/* $Id: dl_ctype.cpp,v 1.1.2.3 2009/11/02 13:48:11 rufina Exp $
 *
 * ruffina, Dream Land, 2003
 */
#include <string.h>
#include <ctype.h>

#include "dl_ctype.h"

char dl_toupper( char c )
{
    return (c >= 'a' && c <= 'z')
           ? c + 'A' - 'a'
           : (c >= 'ю' && c <= 'ъ')
             ? c + 'Ю' - 'ю'
             : c == 'ё'
               ? 'Ё'
               : c;
}

char dl_tolower( char c )
{
    return (c >= 'A' && c <= 'Z')
           ? c + 'a' - 'A'
           : (c >= 'Ю' && c < 'Ъ')
             ? c + 'ю' - 'Ю'
             : c == 'Ё'
               ? 'ё'
               : c;
}

bool dl_is_arg_separator(char c)
{
    return c == '\'' || c == '"' || c == '!';
}

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

bool dl_isrusalpha( char c )
{
    return (c >= 'Ю' && c < 'Ъ') 
           || (c >= 'ю' && c <= 'ъ') 
           || c == 'ё' 
           || c == 'Ё';
}

bool dl_isalpha( char c )
{
    return isalpha(c) || dl_isrusalpha( c );
}

bool dl_isupper( char c )
{
    return isupper( c ) 
            || (c >= 'Ю' && c < 'Ъ') 
            || c == 'Ё';
}

bool dl_islower( char c )
{
    return islower( c )
           || (c >= 'ю' && c <= 'ъ') 
           || c == 'ё';
}

bool dl_isalnum( char c )
{
    return dl_isalpha( c ) || isdigit( c );
}


