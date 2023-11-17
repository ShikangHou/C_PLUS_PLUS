project(mutex)

find_package(Threads REQUIRED)
add_executable(mutexTest src/main.cpp)
target_link_libraries(mutexTest Threads::Threads)