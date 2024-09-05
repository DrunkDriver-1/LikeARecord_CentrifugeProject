// libary inclusion
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define CLK 10     // Pin for the encoder CLK (A)
#define DT 11      // Pin for the encoder DT (B)
#define SW 12      // Pin for the encoder SW (Button)

LiquidCrystal_I2C lcd(0x27, 16, 2);
int lastStateCLK;  // To store the previous state of CLK
int currentStateCLK; // To store the current state of CLK
int buttonState;   // To store the state of the button
int lastButtonState = HIGH; // Last state of the button (HIGH by default if not pressed)
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
  lcd.init();  // Use lcd.init() instead of lcd.begin()
  lcd.backlight();  // Turn on the backlight
  // Read the initial state of CLK
  lastStateCLK = digitalRead(CLK);

  // Initialize the serial monitor
  Serial.begin(9600);
}

void loop() {
  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK);

  // If the previous and the current state of CLK are different, that means the encoder is rotating
  if (currentStateCLK != lastStateCLK && CountState == 1)  {
    // If the DT state is different than the CLK state, then the encoder is rotating clockwise
    if (digitalRead(DT) != currentStateCLK) {
      RCF = RCF + increment;
    } else {
      RCF = RCF - increment;
    }

    // Print the counter value
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("RCF:");
    lcd.setCursor(5, 0);
    lcd.print(RCF);


    //Serial.print("RCF: ");
    //Serial.println(RCF);
  }
if (currentStateCLK != lastStateCLK && CountState == 2)  {
    // If the DT state is different than the CLK state, then the encoder is rotating clockwise
    if (digitalRead(DT) != currentStateCLK) {
      period = period + increment2;
    } else {
      period = period - increment2;
    }

    // Print the counter value
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("period:");
    lcd.setCursor(8, 0);
    lcd.print(period);
    //Serial.print("Period(minutes): ");
    //Serial.println(period);
  }
  if (CountState ==3){
    // Serial.print("Desired RCF: ");
    // Serial.println(RCF);
    // Serial.print("desired period of time: ");
    // Serial.println(period);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("period:");
    lcd.setCursor(8, 0);
    lcd.print(period);
    lcd.setCursor(0, 1);
    lcd.print("RCF:");
    lcd.setCursor(5, 1);
    lcd.print(RCF);
    delay(4000);
    // Serial.println();
    // Serial.println("press button again to confirm");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("press button");
    lcd.setCursor(0, 1);
    lcd.print("to confirm");
    CountState = CountState +1;
    delay(1000);
  }
  if (CountState == 5){
    //Serial.println("confirmed");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("confirmed");
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
