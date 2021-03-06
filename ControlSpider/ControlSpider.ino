//-----------------------------------------------------------Motor---------------------------------------------------------------//
//declaration of variables & object
#include <SoftwareSerial.h>
#include <Cytron_G15Shield.h>
#define A12 12
#define A13 13
#define A1 1
#define B14 14
#define B15 15
#define B2 2
#define C16 16
#define C17 17
#define C3 3
#define D21 21
#define D22 22
#define D4 4
#define E23 23
#define E24 24
#define E5 5
#define F25 25
#define F26 26
#define F6 6

Cytron_G15Shield g15(2, 3, 8); // SoftwareSerial: Rx, Tx and Control pin
//-----------------------------------------------------------Functions---------------------------------------------------------------//
void setup() {
  //initialize the arduino main board's serial/UART and Control Pins
  //CTRL pin for G15 =3 and AX12 =8
  for(int i = 4; i < 8; i++)
  {
    pinMode(i, INPUT);    // sets the digital pin 7 as INPUT
    digitalWrite(i, HIGH); 
  }

  g15.begin(115200); 
  sitdown();
  standstraight();                                                 
  Serial.begin(9600); //Start the serial on computer
  delay(1000);  
  exitwheelforall();
}

void exitwheelforall(){
  g15.exitWheelMode(A12);
  g15.exitWheelMode(A13);
  g15.exitWheelMode(A1);
  g15.exitWheelMode(B14);
  g15.exitWheelMode(B15);
  g15.exitWheelMode(B2);
  g15.exitWheelMode(C16);
  g15.exitWheelMode(C17);
  g15.exitWheelMode(C3);
  g15.exitWheelMode(D21);
  g15.exitWheelMode(D22);
  g15.exitWheelMode(D4);
  g15.exitWheelMode(E23);
  g15.exitWheelMode(E24);
  g15.exitWheelMode(E5);
  g15.exitWheelMode(F25);
  g15.exitWheelMode(F26);
  g15.exitWheelMode(F6);
}

void sitdown(){
  setangle(A12,180,300);
  setangle(A13,135,300);
  setangle(A1,135,300);
  setangle(B14,90,300);
  setangle(B15,270,300);
  setangle(B2,135,300);
  setangle(C16,90,300);
  setangle(C17,135,300);
  setangle(C3,135,300);
  setangle(D21,270,300);
  setangle(D22,270,300);
  setangle(D4,135,300);
  setangle(E23,225,300);
  setangle(E24,180,300);
  setangle(E5,135,300);
  setangle(F25,270,300);
  setangle(F26,135,300);
  setangle(F6,135,300);
  delay(1000);
}

//robot standsupright
void standstraight(){
  setangle(A12,180,300);
  setangle(A13,135,300);
  setangle(A1,120,300);
  setangle(B14,180,300);
  setangle(B15,180,300);
  setangle(B2,120,300);
  setangle(C16,180,300);
  setangle(C17,135,300);
  setangle(C3,120,300);
  setangle(D21,180,300);
  setangle(D22,180,300);
  setangle(D4,120,300);
  setangle(E23,220,300);
  setangle(E24,180,300);
  setangle(E5,120,300);
  setangle(F25,180,300);
  setangle(F26,135,300);
  setangle(F6,120,300);
  delay(1000);
}

