cmake_minimum_required( VERSION 3.8.2 FATAL_ERROR )

# Name the project
project( polyfit )

# Set up compiler flags
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -march=native" )

# Find and include Eigen headers
find_package( Eigen3 REQUIRED NO_MODULE )

# Add source code to the manifest
set( sources normal-distribution-generator.cpp experiment.cpp sine-wave-experiment.cpp model.cpp polyfit-model.cpp main.cpp )

# Build executable
add_executable( polyfit ${sources} )
target_link_libraries( polyfit Eigen3::Eigen )

# Place executable at top level directory
set_target_properties( polyfit PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR} )

