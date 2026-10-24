# CMakeList.txt : CMake project for MonsterTamingCPP, include source and define
# project specific logic here.
#

cmake_minimum_required (VERSION 3.20)

project (MonsterTamingCPP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source to this project's executable.
add_executable (MonsterTamingCPP "src/main.cpp" "src/Monster.cpp" "src/Move.cpp")

target_include_directories(
    MonsterTamingCPP
    PRIVATE
    include
)

target_compile_features(
    MonsterTamingCPP
    PRIVATE
    cxx_std_20
)
#if (CMAKE_VERSION VERSION_GREATER 3.12)
#  set_property(TARGET MonsterTamingCPP PROPERTY CXX_STANDARD 20)
#endif()

# TODO: Add tests and install targets if needed.
