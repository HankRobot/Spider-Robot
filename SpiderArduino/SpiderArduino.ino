#include <WiFi.h>
#include <WiFiUdp.h>

int incomingByte = 0;
int in1 = 26;//d1
int in2 = 25;//d2
int in3 = 17;//d3
int in4 = 16;//d4
int wifiled = 27;
//wifi stuff
const char* ssid     = "HankBot"; // wifi network name
const char* password = "56111899"; // wifi network password
IPAddress ip(192, 168, 137, 20); //set static ip 192.168.137.20
IPAddress gateway(192, 168, 137, 1); //set getteway....
IPAddress subnet(255, 255, 255, 0);//set subnet

WiFiUDP Udp;
unsigned int localUdpPort = 1998;
char incomingPacket[255];

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(wifiled, OUTPUT);

  Serial.begin(115200);
  delay(10);
  Serial.println("Motor test!");

  // We start by connecting to a WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.config(ip,gateway,subnet);  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Starting UDP");
  Udp.begin(localUdpPort);
  digitalWrite(wifiled,HIGH);
  
}

void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void forward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void backward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void tiltleft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void tiltright() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void tiltfront() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void tiltback() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void ListenPacketRoutine() {
  //listen for packets
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    int len = Udp.read(incomingPacket, 255);
    Serial.printf("UDP packet contents: %s\n", incomingPacket);
    if (incomingPacket[0] == 'f') {
      forward();
    } else if (incomingPacket[0] == 'b') {
      backward();
    } else if (incomingPacket[0] == 'l') {
      left();
    } else if (incomingPacket[0] == 'r') {
      right();
    } else if (incomingPacket[0] == 's') {
      stop();
    } else if (incomingPacket[0] == 'w') {
      tiltfront();
    } else if (incomingPacket[0] == 'x') {
      tiltback();
    } else if (incomingPacket[0] == 'a') {
      tiltleft();
    } else if (incomingPacket[0] == 'd') {
      tiltright();
    }
  }
}

void ListenKeyboardRoutine() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
  }

  switch (incomingByte) {
    case 's': {
        stop();
        Serial.println("Stop\n");
        incomingByte = '*';
      }
      break;

    case 'f': {
        forward();

        Serial.println("Forward\n");
        incomingByte = '*';
      }
      break;

    case 'b':
      { backward();

        Serial.println("Backward\n");
        incomingByte = '*';
      }
      break;

    case 'r':
      {
        right();
        Serial.println("Rotate Right\n");
        incomingByte = '*';
      }
      break;

    case 'l':
      {
        left();
        Serial.println("Rotate Left\n");
        incomingByte = '*';
      }
      break;

    case 'w':
      {
        tiltfront();
        Serial.println("Tilt Front\n");
        incomingByte = '*';
      }
      break;

    case 'x':
      {
        tiltback();
        Serial.println("Tilt Back\n");
        incomingByte = '*';
      }
      break;  

    case 'a':
      {
        tiltleft();
        Serial.println("Tilt Left\n");
        incomingByte = '*';
      }
      break;

    case 'd':
      {
        tiltright();
        Serial.println("Tilt Right\n");
        incomingByte = '*';
      }
      break;
  }
}

void test(){
  left();
  delay(1000);
  right();
  delay(1000);
  forward();
  delay(1000);
  backward();
  delay(1000);
  tiltleft();
  delay(1000);
  tiltright();
  delay(1000);
  tiltfront();
  delay(1000);
  tiltback();
  delay(1000);
  stop();
  delay(1000);
}

void loop()
{
  ListenPacketRoutine();
  ListenKeyboardRoutine();
}
