add_library(flags
        enumeration.cpp
        flags.cpp
        flagtable.cpp
        flagtableregistry.cpp
        xmlenumeration.cpp
        xmlflags.cpp
        )

target_include_directories(flags PUBLIC
        ${CMAKE_BINARY_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src/alloc
        ${CMAKE_SOURCE_DIR}/src/l10n
        ${CMAKE_SOURCE_DIR}/src/lang
        ${CMAKE_SOURCE_DIR}/src/util
        ${CMAKE_SOURCE_DIR}/src/xml
        )
