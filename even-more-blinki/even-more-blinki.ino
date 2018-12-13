int RGB_ROT = 11;
int RGB_GRUEN = 10;
int RGB_BLAU = 6;

int LEDS[] = {12,9,8,7,5,4,3, RGB_ROT, RGB_GRUEN, RGB_BLAU};

int UP = 0;
int DOWN = 1;
int upDown = UP;

void setup() {
  for(int i=0; i < (sizeof(LEDS) / sizeof(LEDS[0])); i++) {
    pinMode(LEDS[i], OUTPUT);
  }
  randomSeed(analogRead(0));
}

void loop() {
    switch(upDown) {
        case 0: up(); rgb(); break;
        case 1: down();      break;
        default: break;
    }
}

void up() {
    for(int i=0; i<7; i++) {
        onOff(LEDS[i]);
    }
    upDown = DOWN;
}

void down() {
    for(int i=0; i<7; i++) {
        onOff(LEDS[6-i]);
    }
    upDown = UP;
}
void onOff(int led) {
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
}

void rgb() {
    switch(random(3)) {
        case 0: dimmLED(RGB_ROT);   dimmLED(RGB_GRUEN); dimmLED(RGB_BLAU);  break;
        case 1: dimmLED(RGB_GRUEN); dimmLED(RGB_BLAU);  dimmLED(RGB_ROT);   break;
        case 2: dimmLED(RGB_BLAU);  dimmLED(RGB_ROT);   dimmLED(RGB_GRUEN); break;
        default: break;
    }

    delay(100);

    digitalWrite(RGB_ROT,   LOW);
    digitalWrite(RGB_GRUEN, LOW);
    digitalWrite(RGB_BLAU,  LOW);
}

void dimmLED(int led) {
    for(int i=0; i<256; i+=20) {
        analogWrite(led, i);
        delay(50);
    }
}
