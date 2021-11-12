add_library(io
        dbio.cpp
        dldirectory.cpp
        dlfile.cpp
        dlfileop.cpp
        dlfilestream.cpp
        exceptiondbio.cpp
        http.cpp
        httpsocket.cpp
        servlet.cpp
        socketmanager.cpp
        txncontext.cpp
        xmlconfigurable.cpp
        xmlfile.cpp
        xmlloader.cpp
        xmltableelement.cpp
        xmltableloader.cpp
        )

target_include_directories(io PUBLIC
        ${CMAKE_BINARY_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src/alloc
        ${CMAKE_SOURCE_DIR}/src/lang
        ${CMAKE_SOURCE_DIR}/src/plugin
        ${CMAKE_SOURCE_DIR}/src/util
        ${CMAKE_SOURCE_DIR}/src/xml
        )
