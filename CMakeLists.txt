cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(rgb-hsv-fantastic-converter)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(TARGET_SRC ./src/rgb_hsv_converter.cpp ./src/rgb.cpp ./src/hsv.cpp)
set(TARGET_INC ./inc/rgb_hsv_converter.h ./inc/rgb.h ./inc/hsv.h)
set(TARGET_GTEST ./test/ut_rgb_hsv_converter.cpp)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "Source files" FILES ${TARGET_SRC})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "Header files" FILES ${TARGET_INC})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" PREFIX "Gtest files" FILES ${TARGET_GTEST})

include_directories(./inc)

if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic")
endif()

# Locate GTest
find_package(GTest)
if(GTEST_FOUND)
	include_directories(${GTEST_INCLUDE_DIRS})
	add_executable(runTests ${TARGET_GTEST} ${TARGET_SRC})
	target_link_libraries(runTests GTest::GTest GTest::Main)
endif()

add_library(${PROJECT_NAME} STATIC ${TARGET_SRC} ${TARGET_INC})

add_executable(example ./example.cpp)
target_link_libraries(example ${PROJECT_NAME})
