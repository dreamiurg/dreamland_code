add_library(l10n
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

target_include_directories(l10n PUBLIC
        ${CMAKE_BINARY_DIR}/src # FIXME: config.h hack
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src/xml
        ${CMAKE_SOURCE_DIR}/src/lang
        ${CMAKE_SOURCE_DIR}/src/util
        )

target_link_libraries(l10n
        lang
        )
