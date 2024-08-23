volatile unsigned int pulseCount = 0;
unsigned long previousMillis = 0;
const long interval = 1000; // 1 second interval
float rpm = 0;
float rcf = 0;
int rotorRad = 20;
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);  // Hall effect sensor connected to pin 2
  attachInterrupt(digitalPinToInterrupt(2), countPulse, FALLING);  // Interrupt on falling edge
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    // Calculate RPM (pulseCount / number of magnets) * (60000 / interval)
    rpm = (pulseCount / 1.0) * (60000 / interval); // Assuming 1 magnet
    Serial.print("RPM: ");
    Serial.println(rpm);
    rcf = 11.2 * rotorRad * pow((rpm/1000),2);
    Serial.print("RCF: ");
    Serial.println(rcf);
    pulseCount = 0;  // Reset pulse count
  }
}

void countPulse() {
  pulseCount++;
}
