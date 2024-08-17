int enA = 9;
int in1 = 8;
int in2 = 7;

void setup() {
	// Set all the motor control pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}

	void loop() {
  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	analogWrite(enA,105);

	delay(1000);
}