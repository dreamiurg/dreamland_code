add_library(lang
    boolean.cpp
    byte.cpp
    char.cpp
    dlobject.cpp
    dlstring.cpp
    exception.cpp
    integer.cpp
    long.cpp
    longlong.cpp
    short.cpp
    stringlist.cpp
    stringset.cpp
)

target_include_directories(lang PUBLIC
        ${CMAKE_BINARY_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src/lang
        ${CMAKE_SOURCE_DIR}/src/l10n
        ${CMAKE_SOURCE_DIR}/src/util
        )

target_link_libraries(l10n
        lang
        )
