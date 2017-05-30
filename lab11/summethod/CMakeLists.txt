
project(summethod)

set(HEDEAR_FILES SumMethod.h)
set(SOURCE_FILES SumMethod.cpp)

add_library(libsummethod STATIC ${SOURCE_FILES})
target_include_directories(libsummethod PUBLIC .)

add_executable(summethod ${SOURCE_FILES} main.cpp)

target_link_libraries(summethod libsummethod)

