add_subdirectory(Google_tests)
project(project)
include_directories(${project_SOURCE_DIR})
add_executable(app term.cpp polynomial.cpp)