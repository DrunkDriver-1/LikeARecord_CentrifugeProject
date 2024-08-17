const int sigPin = A0;
int magVal = 0;
volatile int Counter = 0;
volatile int rpm = 0;
volatile int GForce = 0;
bool isPulse = true;
const int check = 20;
void setup() {
  // put your setup code here, to run once:
  pinMode(sigPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(magVal);
  magVal = analogRead(sigPin);
  if (magVal >= check && isPulse == true){
    Counter = Counter + 1;
    isPulse = false;
  }
  else{
    isPulse = true;
  }
  Serial.println(Counter);
}
