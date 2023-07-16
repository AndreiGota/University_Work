cmake_minimum_required(VERSION 3.24)
project(world_population C)

set(CMAKE_C_STANDARD 11)

add_executable(world_population main.c domain/country.c repository/CountryRepo.c utils/DynamicVector.c controller/Controller.c tests/test.c ui/UI.c)
