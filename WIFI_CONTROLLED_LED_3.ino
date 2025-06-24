#define BLYNK_TEMPLATE_ID "TMPL3CMRATzNL"
#define BLYNK_TEMPLATE_NAME "WIFI CONTROLLED LEDS"
#define BLYNK_AUTH_TOKEN "UPEbin2Jif5WJSC7anvsErLuf0pltz_G"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Replace with your WiFi credentials
char ssid[] = "Dk";
char pass[] = "12345678";

// LED GPIO pins
const int led1 = 2; 
const int led2 = 13; 
const int led3 = 4;


void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Set LED pins as output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // Start Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// Virtual pin functions
BLYNK_WRITE(V1) {
  digitalWrite(led1, param.asInt());
}
BLYNK_WRITE(V2) {
  
  digitalWrite(led2, param.asInt());
}
BLYNK_WRITE(V3) {
  digitalWrite(led3, param.asInt());
}


void loop() {
  Blynk.run();
}
