const int sigPin = A0;
int magVal = 0;
volatile int Counter = 0;
volatile int rpm = 0;
volatile int GForce = 0;
bool isPulse = true;
const int check = 20;
int timmer = 0;
int rotorRad = 20;
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
    Counter ++ ;
    isPulse = false;
    timeCheck();
  }
  else{
    isPulse = true;
    timeCheck();
  }
  Serial.println(Counter);
};
void timeCheck(){
  timmer ++;
  if (timmer >= 19200){
    rpm = Counter * 30;
    GForce = 11.2 * rotorRad * pow((rpm/1000),2);
    Serial.println('the rpm of the rotor is currently ');
    Serial.print(rpm);
    Serial.println('and the RCF is ');
    Serial.print(GForce);
    Serial.print(' G');
    Counter = 0;
    timmer = 0;
  }
}