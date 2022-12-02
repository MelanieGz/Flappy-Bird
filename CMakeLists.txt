cmake_minimum_required(VERSION 3.20)

project(FlappyBird)

# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${FlappyBird_SOURCE_DIR}/cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -O0 -g")
# message("${CMAKE_CXX_FLAGS} -std=c++14 -Wall -O0 -g")
# set(SDL2_PATH "D:\\apps\\SDL2\\i686-w64-mingw32")


add_subdirectory(googletest)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

set(SOURCES
  src/main.cpp
  src/window.cpp
  src/bird.cpp
  src/background.cpp
  src/pipe.cpp
)

add_executable(runtests
  test/test.cpp 
  src/window.cpp
  src/bird.cpp
  src/background.cpp
  src/pipe.cpp
)
add_executable(play ${SOURCES})

include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    )
target_link_libraries(play ${SDL2_LIBRARY}
                             ${SDL2_IMAGE_LIBRARIES}
                             )
target_link_libraries(runtests gtest ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})
target_compile_definitions(runtests PRIVATE gtest_disable_pthreads=ON)
