#define RPWM 3 // RPWM pin (output)
#define R_EN 2 // R_EN pin (input)
#define R_IS 4 // R_IS pin (output)

#define LPWM 5 // LPWM pin (output)
#define L_EN 6 //L_EN pin (input)
#define L_IS 7 // L_IS pin (output)
#define CW 1 //do not change
#define CCW 0 //do not change
#define debug 1 //change to 0 to hide serial monitor debugging infornmation or set to 1 to view


#include <RobojaxBTS7960.h>
RobojaxBTS7960 motor(R_EN, RPWM, R_IS, L_EN, LPWM, L_IS, debug);
boolean b0, c0;
boolean state1 = 1;
boolean state2 = 1;

int pin1 = 8;
int pin2 = 9;
int pin3 = 10;
int pin4 = 11;

void setup()
{
  pinMode(pin1, OUTPUT);
  digitalWrite(pin1, LOW);
  pinMode(pin2, INPUT_PULLUP);

  pinMode(pin3, OUTPUT);
  digitalWrite(pin3, LOW);
  pinMode(pin4, INPUT_PULLUP);

  motor.begin();
}

void loop()
{
  b0 = digitalRead(9); //uppwer switch
  c0 = digitalRead(11); //lower switch

//Starting
  if (b0 == HIGH && state1 == 1 && state2 == 1 )
  {
    motor.rotate(100, CW); // run motor with 100% speed in CW direction
  }

  if (b0 == LOW && state1 == 1 && state2 == 1)
  {
    motor.stop(); // stops motor after  switch is pressed
    state1 = 0;
    //delay(120000); // stay  up for 120 seconds
    delay(2000);
  }

  if (b0 == LOW && state1 == 0 && state2 == 1)
  {
    
    motor.rotate(100, CCW); // run motor with 100% speed in CCW direction
  }

//Go Down and stay for 240 sec

  if (c0 == HIGH && state1 == 0 && state2 == 1)
  {
    motor.rotate(100, CCW); // run motor with 100% speed in CCW direction
  }

  if (c0 == LOW && state1 == 0 && state2 == 1)
  {
    motor.stop(); // stops motor after switch is pressed
    state1 = 1;
    //delay(240000); // go down and stay for 240 sec
    delay(2000);
  }

  if (c0 == LOW && state1 == 1 && state2 == 1)
  {
    motor.rotate(100, CW); // run motor with 100% speed in CW direction
    state2 = 0;
  }
  
//Go up and stay for 120 sec
  if (b0 == HIGH && state1 == 1 && state2 == 1)
  {
    motor.rotate(100, CW); // stops motor after  switch is pressed
  }

  if (b0 == LOW && state1 == 1 && state2 == 1 )
  {
    motor.stop();  // run motor with 100% speed in CW direction
    state1=0;
    state2=0;
    //delay(120000); // go up and stay 120 sec
    delay(2000);
  }

  if (b0 == LOW && state1 == 0 && state2 == 0 )
  {
    motor.rotate(100, CCW);  // run motor with 100% speed in CW direction  
  }

//go down and stay for 240 sec
   if (c0 == HIGH && state1 == 0 && state2 == 0 )
  {
    motor.rotate(100, CCW); // run motor with 100% speed in CW direction
  }
  
 if (c0 == LOW && state1 == 0 && state2 == 0 )
  {
    motor.stop(); // run motor with 100% speed in CW direction
    state1=1;
    //delay(240000); // go down and stay 240
    delay(2000);
  }

  if (c0 == LOW && state1 == 1 && state2 == 0 )
  {
    motor.rotate(100, CW); // run motor with 100% speed in CW direction
  }

//Go Up and end


  if (b0 == HIGH && state1 == 1 && state2 == 0 )
  {
    motor.rotate(100, CW); // run motor with 100% speed in CW direction
  }

  if (b0 == LOW && state1 == 1 && state2 == 0 )
  {
    motor.stop(); // run motor with 100% speed in CW direction
    state2=1;
    //delay(2000);
    delay(2000);
  }
}
