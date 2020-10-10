cmake_minimum_required(VERSION 3.2)

project(C++Practice)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Flags
if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++14")
    add_definitions(-D_SCL_SECURE_NO_WARNINGS) # suppress std::copy_n warnings
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fPIC -Wno-format-security -Bsymbolic -Bsymbolic-functions -fsanitize=address")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -Wno-format-security -Bsymbolic -Bsymbolic-functions")

    # release flags
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O3 -fvisibility=hidden -fvisibility-inlines-hidden")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall -O3 -fvisibility=hidden")

    if (UNIX AND NOT APPLE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")
    endif()
endif()

add_subdirectory(CppPrimer)