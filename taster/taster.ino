int LED_ROT = 12;
int LED_GELB = 11;
int LED_GRUEN = 10;
int LED_IN = 3;
int active_led = 12;
bool button_down = false;

// the setup function runs once when you press reset or power the board
void setup() {   
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_ROT, OUTPUT);
  pinMode(LED_GELB, OUTPUT);
  pinMode(LED_GRUEN, OUTPUT);
  pinMode(LED_IN, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  int val = digitalRead(LED_IN);
  if (val == HIGH) {
    Serial.println("button down");
    button_down = true;
  } else if (val == LOW && button_down == true) {
    Serial.println("button pressed");
    button_down = false;
    Serial.println("led off: " + active_led);
    digitalWrite(active_led, LOW);
    active_led++;
    if(active_led > 12){
      active_led = 10;
    }
    Serial.println("led on: " + active_led);
    digitalWrite(active_led, HIGH);
  }
}
