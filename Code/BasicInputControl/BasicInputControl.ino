#define CLK 10  // Interrupt pin for CLK (A)
#define DT 3   // Pin for DT (B)
#define SW 4   // Interrupt pin for SW (Button)

volatile int counter = 0;  // Counter for the number
volatile int lastStateDT = 0;  // To keep track of the last state of DT
volatile bool buttonPressed = false;  // Flag to track button press

void setup() {
  pinMode(CLK, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP);

  Serial.begin(9600);

  // Initialize lastStateDT
  lastStateDT = digitalRead(DT);

  // Attach interrupt to CLK pin (triggers on a change in state)
  attachInterrupt(digitalPinToInterrupt(CLK), updateEncoder, CHANGE);

  // Attach interrupt to SW pin (triggers on button press)
  attachInterrupt(digitalPinToInterrupt(SW), handleButtonPress, FALLING);
}

void loop() {
  // Display the counter value
  Serial.print("Counter: ");
  Serial.println(counter);
  delay(200);  // Just to slow down the serial output for readability

  // Check if the button was pressed
  if (buttonPressed) {
    Serial.println("Button was pressed!");
    buttonPressed = false;  // Reset the flag
  }
}

void updateEncoder() {
  // Read the state of DT
  int currentStateDT = digitalRead(DT);

  // Determine rotation direction
  if (currentStateDT != lastStateDT) {
    if (currentStateDT == HIGH) {
      counter++;
    } else {
      counter--;
    }
  }

  // Update last state of DT
  lastStateDT = currentStateDT;
}

void handleButtonPress() {
  // Set flag to indicate button press
  buttonPressed = true;
  
  // Small delay to debounce button press (if needed)
  delay(50);
}
