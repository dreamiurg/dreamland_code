set(TARGET_NAME l10n)

add_library(${TARGET_NAME}
        flexer.cpp
        grammar_entities.cpp
        noun.cpp
        nounholder.cpp
        pronouns.cpp
        ru_pronouns.cpp
        russianstring.cpp
        verb.cpp
        xmlrussianstring.cpp
        )

target_include_directories(${TARGET_NAME} PUBLIC
        ${CMAKE_BINARY_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src/xml
        ${CMAKE_SOURCE_DIR}/src/lang
        ${CMAKE_SOURCE_DIR}/src/util
        )
