#ifndef RU_PREPOSITIONS_H
#define RU_PREPOSITIONS_H

#include <list>
#include "dlstring.h"

namespace Grammar {

    std::wstring ru_get_correct_preposition_form(const std::wstring &preposition, const std::wstring &nextWord);

}

#endif
