# Minimum CMake version
cmake_minimum_required(VERSION 3.16)

# Project name
project(Cyping)

# Where is headers
include_directories(include)

# All sources
set(SOURCES
	src/file_utils.c
	src/main.c
	src/phrase.c
	src/stest.c
	src/array_utils.c
	src/string_utils.c
	src/random.c
	src/input_utils.c
	src/output_utils.c
	src/user_io.c
	src/stest_colors.c
	src/stest_logic.c
	src/stest_statistic.c
)

# Creating executable
add_executable(${PROJECT_NAME} ${SOURCES})

# In case if we will get warnings or C standarts
set_target_properties(${PROJECT_NAME} PROPERTIES
	C_STANDART 11
	C_STANDART_REQUIRED YES
)
