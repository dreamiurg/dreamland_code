/* $Id: dlfilestream.h,v 1.1.2.4 2009/10/11 18:35:36 rufina Exp $
 *
 * ruffina, Dream Land, 2007
 */
#ifndef DLFILESTREAM_H
#define DLFILESTREAM_H

#include <iostream>
#include <fstream>
#include <vector>

#include "dlfile.h"
#include "exceptiondbio.h"

class DLFileStream : public DLFile {
public:
    DLFileStream( const DLString &dirname, const DLString &filename = DLString::emptyString, const DLString &fileext = DLString::emptyString );
    DLFileStream( const DLFile &dir, const DLFile &file = emptyFile );
    DLFileStream( const DLFile &dir, const DLString &filename, const DLString &fileext = DLString::emptyString );
    virtual ~DLFileStream( );

    void toStream( std::ostream & ) ;
    void fromString( const DLString & ) ;
    vector<DLString> toVector() ;

protected:
    void openInputStream( ) ;
    void openOutputStream( ) ;

    std::ifstream istr;
    std::ofstream ostr;
};

#endif
