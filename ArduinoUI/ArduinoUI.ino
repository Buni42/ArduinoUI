#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Keypad.h>

// oled display

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3c ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// keypad

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 



void setup() {
  Serial.begin(115200);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  setMenu();

}

void loop(){
  // get and prints pressed key from keypad
  char customKey = customKeypad.getKey();
  int inputs[4];
  
  if (customKey){
    for (int i=0; i <= 4; i++){
      inputs[i] = customKey;
  }
      Serial.println(customKey);
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(62, 38);
      display.println(customKey);
      display.display();
      display.invertDisplay(true);
      delay(500);
      display.clearDisplay();
      setMenu();
  }
}

void setMenu(){  //works but not good enough for me
  display.dim(false);
  setContrast(&display, 255);
  display.invertDisplay(false);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(25, 25);
  // Display static text
  int randoms[4];
  randomSeed(analogRead(0));
  for (int i=0; i <= 3; i++){
    randoms[i] = random(0, 10);
    display.print(randoms[i]);
  }
  
  display.drawRect(0, 0, 128, 64, WHITE);
  //display.fillRect(0, 0, 20, 64, WHITE);
  //display.fillRect(108, 0, 20, 64, WHITE);
  display.drawRect(20, 20, 87, 24, BLACK);
  display.display();
}

void setContrast(Adafruit_SSD1306* display, uint8_t contrast)
{
    display->ssd1306_command(SSD1306_SETCONTRAST);
    display->ssd1306_command(contrast);
}
