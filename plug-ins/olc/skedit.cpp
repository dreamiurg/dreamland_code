
#include <character.h>
#include <pcharacter.h>
#include <commandmanager.h>
#include <object.h>
#include <affect.h>
#include "room.h"
#include "regexp.h"
#include "skillhelp.h"

#include "skedit.h"
#include "hedit.h"
#include "olc.h"
#include "security.h"

#include "religionflags.h"
#include "merc.h"
#include "update_areas.h"
#include "websocketrpc.h"
#include "arg_utils.h"
#include "interp.h"
#include "act.h"
#include "mercdb.h"
#include "def.h"

OLC_STATE(OLCStateSkill);

OLCStateSkill::OLCStateSkill() : isChanged(false)
{
}

OLCStateSkill::OLCStateSkill(Skill *skill) 
    : isChanged(false)
{
    if (!original)
        return;

    original = skill->getIndex();
}

OLCStateSkill::~OLCStateSkill() 
{
}

void OLCStateSkill::commit() 
{
    if (!isChanged)
        return;

    BasicSkill *original = getOriginal();
    if (!original)
        return;
    
    original->save();
    if (owner)
        owner->character->println("Изменения сохранены на диск.");
}

BasicSkill * OLCStateSkill::getOriginal()
{
    Skill *skill = skillManager->find(original->getIndex());
    if (!skill)
        throw Exception("Attached skill doesn't exist");

    BasicSkill *basicSkill = dynamic_cast<BasicSkill *>(skill);
    if (!basicSkill)
        throw Exception("Attached skill was unloaded");
    
    return basicSkill;
}

void OLCStateSkill::statePrompt(Descriptor *d) 
{
    d->send( "Skill> " );
}

void OLCStateSkill::changed( PCharacter *ch )
{
    isChanged = true;
}

void OLCStateSkill::show( PCharacter *ch )
{
    BasicSkill *r = getOriginal();

    ptc(ch, "Умение {C%s{x, {C%s{x\r\n", r->getName().c_str(), r->getRussianName().c_str());
    ptc(ch, "Задержка:   {C%d{w пульсов {D(beats){x\r\n", r->getBeats());
    if (r->help)
        ptc(ch, "Справка: %s {D(help или hedit %d){x\r\n",
            web_edit_button(ch, "hedit", r->help->getID()).c_str(),
            r->help->getID());
    else
        ptc(ch, "Справка: нет {D(help create){x\r\n");

    ptc(ch, "{WКоманды{x: commands, show, done, ?\r\n");        
}

SKEDIT(show, "показать", "показать все поля")
{
    show(ch);
    return false;
}

SKEDIT(help, "справка", "создать или посмотреть справку по умению")
{
    DLString arg = argument;
    BasicSkill *r = getOriginal();

    if (arg.empty()) {
        if (!r->help || r->help->getID() < 1) {
            ptc(ch, "Справка не задана, используй help create для создания новой.");
            return false;
        }

        OLCStateHelp::Pointer hedit(NEW, r->help.getPointer());
        hedit->attach(ch);
        hedit->show(ch);
        return true;
    }

    if (arg_oneof(arg, "create", "создать")) {
        if (r->help && r->help->getID() > 0) {
            ptc(ch, "Справка уже существует, используй команду help для редактирования.");
            return false;
        }

        if (!r->help)
            r->help.construct();
        r->help->setID(
            helpManager->getLastID() + 1
        );
        r->help->setSkill(BasicSkill::Pointer(r));

        OLCStateHelp::Pointer hedit(NEW, r->help.getPointer());
        hedit->attach(ch);
        hedit->show(ch);
        return true;
    }   

    ptc(ch, "Использование: help, help create\r\n");
    return false;
}

SKEDIT(beats, "задержка", "wait state в пульсах (секунды * 4)")
{
    BasicSkill *r = getOriginal();
    return numberEdit(0, 60, r->beats);
}

SKEDIT(commands, "команды", "показать список встроенных команд")
{
    do_commands(ch);
    return false;
}

SKEDIT(done, "готово", "выйти из редактора") 
{
    commit();
    detach(ch);
    return false;
}


CMD(skedit, 50, "", POS_DEAD, 103, LOG_ALWAYS, "Online skill editor.")
{
    DLString args = argument;
    DLString cmd = args.getOneArgument();

    if (cmd.empty()) {
        stc("Формат:  skedit умение\r\n", ch);
        return;
    }

    DLString arg = DLString(argument).toLower().stripWhiteSpace();    

    Skill *skill = skillManager->findExisting(arg);
    if (!skill)
        skill = skillManager->findUnstrict(arg);
        
    if (!skill || dynamic_cast<BasicSkill *>(skill) == NULL) {
        stc("Умение с таким названием не найдено.\r\n", ch);
        return;
    }

    OLCStateSkill::Pointer ske(NEW, skill);
    ske->attach(ch);
    ske->show(ch);
}

