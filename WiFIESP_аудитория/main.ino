#include "WIFI.h"
#include "server.h"
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  WiFi_init(false);

  server_init();

}

void loop() {
  server.handleClient();

}
