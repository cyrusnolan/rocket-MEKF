cmake_minimum_required(VERSION 3.0.0)
project(nsim VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/lib/eigen/cmake")
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
 
include_directories("include/")
include_directories("lib/")

add_executable(nsim
    src/main.cpp
    src/gnc/AttitudeController.cpp
    src/gnc/FixedTOF.cpp
    src/gnc/FreeTOF.cpp
    src/gnc/ThrustAllocator.cpp
    src/nsim/GenerateForcesMoments.cpp
    src/nsim/ProcessNoise.cpp
    src/nsim/SaveData.cpp
    src/nsim/simulations/run6DOF.cpp
    src/nsim/simulations/MonteCarlo.cpp
    )

set(ENABLE_OSQP TRUE)
set(ENABLE_ECOS TRUE)
add_subdirectory(lib/Epigraph)

target_link_libraries (nsim Eigen3::Eigen epigraph)
