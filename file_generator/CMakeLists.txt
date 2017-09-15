cmake_minimum_required(VERSION 2.8.4)
project(threadTest)

# ----------------------- LIBRARIES ---------------------------

find_package(Boost COMPONENTS filesystem system REQUIRED)
find_package( OpenCV REQUIRED )
find_library(GMP_LIBRARY gmp /usr/lib)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()


# ----------------------- INCLUDES ----------------------------


file(GLOB SOURCES src/*.cpp)


include_directories(${GMPXX_INCLUDE_DIR}
                    ${OpenCV_INCLUDE_DIRS} 
                    )
include_directories(include/)

# ----------------------- GCC FLAGS ----------------------------

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fpermissive")

# ------------------------ BUILD -------------------------------



add_executable(povrayFileGenerator main/povray_file_generator.cpp ${SOURCES})
target_link_libraries(povrayFileGenerator 
                    ${OpenCV_LIBS}
                    ${OPENCV_BUILD_3RDPARTY_LIBS}
                    ${GMPXX_LIBRARIES}
                    ${GMP_LIBRARIES}
                    ${Boost_LIBRARIES}
                    ${GMP_LIBRARY}
                    )

