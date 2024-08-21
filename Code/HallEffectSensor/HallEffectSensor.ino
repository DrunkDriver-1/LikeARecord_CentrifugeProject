const int sigPin = 6;
int magVal = 0;
float Counter = 1;
float rpm = 1;
volatile int GForce = 0;
bool isPulse = true;
const int check = 20;
int timmer = 0;
int rotorRad = 20;


void setup() {
  // put your setup code here, to run once:
  pinMode(sigPin, INPUT);
  Serial.begin(9600);
  Serial.println("ok its started now");
}


void timeCheck(){
  //timmer ++;
  timmer = timmer +1;
  if (timmer >= 19200) {
    rpm = Counter * 30;
    GForce = 11.2 * rotorRad * pow((rpm/1000),2);
    Serial.print("the rpm of the rotor is currently ");
    Serial.println(rpm);
    Serial.print("and the RCF is ");
    Serial.print(GForce);
    Serial.println(" G");
    Counter = 0;
    timmer = 0;
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(magVal);
  
 // magVal = analogRead(sigPin);
  magVal = digitalRead(sigPin);
  timeCheck();
  if (magVal == HIGH && isPulse == true){
//   if (magVal >= check && isPulse == true){
    Counter ++ ;
    isPulse = false;
  }
  else{
    isPulse = true;
  }
  //Serial.println(Counter);
}
