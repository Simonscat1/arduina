#define led_pin 13
#define PIN_PHOTO_SENSOR A2 

void setup() { 
  Serial.begin(9600); 
  pinMode(led_pin, OUTPUT); 
} 
void check_serail(){
  while (Serial.available() > 0){
    char message = Serial.read();
    if(message ==  'u'){
      digitalWrite(led_pin, HIGH);
      Serial.println("Led is On now");
    }else if(message == 'd'){
      digitalWrite(led_pin, LOW);
      Serial.println("Led is OFF now");
    }else if(message == 'o'){
      int val = analogRead(PIN_PHOTO_SENSOR);
      Serial.print(val);
    }
  }
    
}

void loop() { 
  check_serail();

}