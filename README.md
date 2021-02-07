# SegyOS

SegyOS is just a protected mode application rather than standalone operating system because it lacks of many features that OS must have (mm, paging, multithreading...).
The motivation was to make self-sufficient application that runs from DOS/FREE-DOS and creates LFB (linear frame buffer) for beautiful demos made in pure assembly!

## Compiling
Use nasm to compile with:

    nasm -o segy_os.com segy_os.asm

## Running
You can use either VM with DOS or download [Rufus](https://rufus.ie/) and flash FREE-DOS on your portable device, then just run:

    segy_os.com
