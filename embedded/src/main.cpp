#include <Arduino.h>
#include <Barrier.hpp>
#include <WiFiEsp.h>
#include <SoftwareSerial.h>

#define SENSOR_1_PIN 4
#define SENSOR_2_PIN 5

Barrier *barrier = nullptr;

char ssid[] = "@acula/mesh";
char pass[] = "let it be";
int status = WL_IDLE_STATUS;
char server[] = "127.0.0.1:4000";
SoftwareSerial* serial = nullptr;
WiFiEspClient* client = nullptr;
WiFiEspClass* wifi = nullptr;

void setup(void) {
    Serial.begin(9600);

    serial = new SoftwareSerial(0, 1);
    serial->begin(115200);

    WiFiEspClass::init(serial);
    wifi = new WiFiEspClass();

    if (wifi->status() == WL_NO_SHIELD) {
        Serial.println("WiFi shield not present");
        while (true);
    }

    // attempt to connect to WiFi network
    while (status != WL_CONNECTED) {
        Serial.print("Attempting to connect to WPA SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network
        status = wifi->begin(ssid, pass);
    }

    // you're connected now, so print out the data
    Serial.println("You're connected to the network");

    barrier = new Barrier();
    pinMode(SENSOR_1_PIN, INPUT);
    pinMode(SENSOR_2_PIN, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop(void) {
    const int pin1 = digitalRead(SENSOR_1_PIN);
    const int pin2 = digitalRead(SENSOR_2_PIN);
    barrier->setCurrent(pin1, pin2);

    if (client->connect(server, 80)) {
        Serial.println("Connected to server");
        client->print("GET /");
        client->print(barrier->getDirection() == 1 ? "in" : "out");
        client->println(" HTTP/1.1");
        client->println("Host: 127.0.0.1:4000");
        client->println("Connection: close");
        client->println();
        client->stop();
    }
}
