cmake_minimum_required(VERSION 3.0)
project(toy_kernel C)
enable_language(ASM-ATT)


set(CMAKE_VERBOSE_MAKEFILE ON)

# i set -O2 later. Idk if i can set -g so can I do this here?
# Should it be in flags below?
# set(CMAKE_BUILD_TYPE Debug)

include_directories(include)

# set cross-compiler
set(PREFIX "i686-elf-")
set(CMAKE_C_COMPILER "${PREFIX}gcc")
set(CMAKE_ASM-ATT_COMPILER "${PREFIX}as")
set(CMAKE_LINKER "${PREFIX}ld")

# compilation flags
set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffreestanding -O2")
add_link_options(-nostdlib -lgcc -T "${CMAKE_SOURCE_DIR}/linker.ld")
# otherwise it adds -rdynamic
SET(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS)

# find all .c files in src/
FILE(GLOB C_SRCS "src/*.c")

add_executable("kernel.bin" "${C_SRCS}" src/boot.s)
# blows up with no target
# set_target_properties("kernel.bin" PROPERTIES LINK_DEPENDS "linker.ld")
