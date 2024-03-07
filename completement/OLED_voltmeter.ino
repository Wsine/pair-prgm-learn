#include <Adafruit_SSD1331.h>

#define sclk 13
#define mosi 11
#define rst  9
#define dc   8
#define cs   10

#define BLACK           0x0000
#define BACKGROUND      0x0000

Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, mosi, sclk, rst);

int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
int value = 0;

void setup()
{
  Serial.begin(9600);
  display.begin();
  display.fillScreen(BLACK);
  tftPrintTest();
  delay(2000);
  display.fillScreen(BACKGROUND);
  display.setCursor(0, 0);
}

void loop() {
  value = analogRead(analogInput);
  vout = (value * 5.0) / 1024.0;
  vin = vout / (0.0926);
  
  if (vin < 0.01) {
    vin = 0.01; // remove undesired reading
  }
  
  display.fillScreen(BLACK);
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("INPUT V = ");
  display.print(vin);
  delay(500);
}

void tftPrintTest() {
  display.fillScreen(BLACK);
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("INPUT V = ");
  display.println("Ready to measure");
  delay(500);
}
