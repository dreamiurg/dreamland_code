/* $Id$
 *
 * ruffina, 2004
 */
#include "fight_safe.h"
#include "fight_position.h"


#include "wrapperbase.h"
#include "register-impl.h"
#include "lex.h"

#include "dreamland.h"
#include "affect.h"
#include "pcharactermanager.h"
#include "room.h"
#include "skill.h"
#include "pcharacter.h"
#include "merc.h"
#include "mercdb.h"
#include "act.h"
#include "interp.h"
#include "loadsave.h"
#include "clanreference.h"
#include "race.h"
#include "npcharacter.h"
#include "object.h"
#include "wiznet.h"
#include "def.h"
#include "vnum.h"

CLAN(none);
CLAN(flowers);

#define IS_WANTED(victim) \
    (IS_SET(victim->act, PLR_WANTED) || IS_SET(victim->getPC()->PK_flag, PK_THIEF))


bool is_safe(Character *ch, Character *victim)
{
    if (!is_safe_nomessage(ch, victim))
        return false;

    if (ch && victim) {
        oldact("$C1 находится под защитой богов.",ch,0,victim,TO_CHAR);
        oldact("Боги защитили $C4 от $c2.",ch,0,victim,TO_ROOM);

        if (victim->fighting == ch) 
            stop_fighting (victim, false);
    }

    return true;
}

static bool mprog_safe( Character *ch, Character *victim ) 
{
    FENIA_CALL( ch, "Safe", "CC", ch, victim );
    FENIA_NDX_CALL( ch->getNPC( ), "Safe", "CCC", ch, ch, victim );
    FENIA_CALL( victim, "Safe", "CC", ch, victim );
    FENIA_NDX_CALL( victim->getNPC( ), "Safe", "CCC", victim, ch, victim );
    return false;
}        

static bool is_in_pk_range( int cml, int vml, int non_wanted )
{
    if (non_wanted * cml < vml + max( 4, cml / 12 + 2) 
        && cml > vml - max( 4, cml / 12 + 2 ))
        return true;

    if (vml < cml + max( 4, vml / 12 + 2 )
        && vml > cml - max( 4, vml / 12 + 2 ) * non_wanted)
        return true;

    return false;
}

bool is_safe_nomessage(Character *ch, Character *victim )
{
    if (!ch || !victim)
        return true;

    if (!ch->in_room || !victim->in_room)
        return true;
        
    if ( victim->fighting == ch
        || ch == victim )
    {
        return false;
    }

    if (mprog_safe( ch, victim ))
        return true;
    /* мертвi бджоли не гудуть */
    if (victim->isDead( ) || ch->isDead( ))
        return true;

    // Special protected mobs outside of safe rooms.
    if (victim->is_npc() && IS_SET(victim->act, ACT_SAFE))
        return true;

    // recurrent victim pet to master
    if ( victim->is_npc()
        && IS_CHARMED(victim)
        && !victim->master->is_npc() )
    {
        return is_safe_nomessage(ch,victim->master);
    }

    // recurrent for attacker pet master
    if ( ch->is_npc()
        && IS_CHARMED(ch)
        && !ch->master->is_npc() )
    {
        return is_safe_nomessage(ch->master,victim);
    }

    if ( IS_SET( ch->in_room->room_flags, ROOM_SAFE|ROOM_NO_DAMAGE )
        || IS_SET( victim->in_room->room_flags, ROOM_SAFE|ROOM_NO_DAMAGE ) )
    {
        return true;
    }

    /* Ghosts are safe */
    if (IS_GHOST( victim  ) || IS_GHOST( ch ))
    {
        return true;
    }
    
    // unconfirmed players are safe!
    if ( !victim->is_npc()
        && !ch->is_npc()
        && ( !IS_SET( victim->act, PLR_CONFIRMED )
            || !IS_SET( ch->act, PLR_CONFIRMED ) ) )
    {
        return true;
    }

    /* link dead players whose adrenalin is not gushing are safe */
    if (( IS_SLAIN( victim ) || IS_DEATH_TIME( victim ) )
        && !IS_VIOLENT( victim )
        && !IS_SET( victim->act, PLR_WANTED ) )
    {
        return true;
    }

    if (!victim->is_npc()
        && !victim->is_adrenalined()
        && victim->desc == 0
        && !IS_VIOLENT( victim )
        && !IS_SET( victim->act, PLR_WANTED ) ) 
    {
        return true;
    }
    
    if (ch->is_npc( ) || victim->is_npc( ))
        return false;

    if (!dreamland->hasOption( DL_PK ))
        return true;

    if (victim->getModifyLevel( ) < PK_MIN_LEVEL
        || ch->getModifyLevel( ) <  PK_MIN_LEVEL)
    {
        return true;
    }

    if (ch->getClan( ) != clan_none && victim->getClan( ) == clan_none)
        return true;

    if (ch->getClan( ) == clan_flowers || victim->getClan( ) == clan_flowers)
        return true;

    if (!ch->is_immortal( ))
    {
        if (!is_in_pk_range(ch->getModifyLevel(), victim->getModifyLevel(), !IS_WANTED(victim)))
            return true;
    }

    return false;
}

static bool is_safe_rspell( Character *victim )
{
    if (victim->is_immortal( ))
        return true;

    if (victim->is_npc( ))
        return false;

    if (IS_GHOST( victim ) || IS_DEATH_TIME( victim ))
        return true;
    
    if (victim->desc == 0 && !IS_VIOLENT( victim ))
        return true;
    
    if (victim->getModifyLevel( ) < PK_MIN_LEVEL)
        return true;

    return false;
}


bool is_safe_rspell( short level, Character *victim, bool verbose )
{
    bool rc;

    if (is_safe_rspell( victim ))
        rc = true;
    
    else if (!victim->is_npc() && !is_in_pk_range(level, victim->getModifyLevel(), !IS_WANTED(victim)))
        rc = true;

    else if (victim->is_npc() && IS_CHARMED(victim) && !victim->master->is_npc())
        rc = !is_in_pk_range(level, victim->master->getModifyLevel(), !IS_WANTED(victim->master));

    else
        rc = false;

    if (rc && verbose) {
        oldact("Боги защищают тебя от заклинаний в этой местности.", victim, 0, 0, TO_CHAR);
        oldact("Боги защищают $c4 от заклинаний в этой местности.", victim, 0, 0, TO_ROOM);
    }

    return rc;
}

bool is_safe_rspell( Affect *paf, Character *victim, bool verbose )
{
    Character *pafOwner = paf->sources.getOwner();
    // If we don't know the source of this affect, check safety against its level.
    if (!pafOwner)
        return is_safe_rspell(paf->level, victim, verbose);

    // Ensure charmed creatures are safe from master's spells.
    if (IS_CHARMED(victim) && victim->master == pafOwner)
        return true;
        
    bool rc = is_safe_nomessage(pafOwner, victim);
    if (rc && verbose) {
        oldact("Боги защищают тебя от заклинаний в этой местности.", victim, 0, 0, TO_CHAR);
        oldact("Боги защищают $c4 от заклинаний в этой местности.", victim, 0, 0, TO_ROOM);
    }

    return rc;
}
