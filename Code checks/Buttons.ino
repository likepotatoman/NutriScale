const int Backward_Button_pin = 47;
const int Select_Button_pin = 45;
const int Forward_Button_pin = 43;

int Forward_Button_State = 0; //0 for off and 1 for on
int Backward_Button_State = 0;
int Select_Button_State = 0;

void setup() {
  // put your setup code here, to run once:
pinMode( Backward_Button_pin, INPUT_PULLUP);
pinMode( Forward_Button_pin, INPUT_PULLUP);
pinMode(Select_Button_pin, INPUT_PULLUP);
pinMode(LED_BUILTIN, OUTPUT);
digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Forward_Button_State == 0) {
    if (digitalRead(Forward_Button_pin) == LOW) {
      Forward_Button_State = 1;
      delay(50);
    }
  } else {
    if (digitalRead(Forward_Button_pin) == HIGH) {
      Forward_Button_State = 0;
      delay(50);
         for (int i = 0; i < 1; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);}
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
          for (int i = 0; i < 2; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);}
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
          for (int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);}
    }
  }
}
