# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.5)

# Define the project name and the languages used (C and C++)
project(main C CXX)

# Set the preference for OpenGL implementation to GLVND (the vendor-neutral dispatch library)
set(OpenGL_GL_PREFERENCE GLVND)

# Add the raylib library from the specified subdirectory
add_subdirectory(libs/raylib)

# Check if the compiler is MSVC (Microsoft Visual C++)
if (MSVC)
	# If using MSVC, disable all warnings for raylib
	target_compile_options(raylib PRIVATE /W0)
else()
	# If using any other compiler, disable all warnings for raylib
	target_compile_options(raylib PRIVATE -w)
endif()

# Collect all source and header files recursively from the src and src/headers directories
file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.h")

# Add headers directory to the include path
include_directories(${CMAKE_SOURCE_DIR}/include)

# Create an executable with the collected source files
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the raylib library to the executable
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Add a custom command to copy the assets folder to the executable directory after building
add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
