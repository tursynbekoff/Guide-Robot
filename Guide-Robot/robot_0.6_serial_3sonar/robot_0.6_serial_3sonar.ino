
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

void setup() {
  Serial.begin(9600);
  
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
  delayMicroseconds(2); // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW); // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);  // Calculating the distance
  distance1= duration1*0.034/2;
}

void echo2(){
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(13);
  digitalWrite(trigPin2, LOW);  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration2 = pulseIn(echoPin2, HIGH);  // Calculating the distance
  distance2= duration2*0.034/2;
}

void echo3(){
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(4); // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(12);
  digitalWrite(trigPin3, LOW);// Reads the echoPin, returns the sound wave travel time in microseconds
  duration3 = pulseIn(echoPin3, HIGH); // Calculating the distance
  distance3= duration3*0.034/2;
}


void forward(int dly){

  digitalWrite(39, HIGH);// forward
  digitalWrite(43, HIGH);
  delay(dly);

  digitalWrite(39, LOW);
  digitalWrite(43, LOW);
}


void initiate(){

  digitalWrite(41, HIGH);// goes forward
  digitalWrite(45, HIGH);

}


void terminate(){

  digitalWrite(39, LOW);// terminates all motors
  digitalWrite(41, LOW);
  digitalWrite(43, LOW);
  digitalWrite(45, LOW);
}


void turn_left(int angl){
  int dly;
  dly = angl*6.67; 
  digitalWrite(39, HIGH);
  digitalWrite(45, HIGH);
  delay(dly);

  digitalWrite(39, LOW);
  digitalWrite(45, LOW);
}


void left_90(){

  digitalWrite(39, HIGH);
  digitalWrite(45, HIGH);
  delay(600);

  digitalWrite(39, LOW);
  digitalWrite(45, LOW);
}

void left_45(){

  digitalWrite(39, HIGH);
  digitalWrite(45, HIGH);
  delay(300);

  digitalWrite(39, LOW);
  digitalWrite(45, LOW);
}

void right_135(){

  digitalWrite(43, HIGH);
  digitalWrite(41, HIGH);
  delay(900);

  digitalWrite(43, LOW);
  digitalWrite(41, LOW);
}


void turn_right(int angl){
  int dly;
  dly = angl*6.67; 
  digitalWrite(43, HIGH);
  digitalWrite(41, HIGH);
  delay(dly);

  digitalWrite(43, LOW);
  digitalWrite(41, LOW);
}

void right_90(){

  digitalWrite(43, HIGH);
  digitalWrite(41, HIGH);
  delay(600);

  digitalWrite(43, LOW);
  digitalWrite(41, LOW);
}

void backward(int dly){

  digitalWrite(41, HIGH);
  digitalWrite(45, HIGH);
  delay(dly);

  digitalWrite(41, LOW);
  digitalWrite(45, LOW);
}

void loop() {
  echo1();
  echo2();
  echo3();
  
  if(distance1<110 || distance2<100 || distance3<100){
      terminate();
      delay(2500);   
  }else{

  
      if(Serial.available() > 0) {
        int data = Serial.read();
        char c = data;
        char dest[4];
        dest[0] = c;
        delay(25);
        for (int i=1; i < 6; i++){
          int data = Serial.read();
          char c = data;
          dest[i] = c;
          delay(25);
       }
       char cmd = dest[0];
       char dly[4];
       for (int i=0; i < 4; i++){
          dly[i] = dest[i+2];
          delay(25);
       }
       int dlay = atoi(dly);
       Serial.println(cmd);
       Serial.println(dlay);
       Serial.println();
       if (cmd == 'f'){
        forward(dlay);
       }else if(cmd == 'l'){
        turn_left(dlay);
       }else if(cmd == 'r'){
        turn_right(dlay);
       }else if(cmd == 'b'){
        backward(dlay);
       }else if(cmd == 'q'){
        left_90();
       }else if(cmd == 'e'){
        right_90(); 
       }else if(cmd == 't'){
        terminate(); 
       }else if(cmd == 'i'){
        initiate();
       }else if(cmd == 'a'){
        left_45();
       }else if(cmd == 'd'){
        right_135();
       }else{
        //terminate();
       }
      } 

      
  }

   delay(250);
  
}
