cmake_minimum_required(VERSION 3.12)
project(yarc_os C ASM)

set (RUNT_TARGET runtime)
set (BOOTL_TARGET bootloader)

set(CMAKE_CXX_FLAGS -Wall)
set(SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(PERIPH_DIR ${SRC_DIR}/peripherals)
set(BOOTL_DIR ${SRC_DIR}/bootloader_srcs)
set(RUNT_DIR ${SRC_DIR}/runtime_srcs)

set(COMMON_SRCS
    ${SRC_DIR}/crt0.S
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
    ${SRC_DIR}/graphic_effects.c
)

set (BOOTLOADER_SRCS
    ${COMMON_SRCS}
    ${BOOTL_DIR}/main.c
)

set (RUNTIME_SRCS
    ${COMMON_SRCS}
    ${RUNT_DIR}/main.c
)

set(RUNT_LINKER_SCRIPT "link_runtime.ld")
set(BOOTL_LINKER_SCRIPT "link_bootloader.ld")

add_executable(${BOOTL_TARGET} ${BOOTLOADER_SRCS})
add_executable(${RUNT_TARGET} ${RUNTIME_SRCS})

set_target_properties(${BOOTL_TARGET} PROPERTIES
    C_STANDARD 11)
set_target_properties(${RUNT_TARGET} PROPERTIES
    C_STANDARD 11)

target_include_directories(${BOOTL_TARGET} PUBLIC ${SRC_DIR}/headers ${SRC_DIR}/printf)
target_include_directories(${RUNT_TARGET} PUBLIC ${SRC_DIR}/headers ${SRC_DIR}/printf)

set (COMMON_COMPILE_OPTIONS 
                -mstrict-align
                -Og
                -ggdb
                -flto
                -static-libgcc)

target_compile_options(${BOOTL_TARGET} PRIVATE ${COMMON_COMPILE_OPTIONS})
target_compile_options(${RUNT_TARGET} PRIVATE ${COMMON_COMPILE_OPTIONS})

target_link_options(${BOOTL_TARGET} PRIVATE
                -nostartfiles
                -lgcc
                -T ${SRC_DIR}/${BOOTL_LINKER_SCRIPT})

target_link_options(${RUNT_TARGET} PRIVATE
                -nostartfiles
                -lgcc
                -T ${SRC_DIR}/${RUNT_LINKER_SCRIPT})

add_custom_command(TARGET ${BOOTL_TARGET}
                    POST_BUILD
                    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                    COMMAND sh postbuild.sh ${BOOTL_TARGET})

add_custom_command(TARGET ${RUNT_TARGET}
                    POST_BUILD
                    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                    COMMAND sh postbuild.sh ${RUNT_TARGET})