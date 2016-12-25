cmake_minimum_required(VERSION 3.7)
project(Dravity_Duck)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo -v")

set(SOURCE_FILES
    draw.c
    draw.h
    engine.c
    engine.h
    graphic_functions.c
    graphic_functions.h
    intro.c
    intro.h
    key.c
    key.h
    level.c
    level.h
    main.c
    menu.c
    menu.h
    object.c
    object.h
    rand.c
    rand.h
    save.c
    save.h
    text.c
    text.h
    tileset.c
    tileset.h
    time.c
    time.h
    display.c
    display.h)

add_executable(Dravity_Duck ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} glfw3)