#define leftTrigPin 12
#define leftEchoPin 13
#define rightTrigPin 2
#define rightEchoPin 3
#define rightWarning 8
#define leftWarning 9

void setup() {
  Serial.begin (9600);
  pinMode(leftTrigPin, OUTPUT);
  pinMode(leftEchoPin, INPUT);
  pinMode(rightTrigPin, OUTPUT);
  pinMode(rightEchoPin, INPUT);
  pinMode(rightWarning, OUTPUT);
  pinMode(leftWarning, OUTPUT);
}

void loop() {
  float leftDuration, leftDistance, rightDuration, rightDistance, minDist;

  minDist = 1; //minimum distance 

  digitalWrite(rightWarning, LOW);
  digitalWrite(leftWarning, LOW);
  
  digitalWrite(leftTrigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(leftTrigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(leftTrigPin, LOW);
  leftDuration = pulseIn(leftEchoPin, HIGH);
  leftDistance = (leftDuration/2) / 29.1/2.54 -0.3;

  digitalWrite(rightTrigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(rightTrigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(rightTrigPin, LOW);
  rightDuration = pulseIn(rightEchoPin, HIGH);
  rightDistance = (rightDuration/2) / 29.1/2.54 -0.3;


  /*if (leftDistance < minDist){
    digitalWrite(leftWarning, HIGH);
    Serial.println("Left Warning");
  }
  
  if(rightDistance < minDist){
    digitalWrite(rightWarning, HIGH);
    Serial.println("Right Warning");
  }*/
  if (leftDistance > minDist && leftDistance < 30){
    //Serial.print("left distance: ");
    Serial.println(leftDistance);
    //Serial.print(" in, ");    
  }
  else{
    Serial.println("Left out of range");
  }
  
  if (rightDistance > minDist && rightDistance < 30){
    //Serial.print("right distance: ");
    Serial.println(rightDistance);
    //Serial.println(" in");   
  }
  else{
    Serial.println("Right out of range");
  }
   
  
  delay(250);
}

