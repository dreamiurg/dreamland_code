add_library(lang
    boolean.cpp
    byte.cpp
    char.cpp
    dlobject.cpp
    dlstring.cpp
    exception.cpp
    integer.cpp
    long.cpp
    longlong.cpp
    short.cpp
    stringlist.cpp
    stringset.cpp
)

target_compile_options(lang PUBLIC
    -Wno-multichar
)

target_include_directories(lang PUBLIC
    ../../../objs
    ../
    ../l10n
    ../lang
    ../util
)

target_link_libraries(l10n
  util
)
