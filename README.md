# Cobalt

The next-gen OS!

## Compile Code

To compile the C code...
- .elf file (Linux) -
Navigate to the directory of the Bootloader file, and then type the following:

```
./Bootloader
```
- .exe file (Windows) -
Run the executable Bootloader file (NOTE - Can only run on Windows Operating Systems running Windows 7 and newer). You can run it from the Windows GUI, or you can type this: 
```
Bootloader.exe
```
Note: Cobalt build 16 is the only one with the executable file, and colors do not quite work 

## Updating Code

To update the C code, navigate to the root of the Cobalt directory, then run the following command (assuming you have GCC installed):

```
$ gcc -o Bootloader Bin/CBaB/verbose.c Bin/CBaB/services.c Bin/CBaB/bios.c Bin/CBaB/bootloader.c
```
## CBaB
CBaB is the default Bootloader and BIOS made for Cobalt.
Location: ```/Bin/CBaB```
