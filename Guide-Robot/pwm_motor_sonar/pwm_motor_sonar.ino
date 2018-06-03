//int E1 = 10;
//int M1 = 12;
int E2 = 11;
int M2 = 13;


const int trigPin1 = 3;
const int echoPin1 = 4;
long duration1;
int distance1;
void setup()
{
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an 
  Serial.begin(9600);
 // pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}
int value = 0;

void initiate(){
//  digitalWrite(39, HIGH);// goes forward
//  digitalWrite(43, HIGH);



    for(value = 0 ; value <= 255; value+=5)
    {
     // digitalWrite(M1,HIGH);
      digitalWrite(M2, LOW);
    //  analogWrite(E1, value);
      analogWrite(E2, value);
      delay(30);
          if(value==255){
            return value;
            }
    }
  
}

void echo1(){
digitalWrite(trigPin1, LOW);
delayMicroseconds(4);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(12);
digitalWrite(trigPin1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echoPin1, HIGH);
// Calculating the distance
distance1= duration1*0.034/2;
}



void loop()
{

if (distance1<50){
  digitalWrite(M2, LOW);
  digitalWrite(E2, LOW);
  value = 0;  
}else if(distance1>50 && distance1 < 100){
  digitalWrite(M2, LOW);
  analogWrite(E2, 200);
}else{
  if (value==255){
  digitalWrite(M2, LOW);
  digitalWrite(E2, HIGH);
  } else{
  initiate();
  }    
}
  





echo1();
  //echo2();

Serial.print("Distance1: ");
Serial.println(distance1);

delay(100);
  
//  { 
//    int value;
//    for(value = 0 ; value <= 255; value+=5)
//    {
//     // digitalWrite(M1,HIGH);
//      digitalWrite(M2, HIGH);
//    //  analogWrite(E1, value);
//      analogWrite(E2, value);
//      delay(30);
//    }
//    delay(1000);
//  }
//
//  { 
//    int value;
//    for(value = 0 ; value <= 255; value+=5)
//    {
//    //  digitalWrite(M1,LOW);
//      digitalWrite(M2, LOW);
//    //  analogWrite(E1, value);
//      analogWrite(E2, value);
//      delay(30);
//    }
//    delay(1000);
//  }
} 
