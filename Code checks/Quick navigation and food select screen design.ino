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
uint32_t txtboxColor = 0xD69A; //Muted Blue
uint32_t highlightColor = TFT_RED; //0xCE7D; //Light Soft Blue
int selection_index = 1;
char screen_phase = 'H';

void setup() {
  tft.init();
  tft.setRotation(2);
  TFT_home_screen();
  TFT_border_highlight();
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
      process_forward_button_press();
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
      process_backward_button_press();
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
      process_select_button_press();
    }
  }
}

void process_forward_button_press() {
  if (screen_phase  == 'H') {if (selection_index < 3) {selection_index++;}}
  else if (screen_phase == 'S') {if (selection_index < 33) {selection_index++;}}

  TFT_refresh();
}

void process_backward_button_press() { 
  if (selection_index > 1) {selection_index--;}

  TFT_refresh();
}

void process_select_button_press() { 
  if (screen_phase == 'H') {
    if (selection_index == 1) {screen_phase = 'S';}
  }

  selection_index = 1;
  TFT_refresh();
}

void TFT_border_highlight() {
  if (screen_phase == 'H') {
    if (selection_index == 1) {tft.drawRect(20, 20, 280, 120, highlightColor);} 
    else if (selection_index == 2) {tft.drawRect(20, 180, 280, 120, highlightColor);} 
    else if (selection_index == 3) {tft.drawRect(20, 340, 280, 120, highlightColor);}

  } else if (screen_phase == 'S') {
    if (selection_index == 1) { tft.drawRect(5, 5, 80, 30, highlightColor); }
    else if (selection_index == 2) { tft.drawRect(43, 110, 30, 30, highlightColor); }
    else if (selection_index == 3) { tft.drawRect(77, 110, 30, 30, highlightColor); }
    else if (selection_index == 4) { tft.drawRect(111, 110, 30, 30, highlightColor); }
    else if (selection_index == 5) { tft.drawRect(145, 110, 30, 30, highlightColor); }
    else if (selection_index == 6) { tft.drawRect(179, 110, 30, 30, highlightColor); }
    else if (selection_index == 7) { tft.drawRect(213, 110, 30, 30, highlightColor); }
    else if (selection_index == 8) { tft.drawRect(247, 110, 30, 30, highlightColor); }
    else if (selection_index == 9) { tft.drawRect(43, 144, 30, 30, highlightColor); }
    else if (selection_index == 10) { tft.drawRect(77, 144, 30, 30, highlightColor); }
    else if (selection_index == 11) { tft.drawRect(111, 144, 30, 30, highlightColor); }
    else if (selection_index == 12) { tft.drawRect(145, 144, 30, 30, highlightColor); }
    else if (selection_index == 13) { tft.drawRect(179, 144, 30, 30, highlightColor); }
    else if (selection_index == 14) { tft.drawRect(213, 144, 30, 30, highlightColor); }
    else if (selection_index == 15) { tft.drawRect(247, 144, 30, 30, highlightColor); }
    else if (selection_index == 16) { tft.drawRect(43, 178, 30, 30, highlightColor); }
    else if (selection_index == 17) { tft.drawRect(77, 178, 30, 30, highlightColor); }
    else if (selection_index == 18) { tft.drawRect(111, 178, 30, 30, highlightColor); }
    else if (selection_index == 19) { tft.drawRect(145, 178, 30, 30, highlightColor); }
    else if (selection_index == 20) { tft.drawRect(179, 178, 30, 30, highlightColor); }
    else if (selection_index == 21) { tft.drawRect(213, 178, 30, 30, highlightColor); }
    else if (selection_index == 22) { tft.drawRect(247, 178, 30, 30, highlightColor); }
    else if (selection_index == 23) { tft.drawRect(43, 212, 30, 30, highlightColor); }
    else if (selection_index == 24) { tft.drawRect(77, 212, 30, 30, highlightColor); }
    else if (selection_index == 25) { tft.drawRect(111, 212, 30, 30, highlightColor); }
    else if (selection_index == 26) { tft.drawRect(145, 212, 30, 30, highlightColor); }
    else if (selection_index == 27) { tft.drawRect(179, 212, 30, 30, highlightColor); }
    else if (selection_index == 28) { tft.drawRect(213, 212, 30, 30, highlightColor); }
    else if (selection_index == 29) { tft.drawRect(247, 212, 30, 30, highlightColor); }
    else if (selection_index == 30) { tft.drawRect(20, 270, 280, 40, highlightColor); }
    else if (selection_index == 31) { tft.drawRect(20, 320, 280, 40, highlightColor); }
    else if (selection_index == 32) { tft.drawRect(20, 370, 280, 40, highlightColor); }
    else if (selection_index == 33) { tft.drawRect(20, 420, 280, 40, highlightColor); }
  }
}

