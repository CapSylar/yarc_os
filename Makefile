
BUILDFILE :? = 0

all:
	riscv32-unknown-elf-objcopy -O binary -j .text.init -j .tohost -j .text -j .data -j .bss ${BUILDFILE} ${BUILDFILE}.data
	srec_cat ${BUILDFILE}.data -binary -fill 0x00 -within ${BUILDFILE}.data -binary -o ${BUILDFILE}.out -vmem 32 -disable=header -obs=4