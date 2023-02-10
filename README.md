# frankenpanel-stuff
Tools for my homemade arcade frankepanel. May be of use for others, who knows.

CONTENTS

KEYPAD STUFF ("dual keypads" and "dual keypads_hid")

These Arduino sketches allow to use dual 4x3 kepads for second-generation console gaming (and also Atari Jaguar).

First Keypad is wired to ports 2 to 8, second one from port 9 to port A1.

If using an Arduino Uno, you must use the included python script ("keypad-to-keystroke.py" - run as admin) to turn the serial output to a keyboard hid output. However, there are some severe limitations : only one key can be pressed at the time, holding a key isn't supported, and there is some delay before you can push another key. It's still useful for menu/function uses, but not for games heavily relying on keypads such as Intellivision Dungeons & Dragons, or Atari 5200 Star Raiders.

The Arduino Leonardo don't have these limitations, and fully enables two-player second generation gaming without hiccups.

The bindings are those used by openmsx. They're easily editable if you need to.
