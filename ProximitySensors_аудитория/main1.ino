int led = 13 ;
int SensorPin = 2; 
int valueDigital ;
 
void setup ()
{
  pinMode (led, OUTPUT) ;
  pinMode (SensorPin, INPUT) ;  
  Serial.begin(9600);
}
 
void loop ()
{ 
  valueDigital = digitalRead (SensorPin) ;
    if (valueDigital == HIGH)
     { digitalWrite (led, LOW);
     } 
    else 
     { digitalWrite (led, HIGH); 
     } 
  delay(1000); 
}
