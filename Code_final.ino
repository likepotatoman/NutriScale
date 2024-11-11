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
    const int CS_MicroSD = 45;
  //TFT display module pins

  //SPI communication protocol pins
    const int MISO_pin = 50; //Unchangeable
    const int MOSI_pin = 51; //Unchangeable
    const int SCK_pin_SPI = 52; //Unchangeable


// Create an instance of the libraries
  FourDigits7SegmentsDisplayLibrary display(SegA, SegB, SegC, SegD, SegE, SegF, SegG, Dig1, Dig2, Dig3, Dig4); // Pin numbers for segments and digits
  HX711 scale;

void setup() {
  //initialization of non-constant variables
    int weight = 0;
    int timer = 0;
    String screen_phase = "home_screen";
  //set up for the 4 digit display
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
    
    if (timer == 5){
      weight = scale.get_units();
      Serial.println(weight);
      timer = 0;
      }
      
    timer += 1;
    display.displayNumber(weight);  
    
}
