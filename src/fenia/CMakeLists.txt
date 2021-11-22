set(TARGET_NAME fenia)

add_library(${TARGET_NAME}
        context.cpp
        codesource.cpp
        codesourceref.cpp
        exp-tree.cpp
        function.cpp
        impl.cpp
        lex.cpp
        nodes.cpp
        object.cpp
        handler.cpp
        parse.y++
        phase.cpp
        ref-tree.cpp
        reference.cpp
        scan.l++
        scope.cpp
        stmt-tree.cpp
        xmlregister.cpp
        exceptions.cpp
        feniastring.cpp
        closure.cpp
        native.cpp
        )

target_include_directories(${TARGET_NAME} PUBLIC
        ${CMAKE_BINARY_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
#        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/alloc
#        ${CMAKE_SOURCE_DIR}/src/core
#        ${CMAKE_SOURCE_DIR}/src/core/behavior
#        ${CMAKE_SOURCE_DIR}/src/core/clan
#        ${CMAKE_SOURCE_DIR}/src/core/fenia
#        ${CMAKE_SOURCE_DIR}/src/fenia
#        ${CMAKE_SOURCE_DIR}/src/flags
#        ${CMAKE_SOURCE_DIR}/src/gref
        ${CMAKE_SOURCE_DIR}/src/io
#        ${CMAKE_SOURCE_DIR}/src/l10n
        ${CMAKE_SOURCE_DIR}/src/lang
        ${CMAKE_SOURCE_DIR}/src/util
        ${CMAKE_SOURCE_DIR}/src/xml
        )
