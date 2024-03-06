// Include the Adafruit_SSD1331 library

#include <Adafruit_SSD1331.h>

// Define pin connections for the display module
#define sclk 13
#define mosi 11
#define rst  9
#define dc   8
#define cs   10

// Define color constants
#define BLACK           0x0000
#define BLUE            0x0006
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF
#define BACKGROUND      0x0000

// Create display object
Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, mosi, sclk, rst);

// Declare variables for storing input voltage information
int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
int value = 0;

void setup()
{
  // Initialize serial communication at a baud rate of 9600
  // Hint: Use the Serial.begin() function with the argument 9600.
  
  // Initialize the display and clear the screen with color BLACK
  
  // Call the tftPrintTest() function
  
  // Wait for 2000 milliseconds (2 seconds) before executing the next command
  
  // Fill the display screen with color BACKGROUND (custom)
  
  // Set the cursor position at the top-left corner of the display
}

void loop() {
  
  // Read the analog input value at pin 'analogInput'
  // Hint: Use the analogRead() function with the argument analogInput.
  
  // Calculate the input voltage (vin) from the read value using the map() function
  
  // Remove undesired reading from vin if vin is less than 0.01
  
  // Fill the display screen with color BLACK
  
  // Set the cursor position on the display and configure text properties
  
  // Display text on the screen
  
  // Display the measured voltage value (vin) on the display
  
  // Wait for 500 milliseconds (0.5 seconds) before updating the display
}

void tftPrintTest() {
  // Fill the display screen with color BLACK
  // Set the cursor position and text properties on the display
  
  // Display the text "INPUT V = " on the screen
  
  // Set the cursor position below the previous text on the screen
  
  // Display the text "Ready to measure" on the screen
  // Wait for 500 milliseconds (0.5 seconds) before returning from the function
}
