char t;

#define SW_MOTOR_ENC 5
#define SW_MOTOR_INC1 6
#define SW_MOTOR_INC2 7
#define POT A1
 


int potPin = A1;    

int val = 0;       

void setup() {
  pinMode(potPin, OUTPUT);  
  Serial.begin(9600);  
}

void loop() {
  val = analogRead(potPin);    
  val = map(val,0, 1023, -40, 40);
Serial.println(val);                 // stop the program for some time

                 // stop the program for some time
  
}
