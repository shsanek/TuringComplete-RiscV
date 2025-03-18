# TuringComplete Save Description

[![Видео превью](https://img.youtube.com/vi/nAkqT8UcRKM/maxresdefault.jpg)](https://youtu.be/nAkqT8UcRKM)

This is my save for the game TuringComplete. It features a processor built on the RISC-V architecture with a simplified bus system. Additionally, it includes a slightly modified version of Doom’s code from the repository [https://github.com/smunaut/doom_riscv](https://github.com/smunaut/doom_riscv) adapted to run on this system. The project is intended for entertaining and educational purposes and is not meant to be taken too seriously.

## Special Bus Addresses
*(Based on the most significant byte of the address)*

- **0x60** – Auxiliary devices  
- **0x64** – Debug (currently not used)  
- **0x68** – Reading from the boot file/requesting system information (read-only)

## Other Addresses

- **0x20** – Video adapter  
- **0x40** – Console  
- **0x80** – Virtual ROM  
- **0xA0** – Keyboard character

---

### 0xA0
- **0xA0000000** – Reads one character from the keyboard (returns 0 if there is none)

---

### 0x68
- **0x68000000** – Reads 4 bytes from the boot file  
- **0x68000004** – Returns the size of the boot file  
- **0x68000008** – Returns the available amount of RAM (in bytes)

---

### 0x40
- An 80x24 byte matrix for characters  
  For example, `0x40000001` is the address of the second character.

---

### 0x20 – Video Adapter
- The first 1024 bytes represent a 0bgr palette with 4 bytes per color (the first byte is ignored).  
- This is followed by a byte matrix mapping to the palette, sized 80x60 (by default, it is filled with 0 – so palette 0 can be used at the beginning to quickly set the background).

---

### 0x64 – Debug
- **0x64000008** – Terminates the operation/powers off (write any value)

---

### 0x80 – Virtual ROM
- **0x80****** – Non-volatile memory (functions like RAM but is not cleared on restart; both reading and writing are supported)  
- **0x84****** – Read-only ROM (functions like RAM but is read-only)
