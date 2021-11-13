set(TARGET_NAME alloc)

add_library(${TARGET_NAME}
        allocateclass.cpp
        class.cpp
        oneallocate.cpp
        exceptionclassnotfound.cpp
        )

target_include_directories(${TARGET_NAME} PUBLIC
        ${CMAKE_BINARY_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src/l10n
        ${CMAKE_SOURCE_DIR}/src/lang
        ${CMAKE_SOURCE_DIR}/src/util
        )
