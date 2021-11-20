# FIXME: Temporary hacks to get the code compile without making any changes to it - until migration to CMake is complete
file(TOUCH ${CMAKE_BINARY_DIR}/src/config.h)
add_compile_definitions(HAS_BDB HAVE_DIRENT_H CLOSEDIR=closedir)

# FIXME: Suppress annoying warnings until we fix the root cause
add_compile_options(-Wno-multichar)

# Build all libraries
add_subdirectory(alloc)
add_subdirectory(core)
add_subdirectory(flags)
add_subdirectory(io)
add_subdirectory(l10n)
add_subdirectory(lang)
add_subdirectory(util)
add_subdirectory(process)

# Consolidate all include directories
get_target_property(LIB_ALLOC_INCLUDES alloc INCLUDE_DIRECTORIES)
get_target_property(LIB_CORE_INCLUDES core INCLUDE_DIRECTORIES)
get_target_property(LIB_FLAGS_INCLUDES flags INCLUDE_DIRECTORIES)
get_target_property(LIB_IO_INCLUDES io INCLUDE_DIRECTORIES)
get_target_property(LIB_L10N_INCLUDES l10n INCLUDE_DIRECTORIES)
get_target_property(LIB_UTIL_INCLUDES util INCLUDE_DIRECTORIES)
get_target_property(LIB_PROCESS_INCLUDES process INCLUDE_DIRECTORIES)

# Build main executable
add_executable(${PROJECT_NAME}
        main.cpp
        dreamland.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_BINARY_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${LIB_ALLOC_INCLUDES}
        ${LIB_CORE_INCLUDES}
        ${LIB_FLAGS_INCLUDES}
        ${LIB_IO_INCLUDES}
        ${LIB_L10N_INCLUDES}
        ${LIB_PROCESS_INCLUDES}
        ${LIB_UTIL_INCLUDES}
        )

target_link_libraries(${PROJECT_NAME}
        alloc
        core
        core-behavior
        flags
        io
        l10n
        process
        util
        )

