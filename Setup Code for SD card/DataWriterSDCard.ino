#include <SD.h>
#include <SPI.h>
#include <ctype.h>

const int CS_pin = 43;
int length_data = 8; // Number of elements in a line
int nombre_total_ligne = 262; // Total number of lines to be printed
int num_ligne = 1; // Line number to read
String phrase = "";
String mot = "";

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);

    if (!SD.begin(CS_pin)) {
        Serial.println("Initialization failed!");
        return;
    }

    Serial.println("SD card initialized.");
}

void loop() {
    if (num_ligne <= nombre_total_ligne) {
        File dataFile = SD.open("DATA.txt", FILE_READ);

        if (dataFile) {
            int ligne_actuelle = 1;
            phrase = "";

            while (dataFile.available()) {
                char c = dataFile.read();

                if (c == '\n') {
                    if (ligne_actuelle == num_ligne) break;
                    ligne_actuelle++;
                    phrase = ""; // Reset phrase for the next line
                } else if (ligne_actuelle == num_ligne) {
                    phrase += c; // Append character to phrase
                }
            }
            dataFile.close();

            // Process the first word
            String firstWord = "";
            for (char c : phrase) {
                if (isdigit(c)) break; // Stop when a number is encountered
                if (firstWord.length() < 8) {
                    if (c == ' ') firstWord += '_';  // Replace space with underscore
                    else firstWord += c; // Add each character to firstWord
                }
            }

            String directoryPath = "";
            for (int i = 0; i < firstWord.length(); i++) {
                char letter = firstWord[i];
                directoryPath += "/" + String(letter);

                if (!SD.exists(directoryPath)) {
                    SD.mkdir(directoryPath);  // Create the directory if it doesn't exist
                    delay(10);
                    Serial.println("New directory created at: " + directoryPath);
                } else {
                    Serial.println("Directory already exists: " + directoryPath);
                }

                // Only start file creation starting from the second letter
                if (i != 0) {
                    if (!SD.exists(directoryPath + "/" + firstWord)) {
                        File NewFile = SD.open(directoryPath + "/" + firstWord, FILE_WRITE);
                        delay(10);
                        if (NewFile) {
                            Serial.println("New file created successfully");

                            int last_char_index = 0;
                            mot = "";

                            // Collect words until a number is encountered
                            while (!isdigit(phrase[last_char_index])) {
                                mot += phrase[last_char_index];
                                last_char_index++;
                            }

                            NewFile.println(mot);  // Write the first word to the file
                            NewFile.flush();
                            delay(10);
                            Serial.println("Added to file: " + mot);

                            for (int j = 2; j <= length_data; j++) {
                                mot = "";
                                while (phrase[last_char_index] != ' ' && last_char_index < phrase.length()) {
                                    mot += phrase[last_char_index];
                                    last_char_index++;
                                }
                                last_char_index++;  // Skip space
                                NewFile.println(mot);  // Write next data to file
                                NewFile.flush();
                                delay(10);
                                Serial.println("Added to file: " + mot);
                            }

                            NewFile.close();
                            delay(10);
                        } else {
                            Serial.println("Error creating new file.");
                        }
                    } else {
                        Serial.println("File already exists.");
                    }
                }
            }

        } else {
            Serial.println("Error opening file.");
        }

        num_ligne++; // Move to the next line for the next loop
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
