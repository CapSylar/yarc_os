import serial
import sys
import os

def main():
    if len(sys.argv) < 7:
        print("usage: python uart_program.py [device] [baudrate] [hex imem address] [imem file] [hex dmem address] [dmem_file]")
        exit()

    device = sys.argv[1]
    baud_rate = sys.argv[2]
    imem_address = int(sys.argv[3], 16)
    imem_file_path = sys.argv[4]
    dmem_address = int(sys.argv[5], 16)
    dmem_file_path = sys.argv[6]

    ser = serial.Serial(device, baud_rate)

    # send imem address
    ser.write(imem_address.to_bytes(length=4, byteorder="little"))
    with open(imem_file_path, "rb") as imem_file:
        
        imem_len_bytes = os.path.getsize(imem_file_path)
        # first send the size in bytes
        ser.write(imem_len_bytes.to_bytes(length=4, byteorder="little"))
        print(f"sending 0x{imem_len_bytes:08x} bytes at address 0x{imem_address:08x}")
        # send imem data
        ser.write(imem_file.read())

    # send dmem address
    ser.write(dmem_address.to_bytes(length=4, byteorder="little"))
    with open(dmem_file_path, "rb") as dmem_file:

        dmem_len_bytes = os.path.getsize(dmem_file_path)
        # first send the size in bytes
        ser.write(dmem_len_bytes.to_bytes(length=4, byteorder="little"))
        print(f"sending 0x{dmem_len_bytes:08x} bytes at address 0x{dmem_address:08x}")
        # send imem data
        ser.write(dmem_file.read())

    ser.close()
if __name__ == "__main__":
    main()