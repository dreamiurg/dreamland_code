set(TARGET_NAME coreskills)

add_library(${TARGET_NAME}
        affecthandler.cpp
        skill.cpp
        skillaction.cpp
        skillcommand.cpp
        skilleventhandler.cpp
        skillgroup.cpp
        skillmanager.cpp
        skillreference.cpp
        spell.cpp
        spelltarget.cpp
        )

target_include_directories(${TARGET_NAME} PUBLIC
        ${CMAKE_BINARY_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/alloc
        ${CMAKE_SOURCE_DIR}/src/core
        ${CMAKE_SOURCE_DIR}/src/core/behavior
        ${CMAKE_SOURCE_DIR}/src/core/clan
        ${CMAKE_SOURCE_DIR}/src/core/fenia
        ${CMAKE_SOURCE_DIR}/src/fenia
        ${CMAKE_SOURCE_DIR}/src/flags
        ${CMAKE_SOURCE_DIR}/src/gref
        ${CMAKE_SOURCE_DIR}/src/io
        ${CMAKE_SOURCE_DIR}/src/l10n
        ${CMAKE_SOURCE_DIR}/src/lang
        ${CMAKE_SOURCE_DIR}/src/util
        ${CMAKE_SOURCE_DIR}/src/xml
        )
