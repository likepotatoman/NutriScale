#include "4Digits7SegmentsDisplayLibrary.h"

// Constructor implementation
FourDigits7SegmentsDisplayLibrary::FourDigits7SegmentsDisplayLibrary(int a, int b, int c, int d, int e, int f, int g, int d1, int d2, int d3, int d4) {
    pinA = a;
    pinB = b;
    pinC = c;
    pinD = d;
    pinE = e;
    pinF = f;
    pinG = g;
    D1 = d1;
    D2 = d2;
    D3 = d3;
    D4 = d4;

    // Set all pins as OUTPUT
    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(pinC, OUTPUT);
    pinMode(pinD, OUTPUT);
    pinMode(pinE, OUTPUT);
    pinMode(pinF, OUTPUT);
    pinMode(pinG, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
}

// Function implementations
void FourDigits7SegmentsDisplayLibrary::zero() {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, LOW);
}

void FourDigits7SegmentsDisplayLibrary::one() {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
}

void FourDigits7SegmentsDisplayLibrary::two() {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
}

void FourDigits7SegmentsDisplayLibrary::three() {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
}

void FourDigits7SegmentsDisplayLibrary::four() {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
}

void FourDigits7SegmentsDisplayLibrary::five() {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
}

void FourDigits7SegmentsDisplayLibrary::six() {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
}

void FourDigits7SegmentsDisplayLibrary::seven() {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
}

void FourDigits7SegmentsDisplayLibrary::eight() {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
}

void FourDigits7SegmentsDisplayLibrary::nine() {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
}

void FourDigits7SegmentsDisplayLibrary::allNumbers() {
    one(); delay(500);
    two(); delay(500);
    three(); delay(500);
    four(); delay(500);
    five(); delay(500);
    six(); delay(500);
    seven(); delay(500);
    eight(); delay(500);
    nine(); delay(500);
}

void FourDigits7SegmentsDisplayLibrary::turnOffAllSegments() {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
}

void FourDigits7SegmentsDisplayLibrary::digit1() {
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
}

void FourDigits7SegmentsDisplayLibrary::digit2() {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
}

void FourDigits7SegmentsDisplayLibrary::digit3() {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
}

void FourDigits7SegmentsDisplayLibrary::digit4() {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
}

void FourDigits7SegmentsDisplayLibrary::all4Digits() {
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW);
}

void FourDigits7SegmentsDisplayLibrary::all4DigitsOff() {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
}

void FourDigits7SegmentsDisplayLibrary::displayDigit(int digit, int position) {
    switch (position) {
        case 1: digit1(); break;
        case 2: digit2(); break;
        case 3: digit3(); break;
        case 4: digit4(); break;
    }

    switch (digit) {
        case 0: zero(); break;
        case 1: one(); break;
        case 2: two(); break;
        case 3: three(); break;
        case 4: four(); break;
        case 5: five(); break;
        case 6: six(); break;
        case 7: seven(); break;
        case 8: eight(); break;
        case 9: nine(); break;
    }
}

void FourDigits7SegmentsDisplayLibrary::displayNumber(int number) {
    if (number < 0 || number > 2000) return;

    // Extract each digit from the number
    int thousands = number / 1000;
    int hundreds = (number / 100) % 10;
    int tens = (number / 10) % 10;
    int ones = number % 10;

    // Display each digit on the corresponding display
    if (thousands == 0) {
    digit1();turnOffAllSegments();
    }
    else { displayDigit(thousands, 1); }
    delay(5);  // Small delay for stability, adjust as necessary
    
    if (thousands == 0 and hundreds == 0) 
    {digit2();turnOffAllSegments();}
    else {displayDigit(hundreds, 2);}
    delay(5);
    if (thousands == 0 and hundreds == 0 and tens == 0) 
    {digit3();turnOffAllSegments();}
    else {displayDigit(tens, 3);}
    delay(5);
    displayDigit(ones, 4);
    delay(5);
}
