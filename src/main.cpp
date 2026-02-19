#include <Arduino.h>
#define FSR_PIN A0
int value = 0;
void setup() {
    Serial.begin(9600);
    pinMode(FSR_PIN, INPUT);
}
void loop() {
    value = analogRead(FSR_PIN);
    Serial.println(value);
}