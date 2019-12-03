# MSXeyboard

Codeasm personal handwired keyboard

Currently using a Atmega32U4 with the AVR Catarina bootloader.

To program the controller, i did:
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

##to dump old firmware
```$ avrdude -p m32u4 -P /dev/ttyACM0 -c avr109 -U flash:r:old.hex:i -u
```
