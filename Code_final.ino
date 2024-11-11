// Include all the libraries
#include <4Digits7SegmentsDisplayLibrary.h>
#include <HX711.h>
#include <SD.h>
#include <SPI.h>

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
  //TFT display module pins

  //SPI communication protocol pins
    const int MISO_pin = 50; //Unchangeable
    const int MOSI_pin = 51; //Unchangeable
    const int SCK_pin_SPI = 52; //Unchangeable


// Create an instance of the libraries
FourDigits7SegmentsDisplayLibrary display(SegA, SegB, SegC, SegD, SegE, SegF, SegG, Dig1, Dig2, Dig3, Dig4); // Pin numbers for segments and digits
HX711 scale;

//Declaration of global variables
  int weight = 1;
  int timer = 0;
  char screen_phase = 'H';
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

void setup() {
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
    
    Serial.begin(9600);
}

void loop() {
    if (new_food_selected == true){
      File Food_info = SD.open(selected_food_path + "/" + selected_food, FILE_READ);
      delay(5);
      food_name = Food_info.readStringUntil('\n'); // Read the first line for the food name
      food_cal_per100g = Food_info.parseFloat(); // Calories (in kcal)
      food_protein_per100g = Food_info.parseFloat(); // Protein (in grams)
      food_carbohydrates_per100g = Food_info.parseFloat(); // Carbohydrates (in grams)
      food_sugar_per100g = Food_info.parseFloat(); // Sugar (in grams)
      food_fat_per100g = Food_info.parseFloat(); // Fat (in grams)
      food_fiber_per100g = Food_info.parseFloat(); // Fiber (in grams)
      food_sodium_per100g = Food_info.parseFloat(); // Sodium (in mg)
      Food_info.close();
      new_food_selected = false;
    }

    if (timer == 5){
      weight = scale.get_units();
      Serial.println("Weigth on scale: " + String(weight));
      Serial.println("Food: " + food_name);
      Serial.println("Calories: " + String(round(food_cal_per100g * weight / 100)));
      Serial.println("Protein: " + String(round(food_protein_per100g * weight / 100)));
      Serial.println("Carbs: " + String(round(food_carbohydrates_per100g * weight / 100)));
      Serial.println("Sugar: " + String(round(food_sugar_per100g * weight / 100)));
      Serial.println("Fat: " + String(round(food_fat_per100g * weight / 100)));
      Serial.println("Fiber: " + String(round(food_fiber_per100g * weight / 100)));
      Serial.println("Sodium: " + String(round(food_sodium_per100g * weight / 100)));
      Serial.println("");
      Serial.println("");      
      timer = 0;
      }
      
    timer += 1;
    display.displayNumber(weight);  
    
}
