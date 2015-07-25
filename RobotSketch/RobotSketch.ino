/*
 5/22/2012
 Timothy Holmberg
 SparkFun Electronics
 
 7/5/2014
 Sean O'Bryan
 Modified sparkfun example for easy use
 
 Individual functions for motor control 
 
 This was a revision of the example sketch that originated from Pete Dokter's code for Arduino that shows very basically how to control an Ardumoto 
 motor driver shield with a 5V Arduino controller board. http://www.sparkfun.com/datasheets/DevTools/Arduino/Ardumoto_test_3.pde

 */

int pwm_a = 5;   //PWM control for motor outputs 1 and 2 is on digital pin 3
int pwm_b = 6;  //PWM control for motor outputs 3 and 4 is on digital pin 11
int dir_a = 4;  //direction control for motor outputs 1 and 2 is on digital pin 12
int dir_b = 7;  //direction control for motor outputs 3 and 4 is on digital pin 13
int val = 0;     //value for fade

void setup()
{
  pinMode(pwm_a, OUTPUT);  //Set control pins to be outputs
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);

  analogWrite(pwm_a, 100);  //set both motors to run at (100/255 = 39)% duty cycle (slow)
  analogWrite(pwm_b, 100);

}

void loop()
{ 
  // Move forward for 2 seconds.
  Forward(1);
  // Stop for 2 seconds
  Stop(2);
  // Move Left for 2 seconds
  Left(1);
  // Stop for 1 seconds
  Stop(1);
  // Move right for 1 seconds
  Right(1);
  // Stop for 2 seconds;
  Stop(2);
  // Move backwards for 2 seconds
  Reverse(1);
  // Stop for 2 seconds
  Stop(2);

}


void Reverse(int seconds)
{ 
  digitalWrite(dir_a, LOW);  //Reverse motor direction, 1 high, 2 low
  digitalWrite(dir_b, LOW);  //Reverse motor direction, 3 low, 4 high  
  analogWrite(pwm_a, 255);    //set both motors to run at (100/255 = 39)% duty cycle
  analogWrite(pwm_b, 255);
  delay(seconds*1000);

}

void Forward(int seconds) // no pwm defined
{
  digitalWrite(dir_a, HIGH);  //Set motor direction, 1 low, 2 high
  digitalWrite(dir_b, HIGH);  //Set motor direction, 3 high, 4 low
  analogWrite(pwm_a, 255);
  analogWrite(pwm_b, 255);
  delay(seconds*1000);
}

void Left(int seconds) //full speed forward
{ 
  digitalWrite(dir_a, LOW);  //Reverse motor direction, 1 high, 2 low
  digitalWrite(dir_b, LOW);  //Reverse motor direction, 3 low, 4 high  
  analogWrite(pwm_a, 0);    //set both motors to run at (100/255 = 39)% duty cycle
  analogWrite(pwm_b, 255);
  delay(seconds*1000);
}

void Right(int seconds) //full speed forward
{ 
  digitalWrite(dir_a, LOW);  //Reverse motor direction, 1 high, 2 low
  digitalWrite(dir_b, LOW);  //Reverse motor direction, 3 low, 4 high  
  analogWrite(pwm_a, 255);    //set both motors to run at (100/255 = 39)% duty cycle
  analogWrite(pwm_b, 0);
  delay(seconds*1000);
}

void Stop(int seconds) //stop
{ 
  digitalWrite(dir_a, HIGH); //Set motor direction, 1 low, 2 high
  digitalWrite(dir_b, HIGH); //Set motor direction, 3 high, 4 low
  analogWrite(pwm_a, 0);    //set both motors to run at 100% duty cycle (fast)
  analogWrite(pwm_b, 0); 
  delay(seconds*1000);
}
