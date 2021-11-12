add_library(alloc
        allocateclass.cpp
        class.cpp
        oneallocate.cpp
        exceptionclassnotfound.cpp
        )

target_include_directories(alloc PUBLIC
        ${CMAKE_BINARY_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src/l10n
        ${CMAKE_SOURCE_DIR}/src/lang
        ${CMAKE_SOURCE_DIR}/src/util
        )
