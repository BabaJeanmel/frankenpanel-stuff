#include <Keypad.h>
#include <Keyboard.h>

char previousPressedKey;
boolean hasReleasedKey = false;

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys1[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'+','0','*'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad1 = Keypad( makeKeymap(keys1), rowPins, colPins, ROWS, COLS );

const byte ROWS2 = 4; //four rows
const byte COLS2 = 3; //three columns
char keys2[ROWS2][COLS2] = {
  {'r','t','y'},
  {'f','g','h'},
  {'v','b','n'},
  {'m','u','j'}
};
byte rowPins2[ROWS2] = {12, 11, 10, 9}; //connect to the row pinouts of the keypad
byte colPins2[COLS2] = {A2, A1, A0}; //connect to the column pinouts of the keypad

Keypad keypad2 = Keypad( makeKeymap(keys2), rowPins2, colPins2, ROWS2, COLS2 );

//update instances and possibly fire funcitons

void setup(){
  Serial.begin(9600);
  delay(1000);
}

void loop(){
delay(50);
keypadLoop1();
keypadLoop2();
}

void keypadLoop1() {
  char key1 = keypad1.getKey();
  KeyState state1 = keypad1.getState();

  if (state1 == PRESSED && key1 != NO_KEY) {
  previousPressedKey = key1;
  hasReleasedKey = false;
  Keyboard.print(key1);
}

else if (state1 == RELEASED && !hasReleasedKey) {
// Multiple RELEASED events occur when there had not been HOLD
 Keyboard.print(key1);
 hasReleasedKey = true;

}
else if (state1 == HOLD) {
Keyboard.print(key1);
Keyboard.println(previousPressedKey);

}
}

void keypadLoop2() {
  char key2 = keypad2.getKey();
  KeyState state2 = keypad2.getState();

  if (state2 == PRESSED && key2 != NO_KEY) {
  previousPressedKey = key2;
  hasReleasedKey = false;
  Keyboard.print(key2);
}

else if (state2 == RELEASED && !hasReleasedKey) {
// Multiple RELEASED events occur when there had not been HOLD
 Keyboard.print(key2);
 hasReleasedKey = true;

}
else if (state2 == HOLD) {
Keyboard.print(key2);
Keyboard.println(previousPressedKey);

}
}
