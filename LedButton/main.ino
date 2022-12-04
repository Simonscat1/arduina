#define btn_pin 3
#define led_pin 10
#define check_time 20

long prev = 0;
long prev1 = 0;
bool led_stats = false;
long start = 0;
bool btn_unpress = true;
int power = 0;
bool firstTime = false;

void setup() {
  Serial.begin(9600);
  pinMode(btn_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, led_stats);
}

void loop() {
  int val = digitalRead(btn_pin);
  
  if (val == 1){
    if (millis() - prev > check_time){
      if (millis() - start < 500){
        led_stats = !led_stats;
        if (led_stats){
          analogWrite(led_pin, power);
        }
        else{
          analogWrite(led_pin, 0);
        }

      }
    }
    prev = millis();
  }

  else{
    if (millis() - prev1 > check_time){
      start = millis();
      firstTime = true;
    }
    if (millis() - start > 500 && firstTime){
      if (btn_unpress){
        while (power > 10 && !val){
          val = digitalRead(btn_pin);
          power-=10;
          Serial.println(power);
          analogWrite(led_pin, power);
          delay(100);
        }
      }
      else{
        while (power <= 245 && !val){
          val = digitalRead(btn_pin);
          power+=10;
          Serial.println(power);
          analogWrite(led_pin, power);
          delay(100);
        }
      }
      btn_unpress = !btn_unpress;
      firstTime = false;
      start = millis() - 550;
    }
    prev1 = millis();
  }
}
