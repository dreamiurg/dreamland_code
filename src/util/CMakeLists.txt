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

target_compile_options(util PUBLIC 
    -Wno-multichar
)

target_include_directories(util PUBLIC
    ../../../objs
    ../
    ../l10n
    ../lang
    ../regex
)
