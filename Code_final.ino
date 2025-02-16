// Include all the libraries
#include <4Digits7SegmentsDisplayLibrary.h>
#include <HX711.h>
#include <SD.h>
#include <SPI.h>
#include <TFT_eSPI.h>

// Initialize all the pins
  //4 digit display pins
    const int SegA = 22;
    const int SegB = 24;
    const int SegC = 26;
    const int SegD = 28;
    const int SegE = 30;
    const int SegF = 32;
    const int SegG = 34;
    const int Dig1 = 4;
    const int Dig2 = 3;
    const int Dig3 = 2;
    const int Dig4 = 5;
  //load cell pins
    const int SCK_pin_HX711 = 17;
    const int DOUT_pin = 19;
  //MicroSD module pins
    const int CS_MicroSD = 43;
  //TFT display module pins (Note : no touchscreen)
    const int CS_TFT = ;
    const int RESET_TFT = ;
    const int DC_TFT = ;
  //Button pins
    const int Forward_Button_pin = ;
    const int Backward_Button_pin = ;
    const int Select_Button_pin = ;
  //SPI communication protocol pins
    const int MISO_pin = 50; //Unchangeable
    const int MOSI_pin = 51; //Unchangeable
    const int SCK_pin_SPI = 52; //Unchangeable


// Create an instance of the libraries
  FourDigits7SegmentsDisplayLibrary display(SegA, SegB, SegC, SegD, SegE, SegF, SegG, Dig1, Dig2, Dig3, Dig4); // Pin numbers for segments and digits
  HX711 scale;

//Declaration of global variables
  //Other
    int weight = 1;
    int timer = 0;
  //Food related variables
    bool new_food_selected = true;
    String selected_food = "CORN";
    String selected_food_path = "C/O/R/N/";
    String food_name = "";
    float food_cal = 0;
    float food_protein = 0;
    float food_carbohydrates = 0;
    float food_sugar = 0;
    float food_fat = 0;
    float food_fiber = 0;
    float food_sodium = 0;
    float food_cal_per100g = 0;
    float food_protein_per100g = 0;
    float food_carbohydrates_per100g = 0;
    float food_sugar_per100g = 0;
    float food_fat_per100g = 0;
    float food_fiber_per100g = 0;
    float food_sodium_per100g = 0;
  //User interface related variavles
    char screen_phase = 'H'; //H for home, S for food select, F for selected food, W for week recap, M for month recap, A for advice screen
    int selection_index = 1
    int week_select = 0 //how many weeks into the past
    int month_select = 0 //how many months into the past
    int week_completed = 0 
    int month_completed = 0
    int Forward_Button_State = 0
    int Backward_Button_State = 0
    int Select_Button_State = 0
    String option_one_food = 
    String option_one_food_path = 
    String option_two_food = 
    String option_two_food_path = 
    String option_three_food = 
    String option_three_food_path = 
    uint32_t bgColor = 0xFF9C;  // Soft Beige for background color
    uint32_t btnColor = 0xA61A; // Soft Blue for the button color
    uint32_t textColor = 0x3186; // Dark Gray for the text color
    unint32_t highlightColor = TFT_RED; // Red for high contrast highlight




void refresh_4DD() {
  display.displayNumber(weight); 
}

void refresh_weight() {
  weight = scale.get_units();
}

void refresh_TFT() {
  if (screen_phase == 'H') {
    TFT_home_screen();

  } else if (screen_phase == 'S') {
    TFT_food_select();

  } else if (screen_phase == 'F') {
    TFT_selected_food();

  } else if (screen_phase == 'W') {
    TFT_week_recap();

  } else if (screen_phase == 'M') {
    TFT_month_recap();

  } else if (screen_phase == 'A') {
    TFT_advice();

  }

  TFT_border_highlight();
} //finished

void fetch_food_info() {
  File Food_info = SD.open(selected_food_path + "/" + selected_food, FILE_READ);
  delay(5);
  food_name = Food_info.readStringUntil('\n'); // Read the first line for the food name
  food_cal_per100g = Food_info.parseFloat(); // Calories (in kcal)
  food_protein_per100g = Food_info.parseFloat(); // Protein (in grams)
  food_fat_per100g = Food_info.parseFloat(); // Fat (in grams)
  food_carbohydrates_per100g = Food_info.parseFloat(); // Carbohydrates (in grams)
  food_sodium_per100g = Food_info.parseFloat(); // Sodium (in grams)
  food_sugar_per100g = Food_info.parseFloat(); // Sugar (in grams)
  food_fiber_per100g = Food_info.parseFloat(); // Fiber (in grams)

  Food_info.close();
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
} //finished

