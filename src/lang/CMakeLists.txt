set(TARGET_NAME lang)

add_library(${TARGET_NAME}
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

target_include_directories(${TARGET_NAME} PUBLIC
        ${CMAKE_BINARY_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src/lang
        ${CMAKE_SOURCE_DIR}/src/l10n
        ${CMAKE_SOURCE_DIR}/src/util
        )
