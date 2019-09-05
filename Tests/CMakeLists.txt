add_executable(BasicTest BasicTest.cpp)

target_include_directories(BasicTest PUBLIC ${PROJECT_SOURCE_DIR})

add_test(NAME AliceBasic COMMAND BasicTest)