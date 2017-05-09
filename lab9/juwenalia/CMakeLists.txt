
project(juwenalia)

set(HEDEAR_FILES Student.h Backpack.h products/Product.h products/Water.h products/Vodka.h)
set(SOURCE_FILES Student.cpp Backpack.cpp products/Product.cpp products/Water.cpp products/Vodka.cpp)

add_library(libjuwenalia STATIC ${SOURCE_FILES})
target_include_directories(libjuwenalia PUBLIC .)

add_executable(juwenalia ${SOURCE_FILES} main.cpp)

target_link_libraries(juwenalia libjuwenalia)

