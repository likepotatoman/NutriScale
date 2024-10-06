#ifndef _4Digits7SegmentsDisplayLibrary_h
#define _4Digits7SegmentsDisplayLibrary_h

#include <Arduino.h>

class FourDigits7SegmentsDisplayLibrary {
public:
    FourDigits7SegmentsDisplayLibrary(int pinA, int pinB, int pinC, int pinD, int pinE, int pinF, int pinG, int D1, int D2, int D3, int D4);
    void zero();
    void one();
    void two();
    void three();
    void four();
    void five();
    void six();
    void seven();
    void eight();
    void nine();
    void digit1();
    void digit2();
    void digit3();
    void digit4();
    void allNumbers();
    void turnOffAllSegments();
    void all4Digits();
    void all4DigitsOff();
    void displayDigit(int digit, int position);
    void displayNumber(int number);
private:
    int pinA, pinB, pinC, pinD, pinE, pinF, pinG;
    int D1, D2, D3, D4;
};

#endif
