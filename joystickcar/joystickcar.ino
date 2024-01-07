#define L1 5     //Left Motor MB2
#define L2 6     //Left Motor MB1
#define R1 7     //Right Motor MA1
#define R2 8     //Right Motor MA2
#define enaL 9   //Left Motor Enable Pin EB
#define enaR 10  //Right Motor Enable Pin EA
#define Xaxis_pin A0
#define Yaxis_pin A1 
#define SW_pin A2

//*************************************************//

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(enaR, OUTPUT);
  pinMode(enaL, OUTPUT);

}


int x, y;

void sensorRead() {
  x = analogRead(Xaxis_pin);
  y = analogRead(Yaxis_pin);
}

void setSpeed(int speed) {
  analogWrite(enaR, speed);
  analogWrite(enaL, speed);
}

void goForward() {
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
}
void goLeft() {
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
}
void goRight() {
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
}
void goStop() {
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
}

void loop() {
  sensorRead();
  setSpeed(85);

  if(x==0 && (y>=0 && y<=1023))
  {
    goForward();
  }

  if(y==1023 && (x>=0 && x<=1023))
  {
    goLeft();
  }

  if(y==0 && (x>=0 && x<=1023))
  {
    goRight();
  }

  if(x==1023 && (y>=0 && y<=1023))
  {
    goStop();
  }

  
}