void setup() {
  Serial.begin(9600);
//  pinMode(LED_BUILTIN, OUTPUT);
//  pinMode(22, OUTPUT);
//  pinMode(52, OUTPUT);

  pinMode(39, OUTPUT);//motor1A
  pinMode(41, OUTPUT);//motor1B
  pinMode(43, OUTPUT);//motor2A
  pinMode(45, OUTPUT);//motot2B
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
  digitalWrite(39, HIGH);// goes forward
  digitalWrite(43, HIGH);
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
   }else{
    terminate();
   }
   
//    Serial.println(dest);
//  byte byteArray[5];
//  strcpy((char *)byteArray,str);
//  String myString = String((char *)byteArray);
//  Serial.print(myString);
//    if (strcmp("l_1000", dest) == 0){
//      digitalWrite(LED_BUILTIN, HIGH);
//      delay(500);
//      digitalWrite(LED_BUILTIN, LOW);
//      delay(500);
//      digitalWrite(LED_BUILTIN, HIGH);
//      delay(500);
//      digitalWrite(LED_BUILTIN, LOW);
//      delay(1000);
//      digitalWrite(LED_BUILTIN, HIGH);
//      delay(1000);
//      digitalWrite(LED_BUILTIN, LOW);
//    }
  }
}
