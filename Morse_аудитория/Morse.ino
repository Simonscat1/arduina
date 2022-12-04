#define DATA_PIN 2
#define LETTER_SEP 3
#define IDLE_TIME 10
#define DATA_LEVEL LOW
long start = 0;
int TU = 1000;

int timings[20];
bool levels[20];
bool check_letter = false;
bool is_idle = false;
int current = 0;
char dots_dash[20];
String ENCODED[] = {".-", "--.."};
String LETTERS[] = {"A", "Z"};
int n_letters = 2;


void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  attachInterrupt(0,process_timing, CHANGE ); // 0 -> digitalPin 2

}

void loop() {
  //TODO words separetions
  //TODO last letter before IDLE processing > 7 TU
  process_idle();
  if(check_letter){
    decode_letter();  
    check_letter = false;
  }
  
}
void decode_letter(){
  if(timings[current-1] >= LETTER_SEP and levels[current-1] == !DATA_LEVEL){
    String letter ="";
    for(int i =0; i<current; i++){
      if(timings[i] == 1 and levels[i] == DATA_LEVEL) {
        letter += '.';
      }else if(timings[i] == 3 and levels[i] == DATA_LEVEL){
        letter += '-';
      }
    }
    current = 0;
    for (int iletter=0; iletter<n_letters; iletter++){
      if(ENCODED[iletter] == letter){
        Serial.println(LETTERS[iletter]);
      }
    }
  }
}

void process_timing(){
  if (not is_idle){
  timings[current] = round((millis()-start + TU) /TU);
  levels[current] = !digitalRead(DATA_PIN);
  current++;
  check_letter = true;
  }
  start = millis();
  is_idle = false;
  
}
void process_idle(){
  if (not is_idle and round((millis()-start) /TU)>= IDLE_TIME){
  timings[current] = 7;
  levels[current] = 1;
  current++;
  start = millis();
  is_idle = true;
  }
}