void TFT_food_select() {

  
}

void TFT_selected_food() {

  
}

void TFT_week_recap() {

  
}

void TFT_month_recap() {

  
}

void TFT_advice() {

  
}

void TFT_border_highlight() {
  if (screen_phase == 'H') {
    if (selection_index == 1) {
      tft.drawRect(20, 20, 280, 120, highlightColor);
    } else if (selection_index == 2) {
      tft.drawRect(20, 180, 280, 120, highlightColor);
    } else {
      tft.drawRect(20, 340, 280, 120, highlightColor);
    }
  } else if (screen_phase == 'S') {
    

  } else if (screen_phase == 'F') {
    

  } else if (screen_phase == 'W') {
    

  } else if (screen_phase == 'M') {
    

  } else if (screen_phase == 'A') {
    

  }

}

void add_food() {


}

void update_options() {


}

void process_backward_button_press() {
  if (selection_index != 1) {
    selection_index -= 1;
  }

  refresh_TFT();
} //finished

void process_forward_button_press() {
  if (screen_phase == 'H') {
    if (selection_index != 3) {
      selection_index += 1;
    }

  } else if (screen_phase == 'S') {
    if (selection_index != 30) { 
      selection_index += 1;
    }

  } else if (screen_phase == 'F') {
    if (selection_index != 2) {
      selection_index += 1;
    }

  } else if (screen_phase == 'W') {
    if (selection_index != 3) {
      selection_index += 1;
    }

  } else if (screen_phase == 'M') {
    if (selection_index != 3) {
      selection_index += 1;
    }
  }

  refresh_TFT();
}//finished

