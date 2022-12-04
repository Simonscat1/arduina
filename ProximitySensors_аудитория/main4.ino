# define SENS_PIN A0

float voltage;
float dist;

void Printer(int m, float v, float d) {
Serial.print(m);
Serial.print(" ADC, ");
Serial.print(v); Serial.print(" V, ");
Serial.print(d);
Serial.println(" cm");
}

void setup() {
Serial.begin(9600);
}

void loop() {

float measur = analogRead(SENS_PIN);
voltage = measur * 5 / 1023;

dist = 65 * pow(voltage, -1.10);

Printer(measur, voltage, dist);
delay(200);
}
