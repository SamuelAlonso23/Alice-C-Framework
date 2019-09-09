add_executable(Client Client.cpp)
add_executable(Server Server.cpp)

target_include_directories(Client PUBLIC ${PROJECT_SOURCE_DIR})
target_include_directories(Server PUBLIC ${PROJECT_SOURCE_DIR})