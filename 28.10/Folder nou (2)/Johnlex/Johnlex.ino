/*
 * Author: John Lex
 * Date: 28.10.2020
 * Note: made for Just4Ai team from Autonomous Bootcamp
 * Description of program:
 */
//==============================DEFINE DECLARATION=============================================
#define max_left_angle -16 //verificati in practica range volanului si a potentiometrului
#define max_right_angle 5

#define VOLAN_MOTOR_INB1 3
#define VOLAN_MOTOR_INB2 4
#define VOLAN_MOTOR_ENB 2
//=============================================================================================

String inString = "";    // string to hold input

//==========variabile citirea/decodificarea mesajului serialmonitor=============================
int value = 0;
int sign = 1;
//==============================================================================================

//=========================Variabilile  citirea potentiometru===================================
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to
//===============================================================================================

//=========================Variabilile  de stocare a informatiei=================================
int actual_angle = 0;
int input_angle = 0;
int difference_input_actual_angle = 0;
int direction_volan_motor = 1; // 0 - left ; 1-right;
int speed_volan_motor = 0;
//===============================================================================================

//=========================Definirea prototipurilor functiilor===================================
int read_angle_from_serial_monitor(int k);
int get_actual_position_volan();
void VOLAN_MOTOR_INITIALISE ();    
void VOLAN_GO_LEFT_MOTOR (int speed_motor); 
void VOLAN_GO_RIGHT_MOTOR (int speed_motor);
void VOLAN_STOP();
void get_control_volan_position_and_direction(int input_angle,int actual_angle);
//===============================================================================================




void setup() {

  VOLAN_MOTOR_INITIALISE();
  
  Serial.begin(9600);
  while (!Serial) {
  }
  Serial.println("Give input angle:");
}


void loop() {
  //*********Citirea unghiului dorit al volanului*************\\
 
  input_angle = read_angle_from_serial_monitor(2);                    //citirea input_angle_de_la serial 
  actual_angle = get_actual_position_volan();                         //get actual angle
  get_control_volan_position_and_direction(input_angle,actual_angle); // decizia in ce directie sa rotim motorul si cu cat 
  while (difference_input_actual_angle > 6)
  {
    actual_angle = get_actual_position_volan();
    get_control_volan_position_and_direction(input_angle,actual_angle);
    if (direction_volan_motor == 0) // motorul spre stanga 
    {
        speed_volan_motor = map(difference_input_actual_angle, 0, 40, 0, 255); // viteza e invers proportionala cu diferenta de grade 
        VOLAN_GO_LEFT_MOTOR (255);
    }
    if (direction_volan_motor ==1)  // motorul spre dreapta
    {
      speed_volan_motor = map(difference_input_actual_angle, 0, 40, 0, 255);
      VOLAN_GO_RIGHT_MOTOR (255);
    }
  }
  VOLAN_STOP();
Serial.println(actual_angle);  
Serial.println(input_angle);

}

void get_control_volan_position_and_direction(int input_angle,int actual_angle)
{  
   /*
    * Description of function: 
    */
   if (actual_angle >0)                                           // de la 0 la 40 grade volanul spre dreapta
   {
    if (input_angle > actual_angle)                              // example \~ acual angle is 29 , input angle is 39 we need go forward for 10 angle 
    { direction_volan_motor = 1;                                 //mergi spre dreapta "difference_input_actual_angle" grade
      difference_input_actual_angle = input_angle -actual_angle; 
    }
    if(input_angle < actual_angle)                          // example \~ acual angle is 39 , input angle is 10 we need go back for 20 angle 
    {direction_volan_motor = 0;                                  //mergi spre stanga "difference_input_actual_angle" grade
      difference_input_actual_angle = actual_angle - input_angle;
    }
   }
   ///////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    if (actual_angle < 0)                                             // de la 0 la -40 grade volanul spre stanga
   {
    if (input_angle > actual_angle) 
    {
      direction_volan_motor = 1;                                 //mergi spre dreapta "difference_input_actual_angle" grade
      difference_input_actual_angle = input_angle -actual_angle; 
    }
    if(input_angle < actual_angle) 
    {
          direction_volan_motor = 0;                                   //mergi spre stanga "difference_input_actual_angle" grade
    difference_input_actual_angle = actual_angle - input_angle;
    }

   }
   //if (direction_volan_motor == 0) // volanul la stanga 
   {
    VOLAN_GO_LEFT_MOTOR (45);
   }
}

int read_angle_from_serial_monitor(int k)
{
/*  
 *   Descripiton of function: read input_angle value from serial monitor.
 *   Output variable: int input_angle , angle choosed by user to move volan
 */
if( Serial.available())
  {
    char ch = Serial.read();
    if(ch >= '0' && ch <= '9')            // is this an ascii digit between 0 and 9?
       value = (value * 10) + (ch - '0'); // yes, accumulate the value
    else if( ch == '-')
       sign = -1;
    else                                  // this assumes any char not a digit or minus sign terminates the value
    {
       value = value * sign ;             // set value to the accumulated value
           input_angle = value;
       Serial.println(input_angle);
       value = 0;                         // reset value to 0 ready for the next sequence of digits
       sign = 1;
    }

  }
  if(input_angle> max_right_angle)
  {
    input_angle  = 0;
  }
  if(input_angle< max_left_angle)
  {
    input_angle  = 0;
  }
  
    return input_angle;
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
     outputValue = map(sensorValue, 0, 1023, -40, 40); //transform value from range(0-1023)ADC  to range(-40->40)angle)
     return outputValue;
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

void VOLAN_STOP()
{/*      
   *       DESCRIPTION: try to write your personal description    as in my                         
   *                    example that i gave you 
   *                                   
   */
   analogWrite(VOLAN_MOTOR_ENB, 0);
  
  digitalWrite(VOLAN_MOTOR_INB1, LOW);
  digitalWrite(VOLAN_MOTOR_INB2, LOW);
}
