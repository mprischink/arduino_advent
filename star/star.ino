int taste1 = 2;
int taste2 = 3;
int LEDS[] = {4, 6, 8, 10, 12, 13, 11, 9, 7, 5};
int z = 50;
int m = 0;

void setup() {
  for(int i=0; i < ledcount(); i++){
    pinMode(LEDS[i], OUTPUT);
  }
    pinMode(taste1, INPUT);
    pinMode(taste2, INPUT);
}

void loop() {
    int inp1 = digitalRead(taste1);
    int inp2 = digitalRead(taste2);
    
    if(inp1 == HIGH) {
        m = 1;
    }
    if(inp2 == HIGH) {
        m = 2;
    }

    if(inp1 == LOW && inp2 == LOW) {
        switch(m){
            case 1: 
                for(int i = 0; i < ledcount(); i++) {
                    on(LEDS[i]); off(LEDS[i]);
                }
                break;
            case 2:
                 on(LEDS[random(ledcount())]);
                off(LEDS[random(ledcount())]);
                break;
            default:
                all(HIGH);
        }
    } else {
        all(LOW);
    }

}

void on(int led) {
    digitalWrite(led, HIGH);
    delay(z);
}
void off(int led) {
    digitalWrite(led, LOW);
    delay(z);
}
void all(int onOff) {
  for(int i = 0; i < ledcount(); i++) {
      digitalWrite(LEDS[i], onOff);
  }
}
int ledcount() {
 return (sizeof(LEDS) / sizeof(LEDS[0]));
}
