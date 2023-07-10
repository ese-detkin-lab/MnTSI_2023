// Pin assignments
const int LED = 2; 									
const int BUTTON = 7;

bool state;

void setup() {
	pinMode(LED, OUTPUT); 		
	pinMode(BUTTON, INPUT); 	
}

void loop() {
	state = digitalRead(BUTTON); 
  
  if (state == HIGH) {
    digitalWrite(LED, HIGH);
  } else { 
    digitalWrite(LED, LOW);
  }
}

void concise(){
  // A more concise way to write the code in loop is as follows:
  digitalWrite(LED, digitalRead(BUTTON));
}

