/*
 *  NAME: ScreenSaver Mouse Jiggler
 *  DATE: 2016-10-20
 *  DESC: Arduino based mouse emulator, preventing computer screen-saver from
 *      kicking in and locking desktop (eg. during forensic investigation).
 *  AUTHOR: nshadov
 *  VERSION: 1.0
 */
 

#include <Mouse.h>

// This is runned once, during device initialization

int wiggle = 0;
int w = 0;

void setup()
{
  Mouse.begin();
  pinMode(PC13, OUTPUT);
  randomSeed(analogRead(0));  
  digitalWrite(PC13, LOW);      
}



//Main loop - move mouse back and forth every 5 seconds

void loop()
{
  delay(1000);

  while(true) { 
    wiggle = random(2,5);
    Mouse.move(wiggle,0,0);
    delay(100);
    Mouse.move(0-wiggle,0,0);

    w = random(30,60);
        if (digitalRead(PC13)){ 
        digitalWrite(PC13, LOW);      
    } else {
        digitalWrite(PC13, HIGH);            
    }

    delay(w * 1000);
  }
}
