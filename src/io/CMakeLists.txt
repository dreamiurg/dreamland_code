set(TARGET_NAME io)

add_library(${TARGET_NAME}
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

target_include_directories(${TARGET_NAME} PUBLIC
        ${CMAKE_BINARY_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src/alloc
        ${CMAKE_SOURCE_DIR}/src/lang
        ${CMAKE_SOURCE_DIR}/src/plugin
        ${CMAKE_SOURCE_DIR}/src/util
        ${CMAKE_SOURCE_DIR}/src/xml
        /opt/homebrew/Cellar/berkeley-db/18.1.40/include # FIXME: This is only going to work on @dreamiurg's computer
        )
