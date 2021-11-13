/* $Id: dl_ctype.cpp,v 1.1.2.3 2009/11/02 13:48:11 rufina Exp $
 *
 * ruffina, Dream Land, 2003
 */
#include <string.h>
#include <ctype.h>

#include "dl_ctype.h"

bool dl_isdelim( char ch )
{
    return (strchr( " ,.!;'\":\t`" , ch ) != NULL);
}

bool dl_isspace( char ch )
{
    switch(ch) {
        case ' ':
//        case '\0':
        case '\t':
        case '\r':
        case '\n':
            return true;

        default:
            return false;
    }
}

bool dl_isrusalpha( wchar_t c )
{
    return (c >= L'Ю' && c < L'Ъ')
           || (c >= L'ю' && c <= L'ъ')
           || c == L'ё'
           || c == L'Ё';
}

bool dl_isalpha( char c )
{
    return isalpha(c) || dl_isrusalpha( c );
}

bool dl_isupper( wchar_t c )
{
    return isupper( c ) 
            || (c >= L'Ю' && c < L'Ъ')
            || c == L'Ё';
}

bool dl_islower( wchar_t c )
{
    return islower( c )
           || (c >= L'ю' && c <= L'ъ')
           || c == L'ё';
}

bool dl_isalnum( wchar_t c )
{
    return dl_isalpha( c ) || isdigit( c );
}


