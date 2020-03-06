//-----------------------------------------------------------Motor---------------------------------------------------------------//
//declaration of variables & object
#include <SoftwareSerial.h>
#include <Cytron_G15Shield.h>
#define A12 12
#define A13 13
#define B14 14
#define B15 15
#define C16 16
#define C17 17
#define D21 21
#define D22 22
#define E23 23
#define E24 24
#define F25 25
#define F26 26

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
  standstraight();                                 
  Serial.begin(9600); //Start the serial on computer
  delay(1000);  
}

//robot standsupright
void standstraight(){
  g15.exitWheelMode(A12);
  g15.exitWheelMode(A13);
  g15.exitWheelMode(B14);
  g15.exitWheelMode(B15);
  g15.exitWheelMode(C16);
  g15.exitWheelMode(C17);
  g15.exitWheelMode(D21);
  g15.exitWheelMode(D22);
  g15.exitWheelMode(E23);
  g15.exitWheelMode(E24);
  g15.exitWheelMode(F25);
  g15.exitWheelMode(F26);

  setangle(A12,180,300);
  setangle(A13,135,300);
  setangle(B14,225,300);
  setangle(B15,115,300);
  setangle(C16,225,300);
  setangle(C17,135,300);
  setangle(D21,135,300);
  setangle(D22,135,300);
  setangle(E23,225,300);
  setangle(E24,180,300);
  setangle(F25,135,300);
  setangle(F26,141,300);
  delay(1000);
}

//robot moves forward
void moveforward(){
  g15.exitWheelMode(A12);
  g15.exitWheelMode(A13);
  g15.exitWheelMode(B14);
  g15.exitWheelMode(B15);
  g15.exitWheelMode(C16);
  g15.exitWheelMode(C17);
  g15.exitWheelMode(D21);
  g15.exitWheelMode(D22);
  g15.exitWheelMode(E23);
  g15.exitWheelMode(E24);
  g15.exitWheelMode(F25);
  g15.exitWheelMode(F26);

  //step 1
  turnangle(180,180,0.3,A12);
  turnangle(135,135,0.3,A13);
  turnangle(225,180,0.3,B14);
  turnangle(125,180,0.3,B15);
  turnangle(180,240,0.3,C16);
  turnangle(180,180,0.3,C17);
  turnangle(180,120,0.3,D21);
  turnangle(180,130,0.3,D22);
  turnangle(225,235,0.3,E23);
  turnangle(180,180,0.3,E24);
  turnangle(135,180,0.3,F25);
  turnangle(180,180,0.3,F26);
  delay(300);

  //step 2
  turnangle(180,180,0.5,A12);
  turnangle(135,180,0.5,A13);
  turnangle(180,180,0.5,B14);
  turnangle(180,180,0.5,B15);
  turnangle(240,240,0.5,C16);
  turnangle(180,135,0.5,C17);
  turnangle(120,120,0.5,D21);
  turnangle(130,130,0.5,D22);
  turnangle(235,270,0.5,E23);
  turnangle(180,180,0.5,E24);
  turnangle(180,180,0.5,F25);
  turnangle(180,135,0.5,F26);
  delay(300);

  //step 3
  turnangle(180,180,0.3,A12);
  turnangle(180,180,0.3,A13);
  turnangle(180,230,0.3,B14);
  turnangle(180,120,0.3,B15);
  turnangle(240,180,0.3,C16);
  turnangle(135,135,0.3,C17);
  turnangle(120,180,0.3,D21);
  turnangle(130,180,0.3,D22);
  turnangle(270,270,0.3,E23);
  turnangle(180,180,0.3,E24);
  turnangle(180,140,0.3,F25);
  turnangle(135,135,0.3,F26);
  delay(300);

  //step 4
  turnangle(180,180,0.5,A12);
  turnangle(180,135,0.5,A13);
  turnangle(230,225,0.5,B14);
  turnangle(120,125,0.5,B15);
  turnangle(180,180,0.5,C16);
  turnangle(135,180,0.5,C17);
  turnangle(180,180,0.5,D21);
  turnangle(180,180,0.5,D22);
  turnangle(270,225,0.5,E23);
  turnangle(180,180,0.5,E24);
  turnangle(140,135,0.5,F25);
  turnangle(135,180,0.5,F26);
  delay(300);
}

