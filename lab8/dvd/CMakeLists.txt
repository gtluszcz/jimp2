
project(dvd)

set(HEDEAR_FILES DVD.h Exceptions/Exception.h Exceptions/NoFileException.h Exceptions/InvalidSequenceException.h)
set(SOURCE_FILES DVD.cpp Exceptions/Exception.cpp Exceptions/NoFileException.cpp Exceptions/InvalidSequenceException.cpp)

add_library(libdvd STATIC ${SOURCE_FILES})
target_include_directories(libdvd PUBLIC .)

add_executable(dvd ${SOURCE_FILES} main.cpp)

target_link_libraries(dvd libdvd)

