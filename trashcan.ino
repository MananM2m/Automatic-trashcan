#include <HCSR04.h>
#include <Servo.h>
#include "IRremote.h"

HCSR04 uss(6,7); //echo trig

Servo myservo;

int receiver = 10;

bool open = false;
IRrecv rec(receiver);

decode_results results;

void setup() {
  myservo.attach(9);
  rec.enableIRIn();
  myservo.write(0);
}

void loop() {
  
  if(uss.dist() < 30 || open){
    myservo.write(160);
    delay(60);
    
  }
  else if(!open && uss.dist() > 30){
    
    myservo.write(0);
    delay(60);
    
  }

  if (rec.decode(&results)){
    
      open = !open;
      delay(60);
      rec.resume();
    
  }

  

}
