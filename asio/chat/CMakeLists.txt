
add_executable(chat_client chat_client.cpp)
add_executable(chat_server chat_server.cpp)
target_link_libraries(chat_server pthread)
target_link_libraries(chat_client pthread)
target_include_directories(chat_client PUBLIC ${PROJECT_SOURCE_DIR}/external/dbg-marco)
target_include_directories(chat_client PUBLIC ${PROJECT_SOURCE_DIR}/external/CLI11)