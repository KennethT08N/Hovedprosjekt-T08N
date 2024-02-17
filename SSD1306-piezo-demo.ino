#include <Adafruit_SSD1306.h>
//#include <Adafruit_SSD1306_EMULATOR.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3D  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//Adafruit_SSD1306_EMULATOR display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();

  display.display();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Testing");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(1000);


  display.clearDisplay();
  display.display();
  delay(200);
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.print("Capacitance: ");
  display.setCursor(0, 10);
  display.print("Left wire: ");
  display.setCursor(0, 20);
  display.print("Right wire: ");
  display.display();
  delay(200);
  display.setCursor(80, 0);
  display.print("OK");
  display.display();
  delay(200);
  display.setCursor(80, 10);
  display.print("OK");
  display.display();
  delay(200);
  display.setCursor(80, 20);
  display.print("OK");
  display.display();
  delay(5000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Testing");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(1000);


  display.clearDisplay();
  display.display();
  delay(200);
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.print("Capacitance: ");
  display.setCursor(0, 10);
  display.print("Left wire: ");
  display.setCursor(0, 20);
  display.print("Right wire: ");
  display.display();
  delay(200);
  display.setCursor(80, 0);
  display.print("FAIL");
  display.display();
  delay(200);
  display.setCursor(80, 10);
  display.print("OK");
  display.display();
  delay(200);
  display.setCursor(80, 20);
  display.print("FAIL");
  display.display();
  delay(5000);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Testing");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(1000);

  display.clearDisplay();
  display.display();
  delay(200);
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.print("Cap.: ");
  display.setCursor(0, 10);
  display.print("Left wire: ");
  display.setCursor(0, 20);
  display.print("Right wire: ");
  display.display();
  delay(200);
  display.setCursor(67, 0);
  display.print("OK (2.2nF)");
  display.display();
  delay(200);
  display.setCursor(67, 10);
  display.print("OK");
  display.display();
  delay(200);
  display.setCursor(67, 20);
  display.print("OK");
  display.display();
  delay(5000);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Testing");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(1000);

  display.clearDisplay();
  display.display();
  delay(200);
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.print("Cap.: ");
  display.setCursor(0, 10);
  display.print("Left wire: ");
  display.setCursor(0, 20);
  display.print("Right wire: ");
  display.display();
  delay(200);
  display.setCursor(67, 0);
  display.print("FAIL");
  display.display();
  delay(200);
  display.setCursor(67, 10);
  display.print("FAIL");
  display.display();
  delay(200);
  display.setCursor(67, 20);
  display.print("OK");
  display.display();
  delay(5000);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.print("Testing");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(1000);

  display.clearDisplay();
  display.display();
  delay(200);
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.print("Cap.: ");
  display.setCursor(0, 20);
  display.print("L. wire: ");
  display.setCursor(0, 40);
  display.print("R. wire: ");
  display.display();
  delay(200);
  display.setCursor(102, 0);
  display.print("OK");
  display.display();
  delay(200);
  display.setCursor(102, 20);
  display.print("OK");
  display.display();
  delay(200);
  display.setCursor(102, 40);
  display.print("OK");
  display.display();
  delay(5000);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Testing");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(1000);

  display.clearDisplay();
  display.display();
  delay(200);
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.print("Cap.: ");
  display.setCursor(0, 20);
  display.print("L. wire: ");
  display.setCursor(0, 40);
  display.print("R. wire: ");
  display.display();
  delay(200);
  display.setCursor(95, 0);
  display.print("F");
  display.display();
  delay(200);
  display.setCursor(95, 20);
  display.print("F");
  display.display();
  delay(200);
  display.setCursor(95, 40);
  display.print("OK");
  display.display();
  delay(5000);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Testing");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(100);
  display.print(".");
  display.display();
  delay(1000);

  display.clearDisplay();
  display.display();
  delay(200);
  display.setCursor(0, 0);
  display.setTextSize(2);
  display.print("Cap.: ");
  display.setCursor(0, 20);
  display.print("L wire: ");
  display.setCursor(0, 40);
  display.print("R wire: ");
  display.display();
  delay(200);
  display.setCursor(95, 0);
  display.print("F");
  display.display();
  delay(200);
  display.setCursor(95, 20);
  display.print("F");
  display.display();
  delay(200);
  display.setCursor(95, 40);
  display.print("OK");
  display.display();
  delay(5000);
}
