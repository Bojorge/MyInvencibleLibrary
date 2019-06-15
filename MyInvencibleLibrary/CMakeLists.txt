cmake_minimum_required(VERSION 3.13)
project(MyInvencibleLibrary)


set(CMAKE_CXX_STANDARD 14)


add_executable(MyInvencibleLibrary
        main.cpp RAID_5.h
        Disco.h
        Paridad.h
        Archivo.h
        Redundancia.h
        Compresion.h
        Imagen.cpp
        Imagen.h
        Lista.h
        Nodo.h)
