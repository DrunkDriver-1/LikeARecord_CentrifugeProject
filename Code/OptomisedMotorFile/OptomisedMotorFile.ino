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
	speedControl();
	delay(1000);
}
void speedControl() {
	// Turn on motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	
	// Accelerate from zero to maximum speed
	for (int i = 105; i < 256; i++) {
		analogWrite(enA, i);
		delay(25);
	}
	analogWrite(enA,0);
	// Decelerate from maximum speed to zero
	for (int i = 255; i >= 105; --i) {
		analogWrite(enA, i);
		delay(25);
	}
 
  	// Now turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}
