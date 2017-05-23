
project(meanmethod)

set(HEDEAR_FILES MeanMethod.h)
set(SOURCE_FILES MeanMethod.cpp)

add_library(libmeanmethod STATIC ${SOURCE_FILES})
target_include_directories(libmeanmethod PUBLIC .)

add_executable(meanmethod ${SOURCE_FILES} main.cpp)

target_link_libraries(meanmethod libmeanmethod)

