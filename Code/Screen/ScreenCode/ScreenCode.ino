#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD with I2C address (adjust the address based on the scanner result)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // or use 0x3F if that’s your address

int counter = 0;

void setup() {
  // Start communication with the LCD
  lcd.init();  // Use lcd.init() instead of lcd.begin()
  lcd.backlight();  // Turn on the backlight
}

void loop() {
  // Clear the display
  lcd.clear();
  
  // Set the cursor to the first row, first column
  lcd.setCursor(0, 0);
  
  // Print "Counter:" on the first row
  lcd.print("Counter:");
  
  // Set the cursor to the first row, 9th column (where the counter starts)
  lcd.setCursor(9, 0);
  
  // Print the counter value
  lcd.print(counter);
  
  // Increment the counter
  counter++;
  
  // Delay for 1 second
  delay(1000);
}
