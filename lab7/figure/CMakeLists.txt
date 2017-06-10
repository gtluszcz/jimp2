project(figure)

set(HEDEAR_FILES Figure.h Circle.h Square.h Triangle.h)
set(SOURCE_FILES Figure.cpp Circle.cpp Square.cpp Triangle.cpp)

add_library(libfigure STATIC ${SOURCE_FILES})
target_include_directories(libfigure PUBLIC .)

add_executable(figure ${SOURCE_FILES} main.cpp)

target_link_libraries(figure libfigure)

