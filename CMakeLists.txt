cmake_minimum_required(VERSION 3.0)

project(Core)

add_executable(Core
    main.cpp
    BloodResourceFactory.cpp
    BloodService.cpp
    BloodServiceSettingsFactory.cpp)

target_link_libraries(Core restbed)

target_include_directories(Core PUBLIC ${CMAKE_SOURCE_DIR}/include)

set_property(TARGET Core PROPERTY CXX_STANDARD 17)