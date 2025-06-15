# LCD Interfacing with 8051

This project demonstrates how to interface a 16x2 LCD display (LM016L) with the AT89C51 microcontroller using Keil C and Proteus simulation.

## Format:
- `progam.c`: //c code
- `program_simulation.pdsprj`: Proteus simulation file showing circuit with AT89C51 and LCD.
- `program.png`: Output showing the character on LCD.
  
## Files:
- 'lcd_interface1.c': this code makes char 'A' blink in an 16x2 LCD (initalizing the lcd clears it and it writes char A, this goes on a loop forever)
- 'lcd_interface2.c': this code sends char 'A' in a while loop, which makes DDRAM to automatically increase address in LCD
## Concepts Covered:
- LCD command and data sending routines
- Delay functions in embedded C
- LCD pin connections with Port 2 and control pins on Port 1

✅ Simulated and verified on Proteus.
