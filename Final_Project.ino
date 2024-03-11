#include <Wire.h>
#include "Adafruit_MPR121.h"

#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif

Adafruit_MPR121 cap = Adafruit_MPR121();

int RED = 0;
int GREEN = 1;
int BLUE = 2;

int rgb_pins[6][3] = {{49, 51, 53},
  {37, 39, 41},
  {48, 50, 52},
  {36, 38, 40},
  {23, 25, 27},
  {22, 24, 26}
};


int hold_1 = 0;
int hold_2 = 1;
int next_hold = 1;

bool hand_1 = false;
bool hand_2 = false;



uint16_t currtouched = 0;


void setup() {
  Serial.begin(9600);

  while (!Serial) {
    delay(10);
  }

  Serial.println("Start");

  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");

  for (int i = 0; i < 6; i++) {
    for (int j = 0 ; j < 3; j++ ){
      pinMode(rgb_pins[i][j], OUTPUT);
    }
    light_led(i,RED);
  }
  delay(2500);
}

void light_led(int index, int color){
  digitalWrite(rgb_pins[index][RED], RED==color);
  digitalWrite(rgb_pins[index][GREEN], GREEN==color);
  digitalWrite(rgb_pins[index][BLUE], BLUE==color);
} 

bool is_held(uint16_t currtouched, int index){
  return currtouched & (1<<index);  
}

void loop() {
  currtouched = cap.touched();

  // If either of the start holds hasn't been grabbed
  if (hand_1 == false || hand_2 == false){
      if (hand_1){
        light_led(hold_1, GREEN);
      }
      else {
        light_led(hold_1, BLUE);
      }
      if(hand_2){
        light_led(hold_2, GREEN);
      }
      else{
        light_led(hold_2, BLUE);
      }

      if(next_hold != hold_1 && next_hold != hold_2){
        light_led(next_hold, RED);
      }
  }

  if (is_held(currtouched, hold_1)){
     hand_1 = true;  
     light_led(hold_1, GREEN);
  }
  else {hand_1 = false;}
  if (is_held(currtouched, hold_2)){
    hand_2 = true;
    light_led(hold_2, GREEN);
  }
  else {hand_2 = false;}

  if (hand_1 && hand_2){
    // check if we need to pick next hold
    while (next_hold == hold_1 || next_hold == hold_2){
      next_hold = random(6);
    }
    light_led(next_hold, BLUE);
  }

  if (is_held(currtouched, next_hold)){
    light_led(next_hold, GREEN);
    if (is_held(currtouched, hold_1)){
      light_led(hold_2, RED);
      hold_2 = next_hold;
      hand_2 = true;
    }
    else{
      light_led(hold_1, RED);
      hold_1 = next_hold;
      hand_1 = true;
    }
  }

  Serial.print("curr: "); Serial.print(currtouched);
  Serial.print("\tHold_1: ");Serial.print(hold_1);
  Serial.print("\tHold_2: ");Serial.print(hold_2);
  Serial.print("\tHand_1: ");Serial.print(hand_1);
  Serial.print("\tHand_2: ");Serial.print(hand_2);
  Serial.print("\tnext_hold: ");Serial.print(next_hold);
  Serial.println();
  

  

  delay(500);
}