//robot moves forward
void movebackward(){
  //step 1
  turnangle(200,160,0.5,A12);
  turnangle(115,155,0.5,A13);
  turnangle(180,180,0.5,B14);
  turnangle(180,180,0.5,B15);
  turnangle(120,120,0.5,C16);
  turnangle(155,115,0.5,C17);
  turnangle(240,240,0.5,D21);
  turnangle(240,240,0.5,D22);
  turnangle(215,255,0.5,E23);
  turnangle(200,160,0.5,E24);
  turnangle(180,180,0.5,F25);
  turnangle(155,115,0.5,F26);
  turnangle(108,108,0.5,A1);
  turnangle(130,130,0.5,B2);
  turnangle(108,130,0.5,C3);
  turnangle(130,130,0.5,D4);
  turnangle(108,108,0.5,E5);
  turnangle(130,130,0.5,F6);
  delay(500);

  //step 2
  turnangle(160,160,0.3,A12);
  turnangle(155,155,0.3,A13);
  turnangle(180,120,0.3,B14);
  turnangle(180,240,0.3,B15);
  turnangle(120,180,0.3,C16);
  turnangle(115,115,0.3,C17);
  turnangle(240,180,0.3,D21);
  turnangle(240,180,0.3,D22);
  turnangle(255,255,0.3,E23);
  turnangle(160,160,0.3,E24);
  turnangle(180,240,0.3,F25);
  turnangle(115,115,0.3,F26);
  turnangle(108,130,0.3,A1);
  turnangle(130,108,0.3,B2);
  turnangle(130,130,0.3,C3);
  turnangle(130,108,0.3,D4);
  turnangle(108,130,0.3,E5);
  turnangle(130,108,0.3,F6);
  delay(300);

  //step 3
  turnangle(160,200,0.5,A12);
  turnangle(155,115,0.5,A13);
  turnangle(120,120,0.5,B14);
  turnangle(240,240,0.5,B15);
  turnangle(180,180,0.5,C16);
  turnangle(115,155,0.5,C17);
  turnangle(180,180,0.5,D21);
  turnangle(180,180,0.5,D22);
  turnangle(255,215,0.5,E23);
  turnangle(160,200,0.5,E24);
  turnangle(240,240,0.5,F25);
  turnangle(115,155,0.5,F26);
  turnangle(130,130,0.5,A1);
  turnangle(108,130,0.5,B2);
  turnangle(130,130,0.5,C3);
  turnangle(108,108,0.5,D4);
  turnangle(130,130,0.5,E5);
  turnangle(108,108,0.5,F6);
  delay(500);

  //step 4
  turnangle(200,200,0.3,A12);
  turnangle(115,115,0.3,A13);
  turnangle(120,180,0.3,B14);
  turnangle(240,180,0.3,B15);
  turnangle(180,120,0.3,C16);
  turnangle(155,155,0.3,C17);
  turnangle(180,240,0.3,D21);
  turnangle(180,240,0.3,D22);
  turnangle(215,215,0.3,E23);
  turnangle(200,200,0.3,E24);
  turnangle(240,180,0.3,F25);
  turnangle(155,155,0.3,F26);
  turnangle(130,108,0.3,A1);
  turnangle(130,130,0.3,B2);
  turnangle(130,108,0.3,C3);
  turnangle(108,130,0.3,D4);
  turnangle(130,108,0.3,E5);
  turnangle(108,130,0.3,F6);
  delay(300);
}

void moveforward(){
  //step 1
  turnangle(200,200,0.3,A12);
  turnangle(115,115,0.3,A13);
  turnangle(180,120,0.3,B14);
  turnangle(180,240,0.3,B15);
  turnangle(120,180,0.3,C16);
  turnangle(155,155,0.3,C17);
  turnangle(240,180,0.3,D21);
  turnangle(240,180,0.3,D22);
  turnangle(215,215,0.3,E23);
  turnangle(200,200,0.3,E24);
  turnangle(180,240,0.3,F25);
  turnangle(155,155,0.3,F26);
  turnangle(108,130,0.3,A1);
  turnangle(130,130,0.3,B2);
  turnangle(108,130,0.3,C3);
  turnangle(130,108,0.3,D4);
  turnangle(108,130,0.3,E5);
  turnangle(130,108,0.3,F6);
  delay(300);

  //step 2
  turnangle(200,160,0.5,A12);
  turnangle(115,155,0.5,A13);
  turnangle(120,120,0.5,B14);
  turnangle(240,240,0.5,B15);
  turnangle(180,180,0.5,C16);
  turnangle(155,115,0.5,C17);
  turnangle(180,180,0.5,D21);
  turnangle(180,180,0.5,D22);
  turnangle(215,255,0.5,E23);
  turnangle(200,160,0.5,E24);
  turnangle(240,240,0.5,F25);
  turnangle(155,115,0.5,F26);
  turnangle(130,130,0.5,A1);
  turnangle(130,108,0.5,B2);
  turnangle(130,130,0.5,C3);
  turnangle(108,108,0.5,D4);
  turnangle(130,130,0.5,E5);
  turnangle(108,108,0.5,F6);
  delay(500);

  //step 3
  turnangle(160,160,0.3,A12);
  turnangle(155,155,0.3,A13);
  turnangle(120,180,0.3,B14);
  turnangle(240,180,0.3,B15);
  turnangle(180,120,0.3,C16);
  turnangle(115,115,0.3,C17);
  turnangle(180,240,0.3,D21);
  turnangle(180,240,0.3,D22);
  turnangle(255,255,0.3,E23);
  turnangle(160,160,0.3,E24);
  turnangle(240,180,0.3,F25);
  turnangle(115,115,0.3,F26);
  turnangle(130,108,0.3,A1);
  turnangle(108,130,0.3,B2);
  turnangle(130,130,0.3,C3);
  turnangle(108,130,0.3,D4);
  turnangle(130,108,0.3,E5);
  turnangle(108,130,0.3,F6);
  delay(300);

  //step 4
  turnangle(160,200,0.5,A12);
  turnangle(155,115,0.5,A13);
  turnangle(180,180,0.5,B14);
  turnangle(180,180,0.5,B15);
  turnangle(120,120,0.5,C16);
  turnangle(115,155,0.5,C17);
  turnangle(240,240,0.5,D21);
  turnangle(240,240,0.5,D22);
  turnangle(255,215,0.5,E23);
  turnangle(160,200,0.5,E24);
  turnangle(180,180,0.5,F25);
  turnangle(115,155,0.5,F26);
  turnangle(108,108,0.5,A1);
  turnangle(130,130,0.5,B2);
  turnangle(130,108,0.5,C3);
  turnangle(130,130,0.5,D4);
  turnangle(108,108,0.5,E5);
  turnangle(130,130,0.5,F6);
  delay(500);
}

