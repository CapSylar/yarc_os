cmake_minimum_required(VERSION 3.12)
project(yarc_os C ASM)

set (TARGET_NAME yarc)

set(CMAKE_CXX_FLAGS -Wall)
set(SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(PERIPH_DIR ${SRC_DIR}/peripherals)

set(sources
    ${SRC_DIR}/crt0.S
    ${SRC_DIR}/main.c
    ${SRC_DIR}/csr.c
    ${SRC_DIR}/traps.c
    ${SRC_DIR}/peripherals.c
    ${SRC_DIR}/console.c
    ${PERIPH_DIR}/uart.c
    ${SRC_DIR}/printf.c
    ${SRC_DIR}/greeting.c
    ${SRC_DIR}/video.c
    ${SRC_DIR}/uart_loader.c
    ${SRC_DIR}/utils.c
)

set(LINKER_SCRIPT "link.ld")

add_executable(${TARGET_NAME} ${sources})

set_target_properties(${TARGET_NAME} PROPERTIES
    C_STANDARD 11)

target_include_directories(${TARGET_NAME} PUBLIC ${SRC_DIR}/headers ${SRC_DIR}/printf)

target_compile_options(${TARGET_NAME} PRIVATE
                -mstrict-align
                -Og
                -ggdb
                -flto
                -static-libgcc
                )

target_link_options(${TARGET_NAME} PRIVATE
                -nostartfiles
                -lgcc
                -T ${SRC_DIR}/${LINKER_SCRIPT})

add_custom_command(TARGET ${TARGET_NAME}
                    POST_BUILD
                    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                    COMMAND sh postbuild.sh ${TARGET_NAME})