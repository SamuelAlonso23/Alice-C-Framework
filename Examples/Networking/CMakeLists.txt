add_executable(Client Client.cpp)
add_executable(Server Server.cpp)

target_include_directories(Client PRIVATE ${ALICE_INCLUDE_DIR})
target_include_directories(Server PRIVATE ${ALICE_INCLUDE_DIR})