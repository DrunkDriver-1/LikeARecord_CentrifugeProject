<<<<<<< Updated upstream
=======
#define CLK 10     // Pin for the encoder CLK (A)
#define DT 11      // Pin for the encoder DT (B)
#define SW 12      // Pin for the encoder SW (Button)

int counter = 0;   // Counter for the rotary encoder
int lastStateCLK;  // To store the previous state of CLK
int currentStateCLK; // To store the current state of CLK
int buttonState;   // To store the state of the button
int lastButtonState = HIGH; // Last state of the button (HIGH by default if not pressed)
int increment = 25 // increases or decreases the target RCF in increments of this number
>>>>>>> Stashed changes
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
