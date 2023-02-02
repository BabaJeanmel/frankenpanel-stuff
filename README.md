# frankenpanel-stuff
Tools for my homemade arcade frankepanel. May be of use for others, who knows.

CONTENTS

KEYPAD STUFF
My panel includes two numeric keypads to interact with Atari 5200/Colecovision/Intellivision/Odyssey 2/Jaguar games. They're wired to an Arduino Uno. It has some limitations (only 1 key can be pressed at a time, and there's some delay) but as the 2-player games using numeral pads are quite rare, it's not really an issue. I believe it can be improved by using an Arduino Leonardo's specific HID functions, but as I already had an Uno, I wanted to give it a shot.

- Dual keypads.ino : code for connecting two numeral keypads to an Arduino Uno and output the default OpenMSX Colecovision bindings to serial.
- Keypad_to_keystroke.py : code for converting this serial output to keystrokes. Must be launched as admin to work properly.
