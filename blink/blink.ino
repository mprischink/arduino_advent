int LED_ROT = 12;
int LED_GELB = 11;
int LED_GRUEN = 10;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_ROT, OUTPUT);
  pinMode(LED_GELB, OUTPUT);
  pinMode(LED_GRUEN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int time_gelb = 3000;
  int time_gruen = 3000;
  int time_blink = 500;
  int time_rot = 6000;
  int no_blink= 4;

  // rot
  digitalWrite(LED_ROT, HIGH);   
  delay(time_rot - time_gelb);     

  // rot/gelb
  digitalWrite(LED_GELB, HIGH);   
  delay(time_gelb);   
  digitalWrite(LED_ROT, LOW); 
  digitalWrite(LED_GELB, LOW);     

  // gruen
  digitalWrite(LED_GRUEN, HIGH);   
  delay(time_gruen);                      
  digitalWrite(LED_GRUEN, LOW);  

  // blink
  for(int i = 0; i < no_blink; i++) {    
    digitalWrite(LED_GRUEN, HIGH);   
    delay(time_blink);                      
    digitalWrite(LED_GRUEN, LOW);   
    delay(time_blink);            
  }

  // gelb
  digitalWrite(LED_GELB, HIGH);   
  delay(time_gelb);                      
  digitalWrite(LED_GELB, LOW); 
}
