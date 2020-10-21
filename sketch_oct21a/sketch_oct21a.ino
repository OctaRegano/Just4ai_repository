// The aformention connections
int enA = 8;
int in1 = 9;
int in2 = 10;

void setup() 
  // Set used pins as output
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
    
  // Making sure I don't get my beard tangled 
  // in the motor when I'm hanging over it 
  // plugging it in AKA motor off
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void loop() {
  analogWrite(enA, 50); // set the speed
  
  // turn it on
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  delay(5000);

  analogWrite(enA, 100); // a little bit faster now
  delay(2000);
  analogWrite(enA, 180); // a little bit faster now
  delay(2000);
  analogWrite(enA, 255); // Shout! Hey! Hey! Hey!
  delay(2000);
  analogWrite(enA, 200); // a little bit softer now
  delay(2000);
  analogWrite(enA, 75); // a little bit softer now
  delay(2000);

  // Come on now!
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
  delay(5000);
}

void LEFT_MOTOR_INITIALISE (){                                     //initializare motorul din STANGA

  pinMode(enA, OUTPUT); //pin 8
  pinMode(in1, OUTPUT); //pin 9
  pinMode(in2, OUTPUT); //pin 10
  
}

void RIGHT_MOTOR_INITIALISE (){                                     //initializare motorul din DREAPTA
  pinMode(enA, OUTPUT); //pin 8
  pinMode(in1, OUTPUT); //pin 9
  pinMode(in2, OUTPUT); //pin 10
}

void GO_FORWARD (int speed_motor){
  
  
  }
void STOP () {


}

void GO_BACK (){


}
