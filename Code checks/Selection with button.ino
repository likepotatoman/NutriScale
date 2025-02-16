#include "SPI.h"
#include "TFT_eSPI.h"

TFT_eSPI tft = TFT_eSPI();

const int Backward_Button_pin = 47;
const int Select_Button_pin = 45;
const int Forward_Button_pin = 43;
int Forward_Button_State = 0; //0 for off and 1 for on
int Backward_Button_State = 0;
int Select_Button_State = 0;
uint32_t bgColor = 0xFF9C;  // Soft Beige
uint32_t btnColor = 0xA61A; // Soft Blue
uint32_t textColor = 0x3186; // Dark Gray
uint32_t highlightColor = TFT_RED; //0xCE7D; //Light Soft Blue
int selection = 1;

void setup() {
  tft.init();
  tft.setRotation(2);
  TFT_home_screen();
  highlight();
  pinMode( Backward_Button_pin, INPUT_PULLUP);
  pinMode( Forward_Button_pin, INPUT_PULLUP);
  pinMode(Select_Button_pin, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  button_check();

}

void button_check() {
  if (Forward_Button_State == 0) {
    if (digitalRead(Forward_Button_pin) == LOW) {
      Forward_Button_State = 1;
      delay(50);
    }
  } else {
    if (digitalRead(Forward_Button_pin) == HIGH) {
      Forward_Button_State = 0;
      delay(50);
      if (selection < 4) { selection++; TFT_home_screen(); highlight();} 
    }
  }

  if (Backward_Button_State == 0) {
    if (digitalRead(Backward_Button_pin) == LOW) {
      Backward_Button_State = 1;
      delay(50);
    }
  } else {
    if (digitalRead(Backward_Button_pin) == HIGH) {
      Backward_Button_State = 0;
      delay(50);
      if (selection > 1) { selection--; TFT_home_screen(); highlight();} 
    }
  }

  if (Select_Button_State == 0) {
    if (digitalRead(Select_Button_pin) == LOW) {
      Select_Button_State = 1;
      delay(50);
    }
  } else {
    if (digitalRead(Select_Button_pin) == HIGH) {
      Select_Button_State = 0;
      delay(50);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN, LOW);
      delay(50);
    }
  }
}


void highlight() {
  if (selection == 1) {
    tft.drawRect(20, 20, 280, 120, highlightColor);
  } else if (selection == 2) {
    tft.drawRect(20, 180, 280, 120, highlightColor);
  } else {
    tft.drawRect(20, 340, 280, 120, highlightColor);
  }
}


void TFT_home_screen() {
  tft.setTextColor(textColor);
  tft.setTextSize(3);

  //background
  tft.fillRect(0, 0, 320, 480, bgColor);
  
  //buttons
    //first button
      tft.fillRect(20, 20, 280, 120, btnColor);
      tft.setCursor(110, 50);
      tft.print("SELECT");
      tft.setCursor(80, 90);
      tft.print("NEW FOODS");

    //second button
      tft.fillRect(20, 180, 280, 120, btnColor);
      tft.setCursor(45, 230);
      tft.print("TODAY'S STATS");

    //third button
      tft.fillRect(20, 340, 280, 120, btnColor);
      tft.setCursor(55, 390);
      tft.print("MEAL HISTORY");
}
