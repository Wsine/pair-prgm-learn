/*
Arduino Mega 2560 configuration and working with Adafruit SSD1331 Display Module.
*/

// Include the Adafruit_SSD1331 library at the beginning
#include <Adafruit_SSD1331.h>

// Define the required pins for the SSD1331 display module
#define Sclk 52
#define Mosi 51
#define Rst  44
#define Dc   45
#define Cs   46

// Define the color values to be used in the display
#define BLACK           0x0000
#define BLUE            0x0006
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF
#define BACKGROUND      0x0000

// Create an Adafruit_SSD1331 display instance with the defined pins
Adafruit_SSD1331 display = Adafruit_SSD1331(Cs, Dc, Mosi, Sclk, Rst);

// Declare an int variable named 'counter' and assign the value 0
int counter = 0;

// Define the setup() function, which is executed only once during powerup.
void setup() {
  // Initialize the Serial Monitor with a baud rate of 9600

  // Begin the display and fill the screen with the color BLACK

  // Call the function 'tftPrintTest()' to perform display testing

  // Wait for 2000 milliseconds (2 seconds) before executing the next command

  // Fill the screen with the color BACKGROUND and set the cursor to (0,0)

}

// Define the loop() function, which is called repeatedly during the program execution.
void loop() {
  // Fill the screen with the color BLACK

  // Wait for 250 milliseconds (1/4 second) before executing the next command

  // Fill the screen with the color WHITE

  // Wait for 250 milliseconds (1/4 second) before executing the next command

  // Fill the screen with the color BLACK and set the display text color to WHITE

  // Set the display text size to 2 and set the cursor to (0, 0)

  // Print the incremented 'counter' variable on the display

  // Increment the 'counter' variable

  // Wait for 1500 milliseconds (1.5 seconds) before executing the next command
}

// Define the function 'tftPrintTest()' to perform display testing
void tftPrintTest() {
  // Fill the screen with the color BLACK and set the cursor to (15, 5)

  // Set the display text color to WHITE and set the text size to 2

  // Print the text "HKUEEE" on the display and set the cursor to (0, 25)

  // Set the display text color to CYAN and set the text size to 2

  // Print the text "IDP" on the display and set the cursor to (15, 50)
  
  // Set the display text color to YELLOW and set the text size to 2

  // Print the text "OLED" on the display and wait for 1500 milliseconds (1.5 seconds)
}
