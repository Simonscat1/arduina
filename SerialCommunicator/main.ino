#include <FastLED.h>

#define sensor_pin A0
#define led_pin 11

const int DATA_PIN = 2;
const unsigned char NUM_LEDS = 15;

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
    pinMode(led_pin, OUTPUT);
}

void set_colors() {
  unsigned char i = 0;
  while (i < NUM_LEDS && Serial.available() >= 3) {
    if (i == 0) delay(100);
    unsigned char r = Serial.read();
    unsigned char g = Serial.read();
    unsigned char b = Serial.read();
    leds[i++] = CRGB(r, g, b);
  }
}

void check_serial(){
  while (Serial.available() > 0) {
    char message = Serial.read();  
    if (message == 'u'){
      digitalWrite(led_pin, HIGH);
      //Serial.println("Led is ON");
    } else if (message == 'd') {
      digitalWrite(led_pin, LOW);
      //Serial.println("Led is OFF");
    } else if (message == 's') {
      char val = analogRead(sensor_pin) >> 2;
      Serial.write(val);
    }
  }
}

void loop() {
  check_serial();
    set_colors();
  FastLED.show();
}
