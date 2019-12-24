#include <Arduino.h>
#include <Barrier.hpp>

#define SENSOR_1_PIN 4
#define SENSOR_2_PIN 5

void lasers();

Barrier *barrier = nullptr;

void setup(void) {
    Serial.begin(9600);
    barrier = new Barrier();
    pinMode(SENSOR_1_PIN, INPUT);
    pinMode(SENSOR_2_PIN, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop(void) {
    const int pin1 = digitalRead(SENSOR_1_PIN);
    const int pin2 = digitalRead(SENSOR_2_PIN);
    barrier->setCurrent(pin1, pin2);
    Serial.println(barrier->getDirection());
    delay(500);
}
