#include <Keypad.h>
#include <Keyboard.h>

char previousPressedKey;
boolean hasReleasedKey = false;

const byte ROWS1 = 4;  //four rows
const byte COLS1 = 3;  //three columns
char keys1[ROWS1][COLS1] = {
  { '\341', '\342', '\343' },
  { '\344', '\345', '\346' },
  { '\347', '\350', '\351' },
  { '\335', '\353', '\336' }
};
byte rowPins1[ROWS1] = { 8, 7, 6, 5 };  //connect to the row pinouts of the keypad
byte colPins1[COLS1] = { 4, 3, 2 };     //connect to the column pinouts of the keypad

Keypad keypad1 = Keypad(makeKeymap(keys1), rowPins1, colPins1, ROWS1, COLS1);

char
    keyPressed1,
    lastKey1;

const byte ROWS2 = 4;  //four rows
const byte COLS2 = 3;  //three columns
char keys2[ROWS2][COLS2] = {
  { 'r', 't', 'y' },
  { 'f', 'g', 'h' },
  { 'v', 'b', 'n' },
  { 'm', 'u', 'j' }
};
byte rowPins2[ROWS2] = { A1, A0, 13, 12 };  //connect to the row pinouts of the keypad
byte colPins2[COLS2] = { 11, 10, 9 };       //connect to the column pinouts of the keypad

Keypad keypad2 = Keypad(makeKeymap(keys2), rowPins2, colPins2, ROWS2, COLS2);

char
    keyPressed2,
    lastKey2;

//update instances and possibly fire funcitons

char holdKey;
unsigned long t_hold;

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  keypad1.setHoldTime( 200 );
  keypad2.setHoldTime( 200 );
  lastKey1 = keypad1.getKey();  
  lastKey2 = keypad2.getKey();  
  delay(1000);
}

void loop() {
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
    Keyboard.press(key1);
    delay(100);
    Keyboard.release(key1);
  }

  else if (state1 == RELEASED && !hasReleasedKey) {
    // Multiple RELEASED events occur when there had not been HOLD
    Keyboard.press(key1);
    hasReleasedKey = true;
  }


//  else if (state1 == HOLD) {
//    Keyboard.print(key1);
//    Keyboard.print(previousPressedKey);
//  }

}

void keypadLoop2() {
  char key2 = keypad2.getKey();
  KeyState state2 = keypad2.getState();

  if (state2 == PRESSED && key2 != NO_KEY) {
    previousPressedKey = key2;
    hasReleasedKey = false;
    Keyboard.press(key2);
    delay(100);
    Keyboard.release(key2);
  }

  else if (state2 == RELEASED && !hasReleasedKey) {
    // Multiple RELEASED events occur when there had not been HOLD
    Keyboard.press(key2);
    hasReleasedKey = true;
  }

//  else if (state2 == HOLD) {
//    Keyboard.print(key2);
//    Keyboard.print(previousPressedKey);
//  }
}