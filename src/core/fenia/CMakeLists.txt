set(TARGET_NAME corefenia)

add_library(${TARGET_NAME}
        feniamanager.cpp
        guts.cpp
        idcontainer.cpp
        regcontainer.cpp
        reglist.cpp
        schedulerwrapper.cpp
        wrapperbase.cpp
        wrappermanagerbase.cpp
        wrappertarget.cpp
        )

target_include_directories(${TARGET_NAME} PUBLIC
        ${CMAKE_BINARY_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/alloc
        ${CMAKE_SOURCE_DIR}/src/fenia
        ${CMAKE_SOURCE_DIR}/src/flags
        ${CMAKE_SOURCE_DIR}/src/io
        ${CMAKE_SOURCE_DIR}/src/lang
        ${CMAKE_SOURCE_DIR}/src/process
        ${CMAKE_SOURCE_DIR}/src/util
        ${CMAKE_SOURCE_DIR}/src/xml
        )
