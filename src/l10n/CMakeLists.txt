add_library(l10n
    flexer.cpp
    grammar_entities.cpp
    noun.cpp
    nounholder.cpp
    pronouns.cpp
    ru_prepositions.cpp
    ru_pronouns.cpp
    russianstring.cpp
    verb.cpp
    xmlrussianstring.cpp    
)

target_compile_options(l10n PUBLIC 
    -Wno-multichar
)

target_include_directories(l10n PUBLIC
    ../../../objs
    ../
    ../xml
    ../lang
    ../util
)

target_link_libraries(l10n
  lang
)
