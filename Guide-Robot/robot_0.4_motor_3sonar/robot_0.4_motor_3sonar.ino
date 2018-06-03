
const int trigPin1 = 22;
const int echoPin1 = 24;

const int trigPin2 = 34;
const int echoPin2 = 32;

const int trigPin3 = 48;
const int echoPin3 = 50;

// defines variables
long duration1;
int distance1;

long duration2;
int distance2;

long duration3;
int distance3;
int t;

void setup() {
  Serial.begin(9600);
//  pinMode(LED_BUILTIN, OUTPUT);
//  pinMode(22, OUTPUT);
//  pinMode(52, OUTPUT);
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin3, INPUT);

  pinMode(39, OUTPUT);//motor1A
  pinMode(41, OUTPUT);//motor1B
  pinMode(43, OUTPUT);//motor2A
  pinMode(45, OUTPUT);//motot2B
}

void echo1(){
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distance1= duration1*0.034/2;
}

void echo2(){
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(13);
  digitalWrite(trigPin2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration2 = pulseIn(echoPin2, HIGH);
  // Calculating the distance
  distance2= duration2*0.034/2;
}

void echo3(){
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(4);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(12);
  digitalWrite(trigPin3, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration3 = pulseIn(echoPin3, HIGH);
  // Calculating the distance
  distance3= duration3*0.034/2;
}
void forward(int dly){
//  digitalWrite(22, HIGH);
//  digitalWrite(52, HIGH);
  digitalWrite(39, HIGH);// forward
  digitalWrite(43, HIGH);
  delay(dly);
//  digitalWrite(22, LOW);
//  digitalWrite(52, LOW);
  digitalWrite(39, LOW);
  digitalWrite(43, LOW);
}


void initiate(){
//  digitalWrite(39, HIGH);// goes forward
//  digitalWrite(43, HIGH);

  digitalWrite(41, HIGH);// goes forward
  digitalWrite(45, HIGH);
}


void terminate(){

  digitalWrite(39, LOW);// terminates all motors
  digitalWrite(41, LOW);
  digitalWrite(43, LOW);
  digitalWrite(45, LOW);
}


void turn_left(int dly){
//  digitalWrite(22, LOW);
//  digitalWrite(52, HIGH);
  digitalWrite(39, HIGH);
  digitalWrite(45, HIGH);
  delay(dly);
//  digitalWrite(22, LOW);
//  digitalWrite(52, LOW);
  digitalWrite(39, LOW);
  digitalWrite(45, LOW);
}


void left_90(){
//  digitalWrite(22, LOW);
//  digitalWrite(52, HIGH);
  digitalWrite(39, HIGH);
  digitalWrite(45, HIGH);
  delay(600);
//  digitalWrite(22, LOW);
//  digitalWrite(52, LOW);
  digitalWrite(39, LOW);
  digitalWrite(45, LOW);
}



void turn_right(int dly){
//  digitalWrite(22, HIGH);
//  digitalWrite(52, LOW);
  digitalWrite(43, HIGH);
  digitalWrite(41, HIGH);
  delay(dly);
//  digitalWrite(22, LOW);
//  digitalWrite(52, LOW);
  digitalWrite(43, LOW);
  digitalWrite(41, LOW);
}

void right_90(){
//  digitalWrite(22, HIGH);
//  digitalWrite(52, LOW);
  digitalWrite(43, HIGH);
  digitalWrite(41, HIGH);
  delay(600);
//  digitalWrite(22, LOW);
//  digitalWrite(52, LOW);
  digitalWrite(43, LOW);
  digitalWrite(41, LOW);
}

void backward(int dly){
//  digitalWrite(22, HIGH);
//  digitalWrite(52, HIGH);
  digitalWrite(41, HIGH);
  digitalWrite(45, HIGH);
  delay(dly);
//  digitalWrite(22, LOW);
//  digitalWrite(52, LOW);
  digitalWrite(41, LOW);
  digitalWrite(45, LOW);
}

void loop() {
//  digitalWrite(41, LOW);
//  digitalWrite(43, LOW);
//  digitalWrite(39, LOW);
//  digitalWrite(45, LOW);


  echo1();
  echo2();
  echo3();

//  buttonState1 = digitalRead(buttonPin1);
//  buttonState2 = digitalRead(buttonPin2);
//  buttonState3 = digitalRead(buttonPin3);

 //  initiate();
  
  if(distance1<110 || distance2<100 || distance3<100){
      terminate();
      delay(5000);   
  } 
//  else if((distance1>70 && distance1<99) || (distance2>70 && distance2<99)){
//      initiate();
//      delay(100);
//}
  else{
      initiate();

  }
//      if (buttonState1 == HIGH) {
//        // turn LED on:
//         initiate();
//        Serial.println("Forward");
//      } else if(buttonState2 == HIGH){
//      
//        right_90();//600
//        Serial.println("Back");
//      }
//       else if(buttonState3 == HIGH) {
//        // turn LED off:
//    
//        forward(10000);
//        turn_left(2350);
//        backward(1000);
//        Serial.println("Turn Around");
//       }
//       else{
//          digitalWrite(41, LOW);
//          digitalWrite(43, LOW);
//          digitalWrite(39, LOW);
//          digitalWrite(45, LOW);   
//       }

//  echo1();
//  echo2();
  Serial.print("Distance1: ");
  Serial.println(distance1);
  Serial.print("\t");
//  Serial.print("Distance2: ");
//  Serial.println(distance2);
  delay(250);
  



  
//  if (Serial.available()) {
//    
//    char what = Serial.read();
//    Serial.write(what);
//    if (what == 'f') {
//     forward(t); 
//      
//    }
//    else if (what == 'b') {// reverse
//    backwards(t);
//    }
//    else if (what == 'l') {//left
//    left(t);
//    }
//    else if (what == 'r') {//right
//    right(t);
//    }
//    else { //stop
//      digitalWrite(41, LOW);
//      digitalWrite(43, LOW);
//      digitalWrite(39, LOW);
//      digitalWrite(45, LOW);
//
//      Serial.println("Stopped");
//    }
//  }

  //Serial.println("Done, bro!");
}





