#include <Keypad.h>
#include <Keyboard.h>

const byte ROWS1 = 4;
const byte COLS1 = 3;
char keys1[ROWS1][COLS1] = {
  { '\341', '\342', '\343' },
  { '\344', '\345', '\346' },
  { '\347', '\350', '\351' },
  { '\335', '\353', '\336' }
};
byte rowPins1[ROWS1] = { 8, 7, 6, 5 };
byte colPins1[COLS1] = { 4, 3, 2 };

Keypad keypad1 = Keypad(makeKeymap(keys1), rowPins1, colPins1, ROWS1, COLS1);

char
  keyPressed1,
  lastKey1;

const byte ROWS2 = 4;
const byte COLS2 = 3;
char keys2[ROWS2][COLS2] = {
  { 'r', 't', 'y' },
  { 'f', 'g', 'h' },
  { 'v', 'b', 'n' },
  { 'm', 'u', 'j' }
};
byte rowPins2[ROWS2] = { A1, A0, 13, 12 };
byte colPins2[COLS2] = { 11, 10, 9 };

Keypad keypad2 = Keypad(makeKeymap(keys2), rowPins2, colPins2, ROWS2, COLS2);

void setup() {
  Serial.begin(9600);
  keypad1.setHoldTime(200);
}  //setup

void loop() {
  if (keypad1.getKeys()) {
    for (int i = 0; i < LIST_MAX; i++) {
      if (keypad1.key[i].stateChanged) {
        switch (keypad1.key[i].kstate) {
          case PRESSED:
            Keyboard.press(keypad1.key[i].kchar);
            break;
          case HOLD:
            break;
          case RELEASED:
            Keyboard.release(keypad1.key[i].kchar);
            break;
          case IDLE:
            break;
        }
      }
    }
  }
  if (keypad2.getKeys()) {
    for (int i = 0; i < LIST_MAX; i++) {
      if (keypad2.key[i].stateChanged) {
        switch (keypad2.key[i].kstate) {
          case PRESSED:
            Keyboard.press(keypad2.key[i].kchar);
            break;
          case HOLD:
            break;
          case RELEASED:
            Keyboard.release(keypad2.key[i].kchar);
            break;
          case IDLE:
            break;
        }
      }
    }
  }
}
