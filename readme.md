# MSXeyboard

Codeasm personal handwired keyboard

Currently using a Atmega32U4 with the AVR Catarina bootloader.

## To program 
For programming the controller, i typed:
```
$ git clone https://github.com/qmk/qmk_firmware
$ cd qmk_firmware
$ make git-submodule
$ ln -sf ~/Projects/Keyboard/msxeyboard keyboards/msxeyboard 
$ make handwired:msxeyboard
```
Now press the reset button (I soldered a button accros the Reset and GND pins, connect a wire or touch using screwdriver):
And within 8 seconds
```
$ avrdude -p m32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:msxeyboard_default.hex:i -u
```
adapt where nececairy. (like the serial port)

## to dump old firmware
```
$ avrdude -p m32u4 -P /dev/ttyACM0 -c avr109 -U flash:r:old.hex:i -u
```

# wiring diagram
| KB | Arduino | IO* | Notes |
|----|---------|-----|-------|
|R1  |D10      |PB6  |A10    |
|R2  |D8       |PB4  |A8|
|R3  |D6       |PD7  |A7|
|R4  |D12*     |PD6  |4th below|
|R5  |D4       |PD4  |A6|
|C1  |D9       |PB5  |A9|
|C2  |D5       |PC6  | |
|C3  |D13*     |PC7  |2th below from the right|
|C4  |D18      |PF7  |A0|
|C5  |D19      |PF6  |A1|
|C6  |D30*     |PD5  |(was TX led)|
|C7  |D1       |PD3  |TX|
|C8  |D0       |PD2  |RX|
|C9  |D2       |PD1  |SDA|
|C10 |D3       |PD0  |PWM8/SCL|
|C11 |D11*     |PB7  |1th on the left cide (top 1th, counting up walking down)|
|C12 |D14      |PB3  |MISO|
|C13 |D16      |PB2  |MOSI|
|C14 |D15      |PB1  |SCLK|

* not on Pro Micro, soldered to pin or pad
