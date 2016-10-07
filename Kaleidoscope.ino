#include <NewPing.h>      
#include <Servo.h>        

#define TRIGGER_PIN  5   
#define ECHO_PIN     4   
#define MAX_DISTANCE 200 


Servo myservo;  
Servo myservo2; 

int pos = 0;   
int maxRotation = 160;
int minRotation = 20;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  
  myservo2.attach(8); 
}

void loop() {
  delay(20);
  int distance = sonar.ping_in(); 
  
  if (distance <= 22 && distance > 10) {

    for (pos = minRotation; pos <= maxRotation; pos += 1) { 
      myservo.write(pos);                 
      myservo2.write(maxRotation-pos);
      delay(15);                       
    }
    for (pos = maxRotation; pos >= minRotation; pos -= 1) { 
      myservo.write(pos);              
      myservo2.write(maxRotation-pos);
      delay(15);                      
    }

  }

}
