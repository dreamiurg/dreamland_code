set(TARGET_NAME coreclan)

add_library(${TARGET_NAME}
        clan.cpp
        clanmanager.cpp
        clanreference.cpp
        )

target_include_directories(${TARGET_NAME} PUBLIC
        ${CMAKE_BINARY_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src/alloc
        ${CMAKE_SOURCE_DIR}/src/gref
        ${CMAKE_SOURCE_DIR}/src/lang
        ${CMAKE_SOURCE_DIR}/src/xml
        )
