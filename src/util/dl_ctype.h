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
char dl_toupper( char c );
char dl_tolower( char c );
bool dl_is_arg_separator(char c);

#ifdef __cplusplus
}
#endif
// MOC_SKIP_END

#endif