void TFT_refresh() {
  if (screen_phase == 'H') {TFT_home_screen();}
  else if (screen_phase == 'S') {TFT_food_select();}

  TFT_border_highlight();
}

void TFT_food_select() {
  tft.setTextColor(textColor);
  tft.setTextSize(3);

  //background
    tft.fillRect(0, 0, 320, 480, bgColor);

  //text box
    tft.fillRect(20, 50, 280, 50, txtboxColor);

  //buttons
    //back button
      tft.fillRect(5, 5, 80, 30, btnColor);
      tft.setCursor(9, 10);
      tft.print("BACK");
    
    // Key board
      // A - G
        tft.fillRect(43, 110, 30, 30, btnColor);
        tft.setCursor(51, 115);
        tft.print('A');
        
        tft.fillRect(77, 110, 30, 30, btnColor);
        tft.setCursor(85, 115);
        tft.print('B');
        
        tft.fillRect(111, 110, 30, 30, btnColor);
        tft.setCursor(119, 115);
        tft.print('C');
        
        tft.fillRect(145, 110, 30, 30, btnColor);
        tft.setCursor(153, 115);
        tft.print('D');
        
        tft.fillRect(179, 110, 30, 30, btnColor);
        tft.setCursor(187, 115);
        tft.print('E');
        
        tft.fillRect(213, 110, 30, 30, btnColor);
        tft.setCursor(221, 115);
        tft.print('F');
        
        tft.fillRect(247, 110, 30, 30, btnColor);
        tft.setCursor(255, 115);
        tft.print('G');
      
 
      // H - N
        tft.fillRect(43, 144, 30, 30, btnColor);
        tft.setCursor(51, 149);
        tft.print('H');
        
        tft.fillRect(77, 144, 30, 30, btnColor);
        tft.setCursor(85, 149);
        tft.print('I');
        
        tft.fillRect(111, 144, 30, 30, btnColor);
        tft.setCursor(119, 149);
        tft.print('J');
        
        tft.fillRect(145, 144, 30, 30, btnColor);
        tft.setCursor(153, 149);
        tft.print('K');
        
        tft.fillRect(179, 144, 30, 30, btnColor);
        tft.setCursor(187, 149);
        tft.print('L');
        
        tft.fillRect(213, 144, 30, 30, btnColor);
        tft.setCursor(221, 149);
        tft.print('M');
        
        tft.fillRect(247, 144, 30, 30, btnColor);
        tft.setCursor(255, 149);
        tft.print('N');
      
      // O - U
        tft.fillRect(43, 178, 30, 30, btnColor);
        tft.setCursor(51, 183);
        tft.print('O');
        
        tft.fillRect(77, 178, 30, 30, btnColor);
        tft.setCursor(85, 183);
        tft.print('P');
        
        tft.fillRect(111, 178, 30, 30, btnColor);
        tft.setCursor(119, 183);
        tft.print('Q');
        
        tft.fillRect(145, 178, 30, 30, btnColor);
        tft.setCursor(153, 183);
        tft.print('R');
        
        tft.fillRect(179, 178, 30, 30, btnColor);
        tft.setCursor(187, 183);
        tft.print('S');
        
        tft.fillRect(213, 178, 30, 30, btnColor);
        tft.setCursor(221, 183);
        tft.print('T');
        
        tft.fillRect(247, 178, 30, 30, btnColor);
        tft.setCursor(255, 183);
        tft.print('U');
      
      // V - Z + Extra keys
        tft.fillRect(43, 212, 30, 30, btnColor);
        tft.setCursor(51, 217);
        tft.print('V');
        
        tft.fillRect(77, 212, 30, 30, btnColor);
        tft.setCursor(85, 217);
        tft.print('W');
        
        tft.fillRect(111, 212, 30, 30, btnColor);
        tft.setCursor(119, 217);
        tft.print('X');
        
        tft.fillRect(145, 212, 30, 30, btnColor);
        tft.setCursor(153, 217);
        tft.print('Y');
        
        tft.fillRect(179, 212, 30, 30, btnColor);
        tft.setCursor(187, 217);
        tft.print('Z');
      
        tft.fillRect(213, 212, 30, 30, btnColor);
        tft.setCursor(221, 217);
        tft.print('<');
        
        tft.fillRect(247, 212, 30, 30, btnColor);
        tft.setCursor(255, 217);
        tft.print('>');

    //food options
      //food 1
       tft.fillRect(20, 270, 280, 40, btnColor);
       //food 2
       tft.fillRect(20, 320, 280, 40, btnColor);
       //food 3
       tft.fillRect(20, 370, 280, 40, btnColor);
       //food 4
       tft.fillRect(20, 420, 280, 40, btnColor);

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
