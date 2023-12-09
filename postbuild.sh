#! /bin/bash

echo "====== sections ======"
riscv32-unknown-elf-readelf --sections build/$1
riscv32-unknown-elf-objdump -M numeric -M no-aliases -d -j .text.init -j .text build/$1 >  build/$1.riscv

# generate 2 memory file, text and data in separate files

riscv32-unknown-elf-objcopy -O binary -j .text.init -j .text build/$1 build/$1.imem
riscv32-unknown-elf-objcopy -O binary -j .data -j .bss build/$1 build/$1.dmem

# convert them from binary to vmem

srec_cat build/$1.imem -binary -fill 0x00 -within build/$1.imem -binary -range-padding 4 -byte-swap 4 -o build/$1.ivmem -vmem 32 -disable=header -obs=4
srec_cat build/$1.dmem -binary -fill 0x00 -within build/$1.dmem -binary -range-padding 4 -byte-swap 4 -o build/$1.dvmem -vmem 32 -disable=header -obs=16
# cleanup
rm build/$1.imem
rm build/$1.dmem