#define btn_pin 12
#define diget 11
#define check_time 20

int prev = 0;
bool count = true;
bool has_pressed = false;
int haw = 0;
void setup() {
  pinMode(btn_pin, INPUT);
  pinMode(diget, OUTPUT);
  Serial.begin(9600);
}
int sin2(){
  return 255 * (sin(millis()*0.005)*0.5 +0.5); 
}
void let_switch(int i ){
  i = (sqrt(i) - 100);
  if(i <= 0){
    analogWrite(diget, 0);
  }
  if(i >= 255){
    i = 255;
  }
  analogWrite(diget,(i));
}
void loop(){
  int val = digitalRead(btn_pin);
  let_switch(haw);
  if(val == 1){
    haw +=1;
    if(millis() - prev >  check_time){
      Serial.println(sin2());
      if(!has_pressed){
        has_pressed = true;
        haw = 0;
        count = !count;
      }
    }
    prev = millis();
  }else {
    
    has_pressed = false;
  }
    // Serial.println(sin2());
}