void turnright(){

  //step 1
  turnangle(225,180,0.5,A12);
  turnangle(180,135,0.5,A13);
  turnangle(180,180,0.5,B14);
  turnangle(180,180,0.5,B15);
  turnangle(120,120,0.5,C16);
  turnangle(135,90,0.5,C17);
  turnangle(240,240,0.5,D21);
  turnangle(240,240,0.5,D22);
  turnangle(225,270,0.5,E23);
  turnangle(180,225,0.5,E24);
  turnangle(180,180,0.5,F25);
  turnangle(90,135,0.5,F26);
  turnangle(108,108,0.5,A1);
  turnangle(130,130,0.5,B2);
  turnangle(108,130,0.5,C3);
  turnangle(130,130,0.5,D4);
  turnangle(108,108,0.5,E5);
  turnangle(130,130,0.5,F6);
  delay(500);

  //step 2 
  turnangle(180,180,0.5,A12);
  turnangle(135,135,0.5,A13);
  turnangle(180,120,0.5,B14);
  turnangle(180,240,0.5,B15);
  turnangle(120,180,0.5,C16);
  turnangle(90,90,0.5,C17);
  turnangle(240,180,0.5,D21);
  turnangle(240,180,0.5,D22);
  turnangle(270,270,0.5,E23);
  turnangle(225,225,0.5,E24);
  turnangle(180,240,0.5,F25);
  turnangle(135,135,0.5,F26);
  turnangle(108,130,0.5,A1);
  turnangle(130,108,0.5,B2);
  turnangle(130,130,0.5,C3);
  turnangle(130,108,0.5,D4);
  turnangle(108,130,0.5,E5);
  turnangle(130,108,0.5,F6);
  delay(500);

  //step 3
  turnangle(180,225,0.5,A12);
  turnangle(135,180,0.5,A13);
  turnangle(120,120,0.5,B14);
  turnangle(240,240,0.5,B15);
  turnangle(180,180,0.5,C16);
  turnangle(90,135,0.5,C17);
  turnangle(180,180,0.5,D21);
  turnangle(180,180,0.5,D22);
  turnangle(270,225,0.5,E23);
  turnangle(225,180,0.5,E24);
  turnangle(240,240,0.5,F25);
  turnangle(135,90,0.5,F26);
  turnangle(130,130,0.5,A1);
  turnangle(108,130,0.5,B2);
  turnangle(130,130,0.5,C3);
  turnangle(108,108,0.5,D4);
  turnangle(130,130,0.5,E5);
  turnangle(108,108,0.5,F6);
  delay(500);

  //step 4
  turnangle(225,225,0.5,A12);
  turnangle(180,180,0.5,A13);
  turnangle(120,180,0.5,B14);
  turnangle(240,180,0.5,B15);
  turnangle(180,120,0.5,C16);
  turnangle(135,135,0.5,C17);
  turnangle(180,240,0.5,D21);
  turnangle(180,240,0.5,D22);
  turnangle(225,225,0.5,E23);
  turnangle(180,180,0.5,E24);
  turnangle(240,180,0.5,F25);
  turnangle(90,90,0.5,F26);
  turnangle(130,108,0.5,A1);
  turnangle(130,130,0.5,B2);
  turnangle(130,108,0.5,C3);
  turnangle(108,130,0.5,D4);
  turnangle(130,108,0.5,E5);
  turnangle(108,130,0.5,F6);
  delay(500);
}

