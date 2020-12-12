cmake_minimum_required(VERSION 3.18)

project(Core)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

find_package(Threads REQUIRED)

add_executable(Core
    main.cpp
    BloodResourceFactory.cpp
    BloodService.cpp
    BloodServiceSettingsFactory.cpp)

target_link_libraries(Core restbed Threads::Threads)

target_include_directories(Core PUBLIC ${CMAKE_SOURCE_DIR}/include)

set_property(TARGET Core PROPERTY CXX_STANDARD 17)