/*
Robotic Elbow Cycler
 */
#include <Servo.h> // include Servo Library

Servo jointServo; // Create a servo object

int switchPin = 2; // button on digital pin 2
int potPin = 0; // potentiometer on analog 0
int val;
int count = 0;
int pos = 0;    // variable to store the servo position 
int redPin = 11;
int bluePin = 10;
int greenPin = 6;
int servoAngle;
int cycle = 2;
volatile boolean trigger = LOW; // this is the interrup connected to switchPin

int timer = 500;
int angle;

int torquePin = A1;
int torqueReading;

//button debounce to reduce noise
int reading;
int previous = LOW;
long time = 0;
long debounce = 200;

//Averaging Stuff
const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

void setup(){
  attachInterrupt(0, interupttrigger, LOW); //Interrupt 0 is digital pin 2
  //when the input goes from HIGH to LOW it will trigger our behavior
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  jointServo.attach(9);  // attaches the servo on pin 8 to the servo object

  Serial.begin(9600);  // starts the serial Serial at 9600 bauds
  jointServo.write(0);  // starting position
}

void loop(){

  if(trigger == 1){
   
    runCycler();
  } 
  else{
    rgbLed(0,150,255);
    count = 0;
    manualControl(); 
  }
  delay(10);
}


//AUTOMATIC CONTROL
//1190 is 0deg
//1710 is 90deg
void runCycler(){
  rgbLed(0,255,100); //LED color
  jointServo.writeMicroseconds(1190);
  for(pos=1190; pos<1710; pos+=1){
    jointServo.writeMicroseconds(pos);
    delay(2); 
  }
  jointServo.writeMicroseconds(1710);
  for(pos=1710; pos>=1190; pos-=1){
     jointServo.writeMicroseconds(pos);
     delay(2); 
  }
  
  
  
  count += 1;
//  Serial.print("Count:");
//
Serial.println(count);
  
}



//INTERUPT FUNCTION
void interupttrigger(){
  if(trigger == LOW){
    trigger = HIGH;
  }
  else{
    trigger=LOW;
  } 
}


//MANUAL CONTROL FUNCTION
void manualControl(){
  total= total - readings[index]; // subtract the last reading        
  readings[index] = analogRead(potPin); // read from the sensor:  
  total= total + readings[index];  // add the reading to the total:     
  index = index + 1;  // advance to the next position in the array:                 
  
  if (index >= numReadings) // if we're at the end of the array...              
    index = 0; // ...wrap around to the beginning:                           

  average = total / numReadings; // calculate the average:        
     
  val = map(average, 0, 1023, 800, 2200); // map average to microsecond (pulses) for angle control
  jointServo.writeMicroseconds(val); // write this mapped value to the Servo
  angle = map(val, 800, 2200, -69, 160);
  torqueReading = analogRead(torquePin);
  int voltage = map(torqueReading, 0, 1023, 0, 5);
  int current = voltage/2.2;
//  int torque = current * 402 * 7;
  Serial.print("Torque:");
  Serial.print(voltage);
  Serial.print(", ");
  Serial.print("Rot:");
  Serial.println(val);
  delay(10);        // delay in between reads for stability  
}


//LED COLOR FUNCTION
void rgbLed(int r, int g, int b){
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}





