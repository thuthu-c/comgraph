cmake_minimum_required(VERSION 3.10)
project(Comgraph)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adiciona o diretório rapidxml ao include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/rapidxml)

# Lista de arquivos fonte
add_executable(Comgraph
    main.cpp
    cli_parser.cpp
    api.cpp
    xml_parser.cpp
)
