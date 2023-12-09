cmake_minimum_required(VERSION 3.12)
project(yarc_os C ASM)

set (TARGET_NAME yarc)

set(CMAKE_CXX_FLAGS -Wall)
set(SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)

set(sources
    src/crt0.S
    src/main.c
    src/csr.c
    src/traps.c
)

set(LINKER_SCRIPT "link.ld")

add_executable(${TARGET_NAME} ${sources})

set_target_properties(${TARGET_NAME} PROPERTIES
    C_STANDARD 11)

target_include_directories(${TARGET_NAME} PUBLIC ${SRC_DIR}/headers)

target_compile_options(${TARGET_NAME} PRIVATE
                -mstrict-align
                -Og
                -ggdb
                -flto
                )

target_link_options(${TARGET_NAME} PRIVATE
                -nostartfiles -nostdlib
                -T ${SRC_DIR}/${LINKER_SCRIPT})

add_custom_command(TARGET ${TARGET_NAME}
                    POST_BUILD
                    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                    COMMAND sh postbuild.sh ${TARGET_NAME})