void turnleft(){

  //step 1
  turnangle(225,225,0.5,A12);
  turnangle(180,180,0.5,A13);
  turnangle(120,180,0.5,B14);
  turnangle(240,180,0.5,B15);
  turnangle(180,120,0.5,C16);
  turnangle(135,135,0.5,C17);
  turnangle(180,240,0.5,D21);
  turnangle(180,240,0.5,D22);
  turnangle(225,225,0.5,E23);
  turnangle(180,180,0.5,E24);
  turnangle(240,180,0.5,F25);
  turnangle(90,90,0.5,F26);
  turnangle(130,108,0.5,A1);
  turnangle(130,130,0.5,B2);
  turnangle(130,108,0.5,C3);
  turnangle(108,130,0.5,D4);
  turnangle(130,108,0.5,E5);
  turnangle(108,130,0.5,F6);
  delay(500);

  //step 2
  turnangle(180,225,0.5,A12);
  turnangle(135,180,0.5,A13);
  turnangle(120,120,0.5,B14);
  turnangle(240,240,0.5,B15);
  turnangle(180,180,0.5,C16);
  turnangle(90,135,0.5,C17);
  turnangle(180,180,0.5,D21);
  turnangle(180,180,0.5,D22);
  turnangle(270,225,0.5,E23);
  turnangle(225,180,0.5,E24);
  turnangle(240,240,0.5,F25);
  turnangle(135,90,0.5,F26);
  turnangle(130,130,0.5,A1);
  turnangle(108,130,0.5,B2);
  turnangle(130,130,0.5,C3);
  turnangle(108,108,0.5,D4);
  turnangle(130,130,0.5,E5);
  turnangle(108,108,0.5,F6);
  delay(500);

  //step 3 
  turnangle(180,180,0.5,A12);
  turnangle(135,135,0.5,A13);
  turnangle(180,120,0.5,B14);
  turnangle(180,240,0.5,B15);
  turnangle(120,180,0.5,C16);
  turnangle(90,90,0.5,C17);
  turnangle(240,180,0.5,D21);
  turnangle(240,180,0.5,D22);
  turnangle(270,270,0.5,E23);
  turnangle(225,225,0.5,E24);
  turnangle(180,240,0.5,F25);
  turnangle(135,135,0.5,F26);
  turnangle(108,130,0.5,A1);
  turnangle(130,108,0.5,B2);
  turnangle(130,130,0.5,C3);
  turnangle(130,108,0.5,D4);
  turnangle(108,130,0.5,E5);
  turnangle(130,108,0.5,F6);
  delay(500);

  //step 4
  turnangle(225,180,0.5,A12);
  turnangle(180,135,0.5,A13);
  turnangle(180,180,0.5,B14);
  turnangle(180,180,0.5,B15);
  turnangle(120,120,0.5,C16);
  turnangle(135,90,0.5,C17);
  turnangle(240,240,0.5,D21);
  turnangle(240,240,0.5,D22);
  turnangle(225,270,0.5,E23);
  turnangle(180,225,0.5,E24);
  turnangle(180,180,0.5,F25);
  turnangle(90,135,0.5,F26);
  turnangle(108,108,0.5,A1);
  turnangle(130,130,0.5,B2);
  turnangle(108,130,0.5,C3);
  turnangle(130,130,0.5,D4);
  turnangle(108,108,0.5,E5);
  turnangle(130,130,0.5,F6);
  delay(500);
}

void tiltfront(){

  //step 1
  setangle(A12,180,800);
  setangle(A13,135,800);
  setangle(B14,180,800);
  setangle(B15,77,800);
  setangle(C16,180,800);
  setangle(C17,135,800);
  setangle(D21,90,800);
  setangle(D22,76,800);
  setangle(E23,225,800);
  setangle(E24,180,800);
  setangle(F25,85,800);
  setangle(F26,135,800);
  delay(200);
}

