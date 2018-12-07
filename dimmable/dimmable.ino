int LEDS[] = {11,10,9,6};
int PIN_IN = 3;
int active_led = 12;
bool button_down = false;
unsigned long time_pressed;
int hilo=LOW;
int maxPwm = 255;

// the setup function runs once when you press reset or power the board
void setup() {   
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  
  for(int i=0; i < (sizeof(LEDS) / sizeof(LEDS[0])); i++){
    pinMode(LEDS[i], OUTPUT);
  }
  
  pinMode(PIN_IN, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  int val = digitalRead(PIN_IN);
  if (val == HIGH) {
    Serial.println("button down");
    if(button_down == false){
      time_pressed=millis();
    }else {
      unsigned long now = millis();
      Serial.print("now: ");
      Serial.println(now);
      Serial.print("time_pressed: ");
      Serial.println(time_pressed);
      unsigned long duration = now - time_pressed;
      Serial.print("duration: ");
      Serial.println(duration);
      
      int val = (int)(duration/10)%maxPwm;
      Serial.print("pwm: ");
      Serial.println(val);
      if(duration > 200){      
        for(int i=0; i < (sizeof(LEDS) / sizeof(LEDS[0])); i++){
          analogWrite(LEDS[i],val);
        }
      }
    }
    button_down = true;
  } else if (val == LOW && button_down == true) {
    Serial.println("button pressed");
    button_down = false;

    switchLeds();
  }
}

void switchLeds() {
    if(hilo == LOW){
      hilo = HIGH;
    }else{
      hilo = LOW;
    }
    
    for(int i=0; i < (sizeof(LEDS) / sizeof(LEDS[0])); i++){
      digitalWrite(LEDS[i], hilo);
    }
}

