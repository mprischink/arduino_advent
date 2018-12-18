int RGB_ROT = 11;
int RGB_GRUEN = 10;
int RGB_BLAU = 9;

int LEDS[] = {12,8,7, RGB_ROT, RGB_GRUEN, RGB_BLAU};

int TASTER = 3;
int POT = A5;

bool button_down = false;
int pause = 500;

void setup() {
  for(int i=0; i < (sizeof(LEDS) / sizeof(LEDS[0])); i++) {
    pinMode(LEDS[i], OUTPUT);
  }
  pinMode(TASTER, INPUT);
  randomSeed(analogRead(0));
}

void loop() {
    pause = analogRead(POT);

    int inp = digitalRead(TASTER);
    if (inp == HIGH) {
        button_down = true;
    } else if (inp == LOW && button_down) {
        button_down = false;
        roll();
    }

    switch(random(3)) {
        case 0: blink(LEDS[0]); break;
        case 1: blink(LEDS[1]); break;
        case 2: blink(LEDS[2]); break;
    }
}

void blink(int led) {
    digitalWrite(led, HIGH);
    delay(pause);
    digitalWrite(led, LOW);
    delay(pause);
}

void roll() {
    int rand = random(6);
    for (int i = 0; i < pause; i++) {
        rand = random(6);
    }
    switch(rand + 1) {
        case 1 : one(); break;
        case 2 : two(); break;
        case 3 : three(); break;
        case 4 : four(); break;
        case 5 : five(); break;
        case 6 : six(); break;
    }
    delay(2000);
    allOff();
}

void one() {
    dimmLED(RGB_ROT);
    dimmLED(RGB_GRUEN);
    dimmLED(RGB_BLAU);
}

void dimmLED(int led) {
    for(int i=0; i<256; i+=40) {
        analogWrite(led, i);
        delay(50);
    }
}

void two() {
    digitalWrite(LEDS[0], HIGH);
}
void three() {
    two(); one();
}
void four() {
    two();
    digitalWrite(LEDS[1], HIGH);
}
void five() {
    four(); one();
}
void six() {
    four();
    digitalWrite(LEDS[2], HIGH);
}


void allOff() {
  for(int i=0; i < (sizeof(LEDS) / sizeof(LEDS[0])); i++) {
    digitalWrite(LEDS[i], LOW);
  }
}
