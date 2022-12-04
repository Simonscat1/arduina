#define led_pin 13

bool led_pos = false;

void setup() {
  pinMode(led_pin, OUTPUT);
  cli();
  EICRA = 0;
  EICRA |= 1 << ISC01;
  EICRA |= 1 << ISC00;
  EIMSK |= (1<<INT0);
  sei();
}

ISR(INT0_vect){ 
  led_pos = !led_pos;
}

void loop() {
  digitalWrite(led_pin, led_pos);
}

