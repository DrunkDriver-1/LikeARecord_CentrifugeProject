#define CLK 10     // Pin for the encoder CLK (A)
#define DT 11      // Pin for the encoder DT (B)
#define SW 12      // Pin for the encoder SW (Button)

int counter = 0;   // Counter for the rotary encoder
int lastStateCLK;  // To store the previous state of CLK
int currentStateCLK; // To store the current state of CLK
int buttonState;   // To store the state of the button
int lastButtonState = HIGH; // Last state of the button (HIGH by default if not pressed)
int increment = 25
void setup() {
  // Set encoder pins as inputs
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP); // Use the internal pull-up resistor for the button

  // Read the initial state of CLK
  lastStateCLK = digitalRead(CLK);

  // Initialize the serial monitor
  Serial.begin(9600);
}

void loop() {
  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK);

  // If the previous and the current state of CLK are different, that means the encoder is rotating
  if (currentStateCLK != lastStateCLK) {
    // If the DT state is different than the CLK state, then the encoder is rotating clockwise
    if (digitalRead(DT) != currentStateCLK) {
      counter = counter + increment;
    } else {
      counter = counter - increment;
    }

    // Print the counter value
    Serial.print("Counter: ");
    Serial.println(counter);
  }

  // Update lastStateCLK with the current state
  lastStateCLK = currentStateCLK;

  // Read the button state
  buttonState = digitalRead(SW);

  // If the button was pressed (goes from HIGH to LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    Serial.println("Button pressed!");
    // Perform any action you want when the button is pressed
  }

  // Update the last button state
  lastButtonState = buttonState;
}
