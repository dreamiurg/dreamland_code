set(TARGET_NAME core-behavior)

add_library(${TARGET_NAME}
        areabehavior.cpp
        mobilebehavior.cpp
        objectbehavior.cpp
        roombehavior.cpp
        )

target_include_directories(${TARGET_NAME} PUBLIC
        ${CMAKE_BINARY_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/alloc
        ${CMAKE_SOURCE_DIR}/src/core
        ${CMAKE_SOURCE_DIR}/src/core/clan
        ${CMAKE_SOURCE_DIR}/src/flags
        ${CMAKE_SOURCE_DIR}/src/gref
        ${CMAKE_SOURCE_DIR}/src/l10n
        ${CMAKE_SOURCE_DIR}/src/lang
        ${CMAKE_SOURCE_DIR}/src/util
        ${CMAKE_SOURCE_DIR}/src/xml
        )
