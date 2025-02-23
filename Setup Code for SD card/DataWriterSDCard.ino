#include <SD.h>
#include <SPI.h>
#include <ctype.h>

const int CS_pin = 43;
int length_data = 9; // nombre d'éléments dans une ligne
int nombre_total_ligne = 262; // nombre total de lignes qui vont être imprimées
int num_ligne = 1; // Line number to read
String phrase = "";


void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);

    if (SD.exists("DATA.txt")) {
        Serial.println("File exists!");
    } else {
        Serial.println("File does not exist.");
    }


    if (!SD.begin(CS_pin)) {
        Serial.println("Initialization failed!");
        return;
    }

    Serial.println("SD card initialized.");
}

void loop() {
    // Isolement de la première phrase
    if (num_ligne <= nombre_total_ligne) { //else l 95
        File dataFile = SD.open("DATA.txt", FILE_READ);

        if (dataFile) { // else line 90
            int ligne_actuelle = 1; // Current line counter
            phrase = "";

            while (dataFile.available()) {
                char c = dataFile.read();

                if (c == '\n') {
                    // If we reach the desired line number, stop reading
                    if (ligne_actuelle == num_ligne) break;
                    // Move to the next line
                    ligne_actuelle++;
                    phrase = ""; // Reset phrase for the next line
                } else if (ligne_actuelle == num_ligne) {
                    // Append character to phrase if we’re on the desired line
                    phrase += c;
                }
            }

            dataFile.close();

            // Isolement du premier mot
            String firstWord = "";
            for (char c : phrase) {
                if (isdigit(c)) break; // Stop when a number is encountered
                if (firstWord.length() < 8) {
                    if (c == ' ') { 
                      firstWord += '_';
                    } else {
                      firstWord += c; // Add each character to firstWord
                    }
                }
            }

            String directoryPath = "";

            for (int i = 0; i < firstWord.length(); i++) {
                // Creation des différents sous répertoires
                char lettre = firstWord[i];
                if (!SD.exists(directoryPath + "/" + lettre)) {
                    SD.mkdir(directoryPath + "/" + lettre);
                    Serial.println("New directory at " + directoryPath + " was created named " + lettre);
                } else {
                    Serial.println("Directory of path " + directoryPath + "/" + lettre + " already existed");
                }
                directoryPath = directoryPath + "/" + lettre;

                // Only create the file starting from the second letter
                if (i != 0) {
                    // Creation du fichier dans chaque nested directory sauf le premier
                    if (!SD.exists(directoryPath + "/" + firstWord)){
                        File NewFile = SD.open(directoryPath + "/" + firstWord, FILE_WRITE);
    
                        if (NewFile) { // else l 87
                            Serial.println("Making of new file successful");
                            int indice_derniere_lettre = 0;
    
                            for (int j = 1; j <= length_data; j++) {
                                String mot = "";
    
                                while (phrase[indice_derniere_lettre] != ' ') {
                                    mot += phrase[indice_derniere_lettre];
                                    indice_derniere_lettre += 1;
                                }
                                indice_derniere_lettre += 1;
                                NewFile.println(mot);
                            }
                            NewFile.close();
    
                        } else {
                            Serial.println("Error making new file");
                        }
                    } else {
                        Serial.println("File existed already");
                    }
                }
            }

        } else {
            Serial.println("Error opening file.");
        }

        num_ligne += 1; // Increment line number for the next loop iteration
    } else {
        Serial.println("Finished!");
        while (true) {
            digitalWrite(LED_BUILTIN, HIGH);
            delay(250);
            digitalWrite(LED_BUILTIN, LOW);
            delay(250);
        }
    }
}
