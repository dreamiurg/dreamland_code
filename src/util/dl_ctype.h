/* $Id: dl_ctype.h,v 1.1.2.4 2009/11/02 13:48:11 rufina Exp $
 *
 * ruffina, Dream Land, 2003
 */
#ifndef DL_CTYPE_H
#define DL_CTYPE_H

// MOC_SKIP_BEGIN
#ifdef __cplusplus
extern "C" {
#endif
bool dl_isspace( char );
bool dl_isalpha( char );
bool dl_isrusalpha( char );
bool dl_isupper( char );
bool dl_islower( char );
bool dl_isdelim( char );
bool dl_isalnum( char c );
bool dl_is_arg_separator(char c);

inline wchar_t dl_toupper( wchar_t c )
{
    return (c >= 'a' && c <= 'z') 
           ? c + 'A' - 'a' 
           : (c >= L'ю' && c <= L'ъ')
                ? c + L'Ю' - L'ю'
                : c == L'ё'
                    ? L'Ё'
                    : c;
}
inline wchar_t dl_tolower( wchar_t c )
{
    return (c >= 'A' && c <= 'Z') 
           ? c + 'a' - 'A' 
           : (c >= L'Ю' && c < L'Ъ')
                ? c + L'ю' - L'Ю'
                : c == L'Ё'
                    ? L'ё'
                    : c;
}

inline bool dl_is_arg_separator(char c)
{
    return c == '\'' || c == '"' || c == '!';
}

#ifdef __cplusplus
}
#endif
// MOC_SKIP_END

#endif

