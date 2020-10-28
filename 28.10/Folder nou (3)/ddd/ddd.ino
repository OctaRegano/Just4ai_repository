#define VOLAN_MOTOR_INB1 3
#define VOLAN_MOTOR_INB2 4
#define VOLAN_MOTOR_ENB 2
const int analogInPin = A0;
void VOLAN_MOTOR_INITIALISE ();    

void VOLAN_GO_RIGHT_MOTOR ();
void VOLAN_STOP();
int get_actual_position_volan();

int position_angle = 0;



// centru = -6                  21 grade libertate
//maxim dreapta =   5
//mamxim stanga = -16

//  Maxim ADC dreapta = 586
//  Maxim ADC stanga = 328
//  Center ADC = 455




void setup() {

  VOLAN_MOTOR_INITIALISE();

  Serial.begin(9600);

}


void loop() {
VOLAN_GO_RIGHT_MOTOR(255);
position_angle = get_actual_position_volan();
Serial.print("[RIGHT] position_angle ");
Serial.println(position_angle);
delay(800);
VOLAN_GO_LEFT_MOTOR(255);
position_angle = get_actual_position_volan();
Serial.print("[LEFT] position_angle ");
Serial.println(position_angle);
delay(800);

}

void VOLAN_MOTOR_INITIALISE (){
  /*      
   *       DESCRIPTION: try to write your personal description                            
   *                                   
   */
  pinMode(VOLAN_MOTOR_ENB, OUTPUT); //pin 2
  pinMode(VOLAN_MOTOR_INB1, OUTPUT); //pin 3
  pinMode(VOLAN_MOTOR_INB2, OUTPUT); //pin 4
}

void VOLAN_GO_RIGHT_MOTOR (int speed_motor)
{/*      
   *       DESCRIPTION: try to write your personal description    as in my                         
   *                    example that i gave you 
   *                                   
   */
  analogWrite(VOLAN_MOTOR_ENB, speed_motor);
  digitalWrite(VOLAN_MOTOR_INB1, HIGH);
  digitalWrite(VOLAN_MOTOR_INB2, LOW);
}

void VOLAN_GO_LEFT_MOTOR (int speed_motor){
  /*      
   *       DESCRIPTION: try to write your personal description    as in my                         
   *                    example that i gave you 
   *                                   
   */
  analogWrite(VOLAN_MOTOR_ENB, speed_motor);
  digitalWrite(VOLAN_MOTOR_INB1, LOW);
  digitalWrite(VOLAN_MOTOR_INB2, HIGH);
  
  }

   int get_actual_position_volan()
  {
    /*
     * Description of function: Read voltage from potentiometer A0 
     *                          and transform this value into actual angle of volan.
     * Return variable: outputValue
     */
     
     int sensorValue = 0;        // value read from the pot
     int outputValue = 0;        // value output to the PWM (analog out)
     
     sensorValue = analogRead(analogInPin);            // read data from pin A0
     Serial.print("Valoarea ADC ");
     Serial.println(sensorValue);
     outputValue = map(sensorValue, 0, 1023, -40, 40); //transform value from range(0-1023)ADC  to range(-40->40)angle)
     return outputValue;
  }
