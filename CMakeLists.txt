cmake_minimum_required(VERSION 3.15)
project(EcoMision LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Lista explicita de archivos fuente.
# Si agregas una clase nueva, agrega su .cpp a esta lista.
set(SOURCES
    main.cpp
    src/EcoMision.cpp
    src/Reserva.cpp
    src/Zona.cpp
    src/Explorador.cpp
    src/ElementoInteractivo.cpp
    src/ElementosInteractivos/AnimalHerido.cpp
    src/ElementosInteractivos/EstacionEnergia.cpp
    src/ElementosInteractivos/PlantaMedicinal.cpp
    src/ElementosInteractivos/PortalDeRuta.cpp
    src/ElementosInteractivos/ResiduoContaminante.cpp
)

add_executable(ecomision ${SOURCES})

# Carpeta donde estan los .h (equivalente a -Iinclude)
target_include_directories(ecomision PRIVATE include)

# Warnings recomendados
if(MSVC)
    target_compile_options(ecomision PRIVATE /W4)
else()
    target_compile_options(ecomision PRIVATE -Wall -Wextra -Wpedantic)
endif()
