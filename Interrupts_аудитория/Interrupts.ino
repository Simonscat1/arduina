#define led_pin 13
#define btn_pin 2
bool state = LOW;

void setup() {
  pinMode(btn_pin, INPUT_PULLUP);
  pinMode(led_pin, OUTPUT);
  int_number = digitalPinToInterrupt(btn_pin);
  attachInterrupt(0, _blink, RISING)

}

void loop() {
  digitalWrite(led_pin, state);
  
}

void _blink(){
  state = !state;
}
