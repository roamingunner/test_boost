
add_executable(chat_client chat_client.cpp)
add_executable(chat_server chat_server.cpp)
target_link_libraries(chat_server pthread)
target_link_libraries(chat_client pthread)