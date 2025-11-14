# frankenpanel-stuff
Tools for my homemade arcade frankepanel. May be of use for others, who knows.

*CONTENTS*

ARDUINO ("dual keypads_hid")

This Arduino sketch allows to use dual 4x3 Fasidel kepads for second-generation console gaming (and also Atari Jaguar).

First Keypad is wired to ports 2 to 8, second one from port 9 to port A1.

The bindings are those used by openmsx. They're easily editable if you need to.

U-HID CONFIG

Has two spinners, a trackball, two sticks, 16 buttons and 4 analog triggers (Blue Tip analog buttons) configured. The Blue Tip analog buttons need a specific wiring, check http://forum.arcadecontrols.com/index.php?topic=167989.0 for explanations and schematics. I personally use 3W 1K5 Ohm resistors before each GND connections. The analog calibration in the u-hid profile is based on these resistor values. 

GREMLIN EX CONFIG

I use the following software :

https://github.com/nefarius/ViGEmBus

https://github.com/nefarius/HidHide

https://github.com/muchimi/JoystickGremlinEx

to map the U-HID along with the 4 ultrastiks to 2 virtual XBox controllers.

My config maps sticks 3 and 4 (both flight sticks) as right stick for both players. The digital sticks from the U-HID are mapped as D-pads. Range of the Blue Tip analog buttons is reduced so they can actually reach max value. Set their sensivity as 1 in MAME for best results.
