#define pir 2
#define led 12

void setup() {
  Serial.begin(9600);
  pinMode(pir, INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
   int pirVal = digitalRead(pir);
   Serial.println(pirVal);
   if (pirVal == HIGH) {
      digitalWrite(led, HIGH);
//      Serial.println("LED ON");
      delay(2000);
   }

   else {
      digitalWrite(led, LOW);
//      Serial.println("LED LOW");
      delay(2000);
   }

}
