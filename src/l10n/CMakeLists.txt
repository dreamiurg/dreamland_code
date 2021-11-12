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
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/xml
        ${CMAKE_CURRENT_SOURCE_DIR}/lang
        ${CMAKE_CURRENT_SOURCE_DIR}/util
        )

target_link_libraries(l10n
        lang
        )
