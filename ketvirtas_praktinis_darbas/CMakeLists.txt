cmake_minimum_required(VERSION 4.0)
project(ketvirtas_praktinis_darbas)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ketvirtas_praktinis_darbas
        apskaitos_sistema.cpp
        menu.txt
        receipt.txt)
