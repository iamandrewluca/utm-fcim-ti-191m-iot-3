#include <Arduino.h>

#define SENSOR_1_PIN 4
#define SENSOR_2_PIN 5

#define RIGHT 0x1
#define LEFT  0x0

void setup()
{
    Serial.begin(9600);
    pinMode(SENSOR_1_PIN, INPUT);
    pinMode(SENSOR_2_PIN, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    const int sensor1Input = digitalRead(SENSOR_1_PIN);
    const int sensor2Input = digitalRead(SENSOR_1_PIN);

    if (sensor1Input == HIGH) {
        Serial.println("Laser connected");
    } else {
        Serial.println("Laser not connected");
    }

    digitalWrite(LED_BUILTIN, sensor1Input);
}
