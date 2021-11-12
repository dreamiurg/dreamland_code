add_library(util
        crypto.cpp
        date.cpp
        dl_ctype.cpp
        dl_match.cpp
        dl_math.cpp
        dl_strings.cpp
        iconvmap.cpp
        lastlogstream.cpp
        logstream.cpp
        parsedate.l++
        profiler.cpp
        regexp.cpp
        timer.cpp
        )

target_include_directories(util PUBLIC
        ${CMAKE_BINARY_DIR}/src # FIXME: config.h hack
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src/l10n
        ${CMAKE_SOURCE_DIR}/src/lang
        ${CMAKE_SOURCE_DIR}/src/regex
        )
