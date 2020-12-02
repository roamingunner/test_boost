set(Boost_USE_STATIC_LIBS        ON)
find_package(Boost REQUIRED COMPONENTS program_options)
add_executable(options_description options_description.cpp)
target_link_libraries(options_description Boost::program_options)