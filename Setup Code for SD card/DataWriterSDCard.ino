#include <SD.h>
#include <SPI.h>

const int CS_pin = 43;
int longeur_data = 8 //nombre d'element dans une ligne
int nombre_total_ligne = 40 //nombre total de ligne qui vont etre inprime
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
  if(num_ligne <= nombre_total_ligne){
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

for (int i = 1; i <= longueur_data; i++) {
  String mot = "";
  int indice_derniere_lettre = 0;
  while (phrase[indice_derniere_lettre] != ' ') {
    mot += phrase[indice_derniere_lettre];
    indice_derniere_lettre += 1;
  }
  indice_derniere_lettre += 1;
  NewFile.println(mot);
}
NewFile.close();

    } else {
    Serial.println("Error opening file.");
  }
  num_ligne += 1;  // Increment line number for the next loop iteration
}}
