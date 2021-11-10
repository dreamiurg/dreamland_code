#include <functional>
#include <set>

#include "ru_prepositions.h"

namespace Grammar {

    typedef struct {
        std::wstring short_form;
        std::wstring long_form;
        std::function<bool(const std::wstring &)> is_use_long_form;
    } RuPrepositionRule;

    const std::wstring RU_CONSONANTS = L"бвгджйзклмнпрстфхцчшщ";

    // FIXME: This should be a map, really
    const std::list<RuPrepositionRule> RU_PREPOSITION_RULES = {
            {L"в", L"во", [](const std::wstring &nextWord) {
                // Предлог "во" употребляется:
                // 1) перед формами слов, начинающимися сочетаниями «в, ф + согласный»: во взоре, во власти, во Франции
                // (но: в Финляндии), во Владимире (но: в Венеции), во всем, во вторник, во фразе;
                if (nextWord.length() >= 2
                    && nextWord.find_first_of(std::wstring(L"вф")) == 0
                    && nextWord.find_first_of(RU_CONSONANTS, 1) == 1) {
                    return true;
                }

                // 2) перед формами предложного падежа слов лев, лёд, лён, лоб, ложь, мох, ров, рожь, рот: во лжи, во рву;
                // 3) перед формой мне: во мне;
                // 5) перед формой что: Во что превратился наш парк?
                const std::set<std::wstring> wl{L"льву", L"льду", L"льну", L"лбу", L"лжи", L"мху", L"рву",
                                                L"ржи", L"рту", L"мне", L"что"};
                if (wl.find(nextWord) != wl.end()) {
                    return true;
                }

                // 4) перед формами слов многие, многое, множество, множественный: во множестве случаев, во многих
                // случаях; во множественном числе;
                if (nextWord.find(L"мног") == 0 || nextWord.find(L"множ") == 0) {
                    return true;
                }

                return false;
            }}
    };

    std::wstring ru_get_correct_preposition_form(const std::wstring &preposition, const std::wstring &nextWord) {
        for (const auto & it : RU_PREPOSITION_RULES) {
            if (it.short_form == preposition) {
                if (it.is_use_long_form(nextWord))
                    return it.long_form;
            }
        }
        return preposition;
    }

}