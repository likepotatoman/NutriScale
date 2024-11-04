#include <SD.h>
#include <SPI.h>

const int CS_pin = 43;
int num_ligne = 1;    // Line number to read
String phrase = "";

void setup() {
  Serial.begin(9600);
  if (!SD.begin(CS_pin)) {
    Serial.println("Initialization failed!");
    return;
  }
  Serial.println("SD card initialized.");
}

void loop() {
  //isolement de la premiere phrase
  if(num_ligne <=40){
  File dataFile = SD.open("PRACTICE.txt",FILE_READ);
  if (dataFile) {
    int ligne_actuelle = 1;     // Current line counter
    phrase = "";

    while (dataFile.available()) {
      char c = dataFile.read();
      if (c == '\n') {
        // If we reach the desired line number, stop reading
        if (ligne_actuelle == num_ligne) break;
        // Move to the next line
        ligne_actuelle++;
        phrase = "";  // Reset phrase for the next line
      } else if (ligne_actuelle == num_ligne) {
        // Append character to phrase if we’re on the desired line
        phrase += c;
      }
    }

    dataFile.close();

    //isolement du premier mot
    String firstWord = "";
    for (char c : phrase) {
        if (c == ' ') break; // Stop when a space is encountered
        firstWord += c;       // Add each character to firstWord
    }

    //creation des differents sous directory
    String directoryPath = "";
    for (int i = 0; i < firstWord.length(); i++){
    char lettre = firstWord[i];
    if (!SD.exists(directoryPath+"/"+lettre)){
    SD.mkdir(directoryPath+"/"+lettre);}
    directoryPath = directoryPath+"/"+lettre;
}
File NewFile = SD.open(directoryPath+"/"+firstWord, FILE_WRITE);

//I need to add a line by line thing here instead of just writing down all the data
    
NewFile.println(phrase);
NewFile.close();
Serial.println(phrase);


    } else {
    Serial.println("Error opening file.");
  }
  num_ligne += 1;  // Increment line number for the next loop iteration
  delay(0);     // Delay to avoid rapid printing
}}
