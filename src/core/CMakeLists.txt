add_custom_target(autoflags.h
        DEPENDS ${CMAKE_SOURCE_DIR}/src/bits.conf
        COMMAND ${CMAKE_SOURCE_DIR}/src/makebits.pl -s ${CMAKE_SOURCE_DIR}/src/bits.conf -h -r -f ${CMAKE_BINARY_DIR}/src/autoflags.h
        VERBATIM
)

add_custom_target(autoflags.cpp
        DEPENDS ${CMAKE_SOURCE_DIR}/src/bits.conf ${CMAKE_BINARY_DIR}/src/autoflags.h
        COMMAND ${CMAKE_SOURCE_DIR}/src/makebits.pl -s ${CMAKE_SOURCE_DIR}/src/bits.conf -r -f ${CMAKE_BINARY_DIR}/src/autoflags.cpp && ${CMAKE_SOURCE_DIR}/src/makebits.pl -s ${CMAKE_SOURCE_DIR}/src/bits.conf -h -r -f ${CMAKE_BINARY_DIR}/src/autoflags.h
        VERBATIM
)

add_library(core
        ${CMAKE_BINARY_DIR}/src/autoflags.cpp
        affect.cpp
        affectlist.cpp
        affectmanager.cpp
        bonus.cpp
        character.cpp
        desire.cpp
        dlfileloader.cpp
        dlpluginmanager.cpp
        dlxmlloader.cpp
        eventbus.cpp
        helpmanager.cpp
        hometown.cpp
        liquid.cpp
        mobilespecial.cpp
        npcharacter.cpp
        npcharactermanager.cpp
        object.cpp
        objectmanager.cpp
        pcharacter.cpp
        pcharactermanager.cpp
        pcharactermemory.cpp
        pcharactermemorylist.cpp
        pcrace.cpp
        pcskilldata.cpp
        profession.cpp
        race.cpp
        racelanguage.cpp
        religion.cpp
        remortdata.cpp
        room.cpp
        wearlocation.cpp
        xmlattribute.cpp
        xmlattributes.cpp
        )

add_dependencies(core
        autoflags.h
        autoflags.cpp
        )

target_include_directories(core PUBLIC
        ${CMAKE_BINARY_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/skills
        ${CMAKE_CURRENT_SOURCE_DIR}/clan
        ${CMAKE_CURRENT_SOURCE_DIR}/behavior
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/util
        ${CMAKE_SOURCE_DIR}/src/xml
        ${CMAKE_SOURCE_DIR}/src/alloc
        ${CMAKE_SOURCE_DIR}/src/lang
        ${CMAKE_SOURCE_DIR}/src/flags
        ${CMAKE_SOURCE_DIR}/src/gref
        ${CMAKE_SOURCE_DIR}/src/io
        ${CMAKE_SOURCE_DIR}/src/l10n
        ${CMAKE_SOURCE_DIR}/src/fenia
        )
