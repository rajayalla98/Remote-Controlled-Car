//int Motor_A_Enable = 9;
int Motor_A_Reverse = 2;
int Motor_A_Forward = 4;

//int Motor_B_Enable = 10;
int Motor_B_Reverse = 12;
int Motor_B_Forward = 7;

const int trigPin = 8;
const int echoPin = 9;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  //pinMode(Motor_A_Enable, OUTPUT);
  pinMode(Motor_A_Forward, OUTPUT);
  pinMode(Motor_A_Reverse, OUTPUT);

 // pinMode(Motor_B_Enable, OUTPUT);
  pinMode(Motor_B_Forward, OUTPUT);
  pinMode(Motor_B_Reverse, OUTPUT);
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop() {

  if(Serial.available() > 0)
  {
    char data;
    data = Serial.read();
    Serial.write(Serial.read());
    
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance= duration*0.034/2;
    
    switch (data)
    {
      case '1': //FORWARD
       if(distance>40)
       {
          digitalWrite(Motor_A_Reverse, LOW);
          digitalWrite(Motor_B_Reverse, LOW);
          digitalWrite(Motor_A_Forward, HIGH);
          digitalWrite(Motor_B_Forward, HIGH);
          delay(1000);
          digitalWrite(Motor_B_Reverse, LOW);
          digitalWrite(Motor_B_Forward, LOW);
          digitalWrite(Motor_A_Reverse, LOW);
          digitalWrite(Motor_A_Forward, LOW);
       }
       else
       {
          Serial.println("obstacle at a distance less than 4 0cm cannot move");
       }
        break;
      case '2': //REVERSE
        
        digitalWrite(Motor_A_Forward, LOW);
        digitalWrite(Motor_B_Forward, LOW);
        digitalWrite(Motor_A_Reverse, HIGH);
        digitalWrite(Motor_B_Reverse, HIGH);
        delay(1000);
        digitalWrite(Motor_B_Reverse, LOW);
        digitalWrite(Motor_B_Forward, LOW);
        digitalWrite(Motor_A_Reverse, LOW);
        digitalWrite(Motor_A_Forward, LOW);
        break;
      case '3': //FORWARD LEFT
        
        digitalWrite(Motor_A_Reverse, LOW);
        digitalWrite(Motor_A_Forward, HIGH);
        digitalWrite(Motor_B_Reverse, LOW);
        digitalWrite(Motor_B_Forward, LOW);
        delay(500);
        digitalWrite(Motor_B_Reverse, LOW);
        digitalWrite(Motor_B_Forward, LOW);
        digitalWrite(Motor_A_Reverse, LOW);
        digitalWrite(Motor_A_Forward, LOW);
        break;
      case '4': //FORWARD RIGHT
        
        digitalWrite(Motor_B_Reverse, LOW);
        digitalWrite(Motor_B_Forward, HIGH);
        digitalWrite(Motor_A_Reverse, LOW);
        digitalWrite(Motor_A_Forward, LOW);
        delay(500);
        digitalWrite(Motor_B_Reverse, LOW);
        digitalWrite(Motor_B_Forward, LOW);
        digitalWrite(Motor_A_Reverse, LOW);
        digitalWrite(Motor_A_Forward, LOW);
        break;

        case '5': //STOP
        
        
       digitalWrite(Motor_B_Reverse, LOW);
        digitalWrite(Motor_B_Forward, LOW);
        digitalWrite(Motor_A_Reverse, LOW);
        digitalWrite(Motor_A_Forward, LOW);
        
        break;
      
      default: //If bluetooth module receives any value not listed above, both motors turn off
        digitalWrite(Motor_B_Reverse, LOW);
        digitalWrite(Motor_B_Forward, LOW);
        digitalWrite(Motor_A_Reverse, LOW);
        digitalWrite(Motor_A_Forward, LOW);
        
    }
  }
}