void tiltback(){

  //step 1
  setangle(A12,180,800);
  setangle(A13,135,800);
  setangle(B14,270,800);
  setangle(B15,77,800);
  setangle(C16,270,800);
  setangle(C17,135,800);
  setangle(D21,90,800);
  setangle(D22,180,800);
  setangle(E23,225,800);
  setangle(E24,180,800);
  setangle(F25,180,800);
  setangle(F26,135,800);
  delay(200);
}

void tiltleft(){

  //step 1
  setangle(A12,180,800);
  setangle(A13,135,800);
  setangle(B14,270,800);
  setangle(B15,180,800);
  setangle(C16,180,800);
  setangle(C17,135,800);
  setangle(D21,90,800);
  setangle(D22,180,800);
  setangle(E23,225,800);
  setangle(E24,180,800);
  setangle(F25,90,800);
  setangle(F26,135,800);
  delay(200);
}

void tiltright(){

  //step 1
  setangle(A12,180,800);
  setangle(A13,135,800);
  setangle(B14,180,800);
  setangle(B15,90,800);
  setangle(C16,270,800);
  setangle(C17,135,800);
  setangle(D21,180,800);
  setangle(D22,90,800);
  setangle(E23,225,800);
  setangle(E24,180,800);
  setangle(F25,180,800);
  setangle(F26,135,800);
  delay(200);
}

void turnangle(int start,int endd,double timee, int ID){
  double x = abs((((start-endd)/timee)/360)  * 1088);
  if (x == 0)
  {
    g15.setPosAngle(ID,endd);
  }
  else
  {
    g15.setSpeed(ID,x);
    g15.setPosAngle(ID,endd);
  }
}

void setangle(int ID,int start, int speed){
  g15.setSpeed(ID, speed); 
  g15.setPosAngle(ID, start);
}

word error = 0;
byte data[10];
word position = 0;
bool debug = 1;

int readangle(int motorid){
  while (g15.getPos(motorid, data)!=0)
  {
    Serial.println("Error");
    error = g15.getPos(motorid, data); // Get G15 ID1 knob position
  }
  if(error == 0) // No error
  {
    digitalWrite(13, LOW);
    position = data[0];
    position = position | (data[1] << 8);
    if (debug)
    {
      Serial.print(motorid);
      Serial.print("   ");
      Serial.print(position); // Print position
      Serial.print("   ");
      Serial.println(ConvertPosToAngle(position)); // Print angle
    }
    return ConvertPosToAngle(position);
  }
  else // Error occur, LED on CT UNO will light up
  {
    digitalWrite(13, HIGH);
  }
  delay(200);
}

void test(){
  moveforward();
  moveforward();
  movebackward();
  movebackward();
  turnleft();
  turnleft();
  turnright();
  turnright();
}

void loop() {
  //test();
  if (digitalRead(7)==LOW && digitalRead(6)==HIGH && digitalRead(5)==LOW && digitalRead(4)==HIGH) { //0101
    turnleft();
  }
  else if (digitalRead(7)==HIGH && digitalRead(6)==LOW && digitalRead(5)==HIGH && digitalRead(4)==LOW) { //1010
    turnright();
  }
  else if (digitalRead(7)==LOW && digitalRead(6)==HIGH && digitalRead(5)==HIGH && digitalRead(4)==LOW) { //0110
    moveforward();
  }
  else if (digitalRead(7)==HIGH && digitalRead(6)==LOW && digitalRead(5)==LOW && digitalRead(4)==HIGH) { //1001
    movebackward();
  }
  else if (digitalRead(7)==HIGH && digitalRead(6)==LOW && digitalRead(5)==LOW && digitalRead(4)==LOW) { //1000
    tiltleft();
  }
  else if (digitalRead(7)==LOW && digitalRead(6)==HIGH && digitalRead(5)==LOW && digitalRead(4)==LOW) { //0100
    tiltright();
  }
  else if (digitalRead(7)==LOW && digitalRead(6)==LOW && digitalRead(5)==HIGH && digitalRead(4)==LOW) { //0010
    tiltfront();
  }
  else if (digitalRead(7)==HIGH && digitalRead(6)==HIGH && digitalRead(5)==HIGH && digitalRead(4)==LOW) { //1110
    tiltback();
  }
  else {
    standstraight();
  }
}
