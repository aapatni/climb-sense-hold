#include <AverageValue.h>

AverageValue<int> runningAvg(100);

int analogPin = A0;

int val = 0;
int iter = 50;
int del = 1;



void setup() {
  Serial.begin(9600);
}
void loop() {
  int avg = 0;
  for (int i = 0; i < iter; i++) {
    avg += analogRead(analogPin);
    delay(del);
  }
  avg /= iter;

  runningAvg.push(avg);



  Serial.print(avg);
  Serial.print(",");
  Serial.print(runningAvg.average());
  Serial.println();
}
