
project(tree)

set(HEDEAR_FILES Tree.h Node.h)
set(SOURCE_FILES Tree.cpp Node.cpp)

add_library(libtree STATIC ${SOURCE_FILES})
target_include_directories(libtree PUBLIC .)

add_executable(tree ${SOURCE_FILES} main.cpp)

target_link_libraries(tree libtree)
