char t;
#define LEFT_MOTOR_ENA 8
#define RIGHT_MOTOR_ENB 2
#define LEFT_MOTOR_INA1 9
#define LEFT_MOTOR_INA2 10
#define RIGHT_MOTOR_INB1 3
#define RIGHT_MOTOR_INB2 4



void LEFT_MOTOR_INITIALISE (); 
void RIGHT_MOTOR_INITIALISE ();
void GO_FORWARD ();
void STOP_MOTOR ();
void GO_BACK ();

void setup() {
 
  // Set used pins as output
  ///#############################   Initializarea motoarelor  ####################
  LEFT_MOTOR_INITIALISE ();
  RIGHT_MOTOR_INITIALISE();
  //###############################################################################
Serial1.begin(9600);

 
}
 
void loop() {
if(Serial1.available()){
  t = Serial1.read();
  Serial1.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
 GO_FORWARD (180);
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
GO_BACK (180);
}
else if(t == 'W'){    //turn led on or off)
  digitalWrite(9,HIGH);
}
else if(t == 'w'){
  digitalWrite(9,LOW);
}
else if(t == 'S'){      //STOP (all motors stop)
 STOP_MOTOR ();
}

}
void LEFT_MOTOR_INITIALISE (){                                     //initializare motorul din STANGA

  pinMode(LEFT_MOTOR_ENA, OUTPUT); //pin 8
  pinMode(LEFT_MOTOR_INA1, OUTPUT); //pin 9
  pinMode(LEFT_MOTOR_INA2, OUTPUT); //pin 10
  
}

void RIGHT_MOTOR_INITIALISE (){                                     //initializare motorul din DREAPTA
  pinMode(RIGHT_MOTOR_ENB, OUTPUT); //pin 2
  pinMode(RIGHT_MOTOR_INB1, OUTPUT); //pin 3
  pinMode(RIGHT_MOTOR_INB2, OUTPUT); //pin 4
}

void GO_FORWARD (int speed_motor){
   analogWrite(LEFT_MOTOR_ENA, speed_motor);
   analogWrite(RIGHT_MOTOR_ENB, speed_motor);
  
  
  digitalWrite(LEFT_MOTOR_INA1, LOW);
  digitalWrite(LEFT_MOTOR_INA2, HIGH);
  digitalWrite(RIGHT_MOTOR_INB1, LOW);
  digitalWrite(RIGHT_MOTOR_INB2, HIGH);
  
  }
void STOP_MOTOR () {
 analogWrite(LEFT_MOTOR_ENA, 0);
   analogWrite(RIGHT_MOTOR_ENB, 0);
  
  
  digitalWrite(LEFT_MOTOR_INA1, LOW);
  digitalWrite(LEFT_MOTOR_INA2, LOW);
  digitalWrite(RIGHT_MOTOR_INB1, LOW);
  digitalWrite(RIGHT_MOTOR_INB2, LOW);

}

void GO_BACK (int speed_motor){
   analogWrite(LEFT_MOTOR_ENA, speed_motor);
   analogWrite(RIGHT_MOTOR_ENB, speed_motor);
  
  
  digitalWrite(LEFT_MOTOR_INA1, HIGH);
  digitalWrite(LEFT_MOTOR_INA2, LOW);
  digitalWrite(RIGHT_MOTOR_INB1, HIGH);
  digitalWrite(RIGHT_MOTOR_INB2, LOW);

}
