# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(dreamland_test
  l10n/ru_prepositions_test.cc
)

# target_include_directories(dreamland_test PUBLIC
#   ../src
#   ../src/lang
# )

target_link_libraries(dreamland_test
  gtest_main
  l10n
  lang
  util
)

include(GoogleTest)
gtest_discover_tests(dreamland_test)