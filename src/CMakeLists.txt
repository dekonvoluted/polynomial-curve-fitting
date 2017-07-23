cmake_minimum_required( VERSION 3.8.2 FATAL_ERROR )

# Name the project
project( polyfit )

# Add source code to the manifest
set( sources normal-distribution-generator.cpp experiment.cpp sine-wave-experiment.cpp main.cpp )

# Build executable
add_executable( polyfit ${sources} )

# Place executable at top level directory
set_target_properties( polyfit PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR} )

