//F for forward & B for back, 1 -> left to right (number of sensor)

int FtrigPin1 = 22;
int FechoPin1 = 23;
int FtrigPin2 = 24;
int FechoPin2 = 25;
int FtrigPin3 = 26;
int FechoPin3 = 27;
int FtrigPin4 = 28;
int FechoPin4 = 29;
int FtrigPin5 = 30;
int FechoPin5 = 31;


int BtrigPin1 = 32;
int BechoPin1 = 33;
int BtrigPin2 = 34;
int BechoPin2 = 35;
int BtrigPin3 = 36;
int BechoPin3 = 37;
int BtrigPin4 = 38;
int BechoPin4 = 39;


long duration1, duration2, duration3, duration4, duration5, duration6, duration7, duration8, duration9, cm;

void setup() {
 INITIALIZARE_SENZORI ();

  Serial.begin (9600);
}

void loop() {
SENZOR();

}
void INITIALIZARE_SENZORI () {
  pinMode(FtrigPin1, OUTPUT);  // Pin 22
  pinMode(FechoPin1, INPUT);   // Pin 23
  pinMode(FtrigPin2, OUTPUT);  // Pin 24
  pinMode(FechoPin2, INPUT);   // Pin 25
  pinMode(FtrigPin3, OUTPUT);  // Pin 26
  pinMode(FechoPin3, INPUT);   // Pin 27
  pinMode(FtrigPin4, OUTPUT);  // Pin 28
  pinMode(FechoPin4, INPUT);   // Pin 29
  pinMode(FtrigPin5, OUTPUT);  // Pin 30
  pinMode(FechoPin5, INPUT);   // Pin 31
  
  }


void SENZOR() {

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:

                                                                                //Forward sensors
  
  digitalWrite(FtrigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(FtrigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(FtrigPin1, LOW);
  digitalWrite(FtrigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(FtrigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(FtrigPin2, LOW);
  digitalWrite(FtrigPin3, LOW);
  delayMicroseconds(5);
  digitalWrite(FtrigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(FtrigPin3, LOW);
  digitalWrite(FtrigPin4, LOW);
  delayMicroseconds(5);
  digitalWrite(FtrigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(FtrigPin4, LOW);
  digitalWrite(FtrigPin5, LOW);
  delayMicroseconds(5);
  digitalWrite(FtrigPin5, HIGH);
  delayMicroseconds(10);
  digitalWrite(FtrigPin5, LOW);

                                                                               // Back sensors
  digitalWrite(BtrigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(BtrigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(BtrigPin1, LOW);
  digitalWrite(BtrigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(BtrigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(BtrigPin2, LOW);
  digitalWrite(BtrigPin3, LOW);
  delayMicroseconds(5);
  digitalWrite(BtrigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(BtrigPin3, LOW);
  digitalWrite(BtrigPin4, LOW);
  delayMicroseconds(5);
  digitalWrite(BtrigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(BtrigPin4, LOW);

  
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.

  duration1 = pulseIn(FechoPin1, HIGH);
  duration2 = pulseIn(FechoPin2, HIGH);
  duration3 = pulseIn(FechoPin3, HIGH);
  duration4 = pulseIn(FechoPin4, HIGH);
  duration5 = pulseIn(FechoPin5, HIGH);
  
  duration6 = pulseIn(BechoPin1, HIGH);
  duration7 = pulseIn(BechoPin2, HIGH);
  duration8 = pulseIn(BechoPin3, HIGH);
  duration9 = pulseIn(BechoPin4, HIGH);

  // Convert the time into a distance
  //  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  //  Serial.print(cm);
  //  Serial.print("cm");
  //  Serial.println();

  
};
