# ATARI ST MOUSE

This project is a script to convert an Atari ST to a USB HID (Human Input Device) using an Arduino Leonardo or similar.

## How to Use

Load the .ino file to the Arduino using the Arduino IDE. You will need to build a custom board with the Arduino attached. You can amend pins used for each action by editing the .ino file to suit your needs. This script has been created with the Atari ST mouse in mind but will work with other computers that have mice that use the DB9 connector. 

## Notes

To adjust the speed of the mouse to suit your needs simply adjust the value for `mouseSpeed` (set at 10.0 by default). i have found this default value works well for the standard Atari ST mouse but is too fast when used with a third party Atari/Amiga replacement mouse. 

## Future developments

- Allow the script to have speed controlled by a potentiometer or slide switch for hardware control.
- Include an Atari/Amiga switch that would handle the different wiring for the mouse of these systems AND make any speed adjustment calibrations.
