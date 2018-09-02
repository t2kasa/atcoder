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

# abc075 - abc078, abc080
add_subdirectory(abc075)
add_subdirectory(abc076)
add_subdirectory(abc077)
add_subdirectory(abc078)
add_subdirectory(abc080)

# abc079
add_executable(abc079d abc079d.cpp)

# abc088
add_executable(abc088d abc088d.cpp)


# abc099
add_executable(abc099d abc099d.cpp)

add_executable(abc108a abc108a.cpp)
add_executable(abc108b abc108b.cpp)
add_executable(abc108c abc108c.cpp)

add_executable(tpdc_o_string tpdc_o_string.cpp)