void movebackward(){
  g15.exitWheelMode(A12);
  g15.exitWheelMode(A13);
  g15.exitWheelMode(B14);
  g15.exitWheelMode(B15);
  g15.exitWheelMode(C16);
  g15.exitWheelMode(C17);
  g15.exitWheelMode(D21);
  g15.exitWheelMode(D22);
  g15.exitWheelMode(E23);
  g15.exitWheelMode(E24);
  g15.exitWheelMode(F25);
  g15.exitWheelMode(F26);

  //step 1
  turnangle(180,180,0.3,A12);
  turnangle(135,135,0.3,A13);
  turnangle(180,225,0.3,B14);
  turnangle(180,125,0.3,B15);
  turnangle(240,180,0.3,C16);
  turnangle(180,180,0.3,C17);
  turnangle(120,180,0.3,D21);
  turnangle(130,180,0.3,D22);
  turnangle(235,225,0.3,E23);
  turnangle(180,180,0.3,E24);
  turnangle(180,135,0.3,F25);
  turnangle(180,180,0.3,F26);
  delay(300);

  //step 2
  turnangle(180,180,0.5,A12);
  turnangle(135,180,0.5,A13);
  turnangle(225,230,0.5,B14);
  turnangle(125,120,0.5,B15);
  turnangle(180,180,0.5,C16);
  turnangle(180,135,0.5,C17);
  turnangle(180,180,0.5,D21);
  turnangle(180,180,0.5,D22);
  turnangle(225,270,0.5,E23);
  turnangle(180,180,0.5,E24);
  turnangle(135,130,0.5,F25);
  turnangle(180,135,0.5,F26);
  delay(300);

  //step 3
  turnangle(180,180,0.3,A12);
  turnangle(180,180,0.3,A13);
  turnangle(230,180,0.3,B14);
  turnangle(120,180,0.3,B15);
  turnangle(180,240,0.3,C16);
  turnangle(135,135,0.3,C17);
  turnangle(180,120,0.3,D21);
  turnangle(180,130,0.3,D22);
  turnangle(270,270,0.3,E23);
  turnangle(180,180,0.3,E24);
  turnangle(140,180,0.3,F25);
  turnangle(135,135,0.3,F26);
  delay(300);

  //step 4
  turnangle(180,180,0.5,A12);
  turnangle(180,135,0.5,A13);
  turnangle(180,180,0.5,B14);
  turnangle(180,180,0.5,B15);
  turnangle(240,240,0.5,C16);
  turnangle(135,180,0.5,C17);
  turnangle(120,120,0.5,D21);
  turnangle(130,130,0.5,D22);
  turnangle(270,235,0.5,E23);
  turnangle(180,180,0.5,E24);
  turnangle(180,180,0.5,F25);
  turnangle(135,180,0.5,F26);
  delay(300);
}

void turnleft(){
  g15.exitWheelMode(A12);
  g15.exitWheelMode(A13);
  g15.exitWheelMode(B14);
  g15.exitWheelMode(B15);
  g15.exitWheelMode(C16);
  g15.exitWheelMode(C17);
  g15.exitWheelMode(D21);
  g15.exitWheelMode(D22);
  g15.exitWheelMode(E23);
  g15.exitWheelMode(E24);
  g15.exitWheelMode(F25);
  g15.exitWheelMode(F26);

  //step 1
  turnangle(225,180,0.5,A12);
  turnangle(180,135,0.5,A13);
  turnangle(225,235,0.5,B14);
  turnangle(120,120,0.5,B15);
  turnangle(225,180,0.5,C16);
  turnangle(135,90,0.5,C17);
  turnangle(120,180,0.5,D21);
  turnangle(135,180,0.5,D22);
  turnangle(225,270,0.5,E23);
  turnangle(180,225,0.5,E24);
  turnangle(135,135,0.5,F25);
  turnangle(90,135,0.5,F26);
  delay(500);

  //step 2
  turnangle(180,180,0.2,A12);
  turnangle(135,135,0.2,A13);
  turnangle(235,235,0.2,B14);
  turnangle(120,120,0.2,B15);
  turnangle(180,225,0.2,C16);
  turnangle(90,90,0.2,C17);
  turnangle(180,120,0.2,D21);
  turnangle(180,135,0.2,D22);
  turnangle(270,270,0.2,E23);
  turnangle(225,225,0.2,E24);
  turnangle(135,135,0.2,F25);
  turnangle(135,135,0.2,F26);
  delay(200);

  //step 3
  turnangle(180,225,0.5,A12);
  turnangle(135,180,0.5,A13);
  turnangle(235,180,0.5,B14);
  turnangle(120,180,0.5,B15);
  turnangle(225,225,0.5,C16);
  turnangle(90,135,0.5,C17);
  turnangle(120,120,0.5,D21);
  turnangle(135,135,0.5,D22);
  turnangle(270,225,0.5,E23);
  turnangle(225,180,0.5,E24);
  turnangle(135,180,0.5,F25);
  turnangle(135,90,0.5,F26);
  delay(500);

  //step 4
  turnangle(225,225,0.2,A12);
  turnangle(180,180,0.2,A13);
  turnangle(180,225,0.2,B14);
  turnangle(180,120,0.2,B15);
  turnangle(225,225,0.2,C16);
  turnangle(135,135,0.2,C17);
  turnangle(120,120,0.2,D21);
  turnangle(135,135,0.2,D22);
  turnangle(225,225,0.2,E23);
  turnangle(180,180,0.2,E24);
  turnangle(180,135,0.2,F25);
  turnangle(90,90,0.2,F26);
  delay(200);
}

