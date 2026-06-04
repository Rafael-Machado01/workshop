cmake_minimum_required(VERSION 4.1)
project(oficina)

set(CMAKE_CXX_STANDARD 14)

add_executable(oficina
        snippts/bagunca.cpp
        snippts/busca.cpp
        snippts/clipboard.cpp
        snippts/inclusão.cpp
        snippts/menu.cpp
        snippts/set.cpp
        main.cpp
        snippts/dados_mocado.cpp
        snippts/questoes/one.cpp
        snippts/questoes/two.cpp
        snippts/questoes/three.cpp
        menu.cpp
)
