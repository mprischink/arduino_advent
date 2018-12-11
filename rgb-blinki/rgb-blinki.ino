int RGB_ROT = 6;
int RGB_GRUEN = 5;
int RGB_BLAU = 4;

int LEDS[] = {12,11,10,9,8,7, RGB_ROT, RGB_GRUEN, RGB_BLAU};

int PIN_IN = 3;

boolean button_down = false;
int mode = 3;

void setup() {
  Serial.begin(9600);
  Serial.println(LED_BUILTIN);

  pinMode(LED_BUILTIN, OUTPUT);
  for(int i=0; i < (sizeof(LEDS) / sizeof(LEDS[0])); i++) {
    pinMode(LEDS[i], OUTPUT);
  }
  pinMode(PIN_IN, INPUT);

  randomSeed(analogRead(0));
}


void loop() {
  changeModeByInput();
  switch (mode) {
    case 0: justRandom(); break;
    case 1: justRandomTwo(); break;
    default: all();
  }
}

void changeModeByInput() {
  int val = digitalRead(PIN_IN);
  if (val == HIGH) {
    button_down = true;
  } else if (val == LOW && button_down) {
    button_down = false;
    mode++;
    if (mode > 1) {
      mode = 0;
    }
  }
}

void justRandom() {
  long randNumber = random(6);
  Serial.println(randNumber);
  rgb(true);
  digitalWrite(LEDS[randNumber], HIGH);
  delay(400);
  digitalWrite(LEDS[randNumber], LOW);
  rgb(false);
}

void justRandomTwo() {
  long randNumber1 = random(3);
  long randNumber2 = random(3) + 3;
  rgb(true);
  digitalWrite(LEDS[randNumber1], HIGH);
  digitalWrite(LEDS[randNumber2], HIGH);
  delay(400);
  digitalWrite(LEDS[randNumber1], LOW);
  digitalWrite(LEDS[randNumber2], LOW);
  rgb(false);
}

void all() {
  rgb(true);
  for(int i=0; i < (sizeof(LEDS) / sizeof(LEDS[0])); i++) {
    digitalWrite(LEDS[i], HIGH);
  }
  delay(400);
  for(int i=0; i < (sizeof(LEDS) / sizeof(LEDS[0])); i++) {
    digitalWrite(LEDS[i], LOW);
  }
  rgb(false);
}

void rgb(boolean onOff) {
  if (onOff) {
    digitalWrite(RGB_ROT,   random(2));
    digitalWrite(RGB_GRUEN, random(2));
    digitalWrite(RGB_BLAU,  random(2));
  } else {
    digitalWrite(RGB_ROT,   LOW);
    digitalWrite(RGB_GRUEN, LOW);
    digitalWrite(RGB_BLAU,  LOW);
  }
}
