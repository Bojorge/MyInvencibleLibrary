cmake_minimum_required(VERSION 3.13)
project(MyInvencibleLibrary)

set(CMAKE_CXX_STANDARD 14)

add_executable(MyInvencibleLibrary main.cpp Imagen.h RAID_5.h Disco.h Paridad.h Archivo.h Redundancia.h Compresion.h)