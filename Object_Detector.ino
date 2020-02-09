/* Defining Pins*/
int buzzOut = 8; 
int echo = 9; 
int trig = 10;
int greenLED = 7;
int redLED = 6;
float d, t;  // distance in centimeters (dcm), time (t)

void setup() 
{
  Serial.begin(9600); 
  pinMode(buzzOut, OUTPUT);  //pin for buzzer
  pinMode(trig, OUTPUT); //pin for pulses for the ultrasonic sensor
  pinMode(echo, INPUT); //pin for input signal from sensor
  pinMode(greenLED, OUTPUT); // output for green LED
  pinMode(redLED, OUTPUT);  // output for red LED
}

void loop() 
{
    //pulse signal for ultrasonic sensor
  digitalWrite(trig,LOW);
  delay(1); // dealy 1ms
  digitalWrite(trig, HIGH);
  delay(10); //delay 10ms
  digitalWrite(trig, LOW);

  t = pulseIn(echo, HIGH); //reading time from sensor in microseconds
  d = (t*.0343)/2; // calculating distance in cm
  Serial.println(d);  // printing over the serial port
  if (d <= 15) // if distance is less than 15cm
  {
    digitalWrite(buzzOut, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
  }
  else
  {
    digitalWrite(buzzOut,LOW);
    digitalWrite(redLED, LOW); // turning off red LED
    digitalWrite(greenLED, HIGH);
  }
  delay(60); 
}
