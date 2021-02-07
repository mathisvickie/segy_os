@echo off
erase segy_os.com
nasm.exe -o segy_os.com segy_os.asm
segy_os.com
exit