void turnright(){
  g15.exitWheelMode(A12);
  g15.exitWheelMode(A13);
  g15.exitWheelMode(B14);
  g15.exitWheelMode(B15);
  g15.exitWheelMode(C16);
  g15.exitWheelMode(C17);
  g15.exitWheelMode(D21);
  g15.exitWheelMode(D22);
  g15.exitWheelMode(E23);
  g15.exitWheelMode(E24);
  g15.exitWheelMode(F25);
  g15.exitWheelMode(F26);

  //step 1
  turnangle(180,225,0.5,A12);
  turnangle(135,180,0.5,A13);
  turnangle(235,225,0.5,B14);
  turnangle(120,120,0.5,B15);
  turnangle(180,225,0.5,C16);
  turnangle(90,135,0.5,C17);
  turnangle(180,120,0.5,D21);
  turnangle(180,135,0.5,D22);
  turnangle(270,225,0.5,E23);
  turnangle(225,180,0.5,E24);
  turnangle(135,135,0.5,F25);
  turnangle(135,90,0.5,F26);
  delay(500);

  //step 2
  turnangle(225,225,0.2,A12);
  turnangle(180,180,0.2,A13);
  turnangle(225,180,0.2,B14);
  turnangle(120,180,0.2,B15);
  turnangle(225,225,0.2,C16);
  turnangle(135,135,0.2,C17);
  turnangle(120,120,0.2,D21);
  turnangle(135,135,0.2,D22);
  turnangle(225,225,0.2,E23);
  turnangle(180,180,0.2,E24);
  turnangle(135,180,0.2,F25);
  turnangle(90,90,0.2,F26);
  delay(200);

  //step 3
  turnangle(225,180,0.5,A12);
  turnangle(180,135,0.5,A13);
  turnangle(180,235,0.5,B14);
  turnangle(180,120,0.5,B15);
  turnangle(225,225,0.5,C16);
  turnangle(135,90,0.5,C17);
  turnangle(120,120,0.5,D21);
  turnangle(135,135,0.5,D22);
  turnangle(225,270,0.5,E23);
  turnangle(180,225,0.5,E24);
  turnangle(180,135,0.5,F25);
  turnangle(90,135,0.5,F26);
  delay(500);

  //step 4
  turnangle(180,180,0.2,A12);
  turnangle(135,135,0.2,A13);
  turnangle(235,235,0.2,B14);
  turnangle(120,120,0.2,B15);
  turnangle(225,180,0.2,C16);
  turnangle(90,90,0.2,C17);
  turnangle(120,180,0.2,D21);
  turnangle(135,180,0.2,D22);
  turnangle(270,270,0.2,E23);
  turnangle(225,225,0.2,E24);
  turnangle(135,135,0.2,F25);
  turnangle(135,135,0.2,F26);
  delay(200);
}

void tiltfront(){
  g15.exitWheelMode(A12);
  g15.exitWheelMode(A13);
  g15.exitWheelMode(B14);
  g15.exitWheelMode(B15);
  g15.exitWheelMode(C16);
  g15.exitWheelMode(C17);
  g15.exitWheelMode(D21);
  g15.exitWheelMode(D22);
  g15.exitWheelMode(E23);
  g15.exitWheelMode(E24);
  g15.exitWheelMode(F25);
  g15.exitWheelMode(F26);

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
  g15.exitWheelMode(A12);
  g15.exitWheelMode(A13);
  g15.exitWheelMode(B14);
  g15.exitWheelMode(B15);
  g15.exitWheelMode(C16);
  g15.exitWheelMode(C17);
  g15.exitWheelMode(D21);
  g15.exitWheelMode(D22);
  g15.exitWheelMode(E23);
  g15.exitWheelMode(E24);
  g15.exitWheelMode(F25);
  g15.exitWheelMode(F26);

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
  g15.exitWheelMode(A12);
  g15.exitWheelMode(A13);
  g15.exitWheelMode(B14);
  g15.exitWheelMode(B15);
  g15.exitWheelMode(C16);
  g15.exitWheelMode(C17);
  g15.exitWheelMode(D21);
  g15.exitWheelMode(D22);
  g15.exitWheelMode(E23);
  g15.exitWheelMode(E24);
  g15.exitWheelMode(F25);
  g15.exitWheelMode(F26);

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
  g15.exitWheelMode(A12);
  g15.exitWheelMode(A13);
  g15.exitWheelMode(B14);
  g15.exitWheelMode(B15);
  g15.exitWheelMode(C16);
  g15.exitWheelMode(C17);
  g15.exitWheelMode(D21);
  g15.exitWheelMode(D22);
  g15.exitWheelMode(E23);
  g15.exitWheelMode(E24);
  g15.exitWheelMode(F25);
  g15.exitWheelMode(F26);

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
  double x = abs((((start-endd)/timee)/378)  * 1023);
  g15.setSpeed(ID,x);
  g15.setPosAngle(ID,endd);
}

void setangle(int ID,int start, int speed){
  g15.setSpeed(ID, speed); // Set G15 (ID = 1) speed to 500,
  g15.setPosAngle(ID, start);
}

void loop() {
  /*
  Serial.print(digitalRead(7));
  Serial.print(digitalRead(6));
  Serial.print(digitalRead(5));
  Serial.print(digitalRead(4));
  Serial.println("");
  */
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