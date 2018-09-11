cmake_minimum_required(VERSION 3.10)
project(atcoder)

set(CMAKE_CXX_STANDARD 14)

# abc007
add_executable(abc007a abc007a.cpp)
add_executable(abc007b abc007b.cpp)
add_executable(abc007c abc007c.cpp)

# atc001
add_executable(atc001a atc001a.cpp)
add_executable(atc001b atc001b.cpp)

# abc085
add_executable(abc085c abc085c.cpp)

add_subdirectory(abc021)

# arc004
add_executable(arc004a arc004a.cpp)

# arc031
add_executable(arc031b arc031b.cpp)

# arc037
add_executable(arc037b arc037b.cpp)

add_subdirectory(abc045)
add_subdirectory(abc064)
add_subdirectory(abc068)
add_subdirectory(abc069)
add_subdirectory(abc070)
add_subdirectory(abc071)
add_subdirectory(abc072)
add_subdirectory(abc074)
add_subdirectory(abc075)
add_subdirectory(abc076)
add_subdirectory(abc077)
add_subdirectory(abc078)
add_subdirectory(abc079)
add_subdirectory(abc080)

add_executable(abc065d abc065d.cpp)
add_executable(abc066d abc066d.cpp)
add_executable(abc067d abc067d.cpp)
add_executable(abc073a abc073a.cpp)
add_executable(abc073b abc073b.cpp)
add_executable(abc073c abc073c.cpp)
add_executable(abc073d abc073d.cpp)

# abc088
add_executable(abc088d abc088d.cpp)

# abc091
add_executable(abc091d abc091d.cpp)

# abc099
add_executable(abc099d abc099d.cpp)

add_executable(abc108a abc108a.cpp)
add_executable(abc108b abc108b.cpp)
add_executable(abc108c abc108c.cpp)

add_executable(tpdc_o_string tpdc_o_string.cpp)

# abc109
add_subdirectory(abc109)