void process_select_button_press() {
  if (screen_phase == 'H') {
    
    if (selection_index == 1) {
      screen_phase = 'S';
      selected_food = "";
      selected_food_path = "";
    } else if (selection_index == 2){
      screen_phase = 'W';
      week_select = 0;
    } else if (selection_index == 3){
      screen_phase = 'M';
      month_select = 0;
    } else if (selection_index == 4){
      screen_phase = 'A';
    }

  
  } else if (screen_phase == 'S') {
    if (selection_index == 1) {
      screen_phase = 'H';
    } else if (selection_index == 28) {
      screen_phase = 'F';
      selected_food = option_one_food;
      selected_food_path = option_one_food_path;
      fetch_food_info();
    } else if (selection_index == 29) {
      screen_phase = 'F';
      selected_food = option_two_food;
      selected_food_path = option_two_food_path;
      fetch_food_info();
    } else if (selection_index == 30) {
      screen_phase = 'F';
      selected_food = option_three_food;
      selected_food_path = option_three_food_path;
      fetch_food_info();
    } else {
      if (selected_food.length() <= 8){
        if (selection_index == 2) {
          selected_food += "A";
          selected_food_path += "A/";

        } else if (selection_index == 3) {
          selected_food += "B";
          selected_food_path += "B/";

        } else if (selection_index == 4) {
          selected_food += "C";
          selected_food_path += "C/";

        } else if (selection_index == 5) {
          selected_food += "D";
          selected_food_path += "D/";

        } else if (selection_index == 6) {
          selected_food += "E";
          selected_food_path += "E/";

        } else if (selection_index == 7) {
          selected_food += "F";
          selected_food_path += "F/";

        } else if (selection_index == 8) {
          selected_food += "G";
          selected_food_path += "G/";

        } else if (selection_index == 9) {
          selected_food += "H";
          selected_food_path += "H/";

        } else if (selection_index == 10) {
          selected_food += "I";
          selected_food_path += "I/";

        } else if (selection_index == 11) {
          selected_food += "J";
          selected_food_path += "J/";

        } else if (selection_index == 12) {
          selected_food += "K";
          selected_food_path += "K/";

        } else if (selection_index == 13) {
          selected_food += "L";
          selected_food_path += "L/";

        } else if (selection_index == 14) {
          selected_food += "M";
          selected_food_path += "M/";

        } else if (selection_index == 15) {
          selected_food += "N";
          selected_food_path += "N/";

        } else if (selection_index == 16) {
          selected_food += "O";
          selected_food_path += "O/";

        } else if (selection_index == 17) {
          selected_food += "P";
          selected_food_path += "P/";

        } else if (selection_index == 18) {
          selected_food += "Q";
          selected_food_path += "Q/";

        } else if (selection_index == 19) {
          selected_food += "R";
          selected_food_path += "R/";

        } else if (selection_index == 20) {
          selected_food += "S";
          selected_food_path += "S/";

        } else if (selection_index == 21) {
          selected_food += "T";
          selected_food_path += "T/";

        } else if (selection_index == 22) {
          selected_food += "U";
          selected_food_path += "U/";

        } else if (selection_index == 23) {
          selected_food += "V";
          selected_food_path += "V/";

        } else if (selection_index == 24) {
          selected_food += "W";
          selected_food_path += "W/";

        } else if (selection_index == 25) {
          selected_food += "X";
          selected_food_path += "X/";

        } else if (selection_index == 26) {
          selected_food += "Y";
          selected_food_path += "Y/";

        } else if (selection_index == 27) {
          selected_food += "Z";
          selected_food_path += "Z/";
        }

        update_options();
      }
    }

  } else if (screen_phase == 'F') {
    if (selection_index == 1) {
      screen_phase = 'S'
      selected_food = "";
      selected_food_path = "";
    } else if (selection_index == 2){
      screen_phase = 'H';
      add_food();
    }

  } else if (screen_phase == 'W') {
    if (selection_index == 1) {
      screen_phase = 'H';
    } else if (selection_index == 2){
      if (week_select != 3 && week_completed >= week_select + 1) {
        week_select += 1;
      }
    } else if (selection_index == 3) {
      if (week_slect != 0) {
        week_select -= 1;
      }
    
    }

  } else if (screen_phase == 'M') {
    if (selection_index == 1) {
      screen_phase = 'H';
    } else if (selection_index == 2){
      if (month_completed >= month_select + 1) {
        month_select += 1;
      }
    } else if (selection_index == 3) {
      if (month_slect != 0) {
        month_select -= 1;
      }

    }

  } else if (screen_phase == 'A') {
    if (selection_index == 1) {
      screen_phase = 'H';
    }

  } 

  selection_index = 1;
  refresh_TFT();
}

void check_buttons() {
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
} //finished


void setup() {
  Serial.begin(9600); //for debugging so we can delete it if not debugging
  
  //set up for the buttons
    pinMode(Forward_Button_pin, INPUT_PULLUP);
    pinMode(Backward_Button_pin, INPUT_PULLUP);
    pinMode(Select_Button_pin, INPUT_PULLUP);
  //set up for the 4 digit display
    display.displayNumber(8888);
    delay(500);
    display.all4DigitsOff(); // Turn off all digits initially
  //set up for the load cell
    scale.begin(DOUT_pin, SCK_pin_HX711); //starts the communication
    scale.tare(); //tare
    scale.set_scale(1106);//sets the scale needed to show the correct weight (can be changed)
  //set up for the SD module
    if(!SD.begin(CS_MicroSD)){
      Serial.println("Initialization failed");
    } else {
    Serial.println("SD card initialized");
    }
  //set up for the TFT display
    tft.init();
    tft.setRotation(2); //use 0 or delete if the pins are at the bottom and use  2 if the pins are on the top
}

void loop() {

    if (timer == 5){
      
Serial.println("Weight on scale: " + String(weight) + "\n" +
               "Food: " + food_name + "\n" +
               "Calories: " + String(round(food_cal_per100g * weight / 100)) + "\n" +
               "Protein: " + String(round(food_protein_per100g * weight / 100)) + "\n" +
               "Carbs: " + String(round(food_carbohydrates_per100g * weight / 100)) + "\n" +
               "Sugar: " + String(round(food_sugar_per100g * weight / 100)) + "\n" +
               "Fat: " + String(round(food_fat_per100g * weight / 100)) + "\n" +
               "Fiber: " + String(round(food_fiber_per100g * weight / 100)) + "\n" +
               "Sodium: " + String(round(food_sodium_per100g * weight / 100)));    
      timer = 0;
      }
      
    timer += 1;
}
