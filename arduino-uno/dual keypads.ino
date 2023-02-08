#include <Keypad.h>

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 3; //three columns

char keys1[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'=','0','-'}
};

byte pin_rows[ROW_NUM] = {8, 7, 6, 5}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad1 = Keypad( makeKeymap(keys1), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

const byte ROWS2 = 4; //four rows
const byte COLS2 = 3; //three columns
char keys2[ROWS2][COLS2] = {
  {'r','t','y'},
  {'f','g','h'},
  {'v','b','n'},
  {'m','u','j'}
};
byte rowPins2[ROWS2] = {A1, A0, 13, 12}; //connect to the row pinouts of the keypad
byte colPins2[COLS2] = {11, 10, 9}; //connect to the column pinouts of the keypad

Keypad keypad2 = Keypad( makeKeymap(keys2), rowPins2, colPins2, ROWS2, COLS2 );

void setup(){
  Serial.begin(9600);
}

void loop(){
  char key1 = keypad1.getKey();
  char key2 = keypad2.getKey();

 if (key1){
 Serial.println(key1);
 }
  
 if (key2){
 Serial.println(key2);
 }
 
}
