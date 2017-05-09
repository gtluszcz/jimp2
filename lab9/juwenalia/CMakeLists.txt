
project(juwenalia)

set(HEDEAR_FILES Student.h Backpack.h Store.h products/Product.h products/AlcoholProduct.h products/Water.h products/Vodka.h products/Beer.h products/Wine.h)
set(SOURCE_FILES Student.cpp Backpack.cpp Store.cpp products/Product.cpp products/AlcoholProduct.cpp products/Water.cpp products/Vodka.cpp products/Beer.cpp products/Wine.cpp)

add_library(libjuwenalia STATIC ${SOURCE_FILES})
target_include_directories(libjuwenalia PUBLIC .)

add_executable(juwenalia ${SOURCE_FILES} main.cpp)

target_link_libraries(juwenalia libjuwenalia)

