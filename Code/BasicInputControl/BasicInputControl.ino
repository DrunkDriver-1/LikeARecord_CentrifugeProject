<<<<<<< Updated upstream
=======
#define CLK 10     // Pin for the encoder CLK (A)
#define DT 11      // Pin for the encoder DT (B)
#define SW 12      // Pin for the encoder SW (Button)


int lastStateCLK;  // To store the previous state of CLK
int currentStateCLK; // To store the current state of CLK
int buttonState;   // To store the state of the button
int lastButtonState = HIGH; // Last state of the button (HIGH by default if not pressed)
<<<<<<< Updated upstream
int increment = 25 // increases or decreases the target RCF in increments of this number
>>>>>>> Stashed changes
void setup() {
  // put your setup code here, to run once:
=======
int increment = 25;
int RCF = 0;
int period = 0;
int CountState = 1;
int increment2 = 1;
void setup()
 {
  // Set encoder pins as inputs
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP); // Use the internal pull-up resistor for the button
>>>>>>> Stashed changes

}

void loop() {
  // put your main code here, to run repeatedly:

<<<<<<< Updated upstream
}
=======
  // If the previous and the current state of CLK are different, that means the encoder is rotating
  if (currentStateCLK != lastStateCLK && CountState == 1)  {
    // If the DT state is different than the CLK state, then the encoder is rotating clockwise
    if (digitalRead(DT) != currentStateCLK) {
      RCF = RCF + increment;
    } else {
      RCF = RCF - increment;
    }

    // Print the counter value
    Serial.print("RCF: ");
    Serial.println(RCF);
  }
if (currentStateCLK != lastStateCLK && CountState == 2)  {
    // If the DT state is different than the CLK state, then the encoder is rotating clockwise
    if (digitalRead(DT) != currentStateCLK) {
      period = period + increment2;
    } else {
      period = period - increment2;
    }

    // Print the counter value
    Serial.print("Period(minutes): ");
    Serial.println(period);
  }
  if (CountState ==3){
    Serial.print("Desired RCF: ");
    Serial.println(RCF);
    Serial.print("desired period of time: ");
    Serial.println(period);
    delay(2000);
    Serial.println();
    Serial.println("press button again to confirm");
    CountState = CountState +1;
    delay(1000);
  }
  if (CountState == 5){
    Serial.println("confirmed");
    CountState = CountState + 1;
  }
  // Update lastStateCLK with the current state
  lastStateCLK = currentStateCLK;

  // Read the button state
  buttonState = digitalRead(SW);

  // If the button was pressed (goes from HIGH to LOW)
  if (buttonState == LOW && lastButtonState == HIGH && CountState <6) {
    Serial.println("Button pressed!");
    CountState = CountState +1;
    delay(1000);
    // Perform any action you want when the button is pressed
  }

  // Update the last button state
  lastButtonState = buttonState;
}
>>>>>>> Stashed changes
