cmake_minimum_required(VERSION 3.14)
project(vorgabe C)

set(CMAKE_C_STANDARD 11)

include_directories(simple_ray)

add_executable(vorgabe
        simple_ray/bmp.c
        simple_ray/bmp.h
        simple_ray/ray.c
        simple_ray/ray.h
        simple_ray/ray_default_scene.c
        simple_ray/ray_default_scene.h
        simple_ray/ray_math.c
        simple_ray/ray_math.h
        simple_ray/ray_settings.h
        main.c)
