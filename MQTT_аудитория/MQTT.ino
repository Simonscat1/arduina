#define led_pin 7

void setup() {
  Serial.begin(9600);
  while (!Serial){
    
  }
  pinMode(led_pin, OUTPUT);
}

void loop() {
  /*
  digitalWrite(led_pin, HIGH);
  delay(1000);
  Serial.println("LOW");
  digitalWrite(led_pin, LOW);
  delay(1000);
  Serial.println("HIGH");
  */
  while(Serial.available() > 0){
    int message = Serial.readString().toInt();
    switch(message) {
      case 1:
        digitalWrite(led_pin, HIGH);
      break;
      case 2:
        digitalWrite(led_pin, LOW);
      break;
    }
  }
}
