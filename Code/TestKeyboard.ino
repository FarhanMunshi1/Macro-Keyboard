// Test macro keyboard with this

#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

// define buttons and led
#define BTN_1           34
#define BTN_2           35
#define BTN_3           13
#define BTN_4           23
#define BTN_5           22

#define BTN_6           4

#define BTN_7           21
#define BTN_8           15
#define BTN_9           19

#define RED             5
#define GREEN           18
#define BLUE            17

#define DEBOUNCE_VAL    0.2
#define CLOCK_VAL       10

int lastState = HIGH;     // the previous state from the input pin
int currentState;         // the current reading from the input pin

bool btn1_flag = false;
bool btn2_flag = false;
bool btn3_flag = false;
bool btn4_flag = false;
bool btn5_flag = false;
bool btn6_flag = false;
bool btn7_flag = false;
bool btn8_flag = false;
bool btn9_flag = false;

bool green_flag = false;
bool red_flag = false;

char buff[9];

void IRAM_ATTR Button1_Press() {
  btn1_flag = true;
}
void IRAM_ATTR Button2_Press() {
  btn2_flag = true;  
}
void IRAM_ATTR Button3_Press() {
  btn3_flag = true;  
}
void IRAM_ATTR Button4_Press() {
  btn4_flag = true;  
}
void IRAM_ATTR Button5_Press() {
  btn5_flag = true;  
}
void IRAM_ATTR Button6_Press() {
  btn6_flag = true;  
}
void IRAM_ATTR Button7_Press() {
  btn7_flag = true;  
}
void IRAM_ATTR Button8_Press() {
  btn8_flag = true;  
}
void IRAM_ATTR Button9_Press() {
  btn9_flag = true;  
}

void TurnOnGreenLight() {
  digitalWrite(GREEN, HIGH);
  digitalWrite(RED, LOW);
  digitalWrite(BLUE, LOW);

  green_flag = true;
}
void TurnOnRedLight() {
  digitalWrite(GREEN, LOW);
  digitalWrite(RED, HIGH);
  digitalWrite(BLUE, LOW);  

  red_flag = true;
}

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();
  
  // pinModes 
  pinMode(BTN_1, INPUT);
  pinMode(BTN_2, INPUT);
  pinMode(BTN_3, INPUT);
  pinMode(BTN_4, INPUT);
  pinMode(BTN_5, INPUT);
  pinMode(BTN_6, INPUT);
  pinMode(BTN_7, INPUT);
  pinMode(BTN_8, INPUT);
  pinMode(BTN_9, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  // interrupts 
  attachInterrupt(digitalPinToInterrupt(BTN_1), Button1_Press, RISING) ;
  attachInterrupt(digitalPinToInterrupt(BTN_2), Button2_Press, RISING) ;
  attachInterrupt(digitalPinToInterrupt(BTN_3), Button3_Press, RISING) ;
  attachInterrupt(digitalPinToInterrupt(BTN_4), Button4_Press, RISING) ;
  attachInterrupt(digitalPinToInterrupt(BTN_5), Button5_Press, RISING) ;
  attachInterrupt(digitalPinToInterrupt(BTN_6), Button6_Press, RISING) ;
  attachInterrupt(digitalPinToInterrupt(BTN_7), Button7_Press, RISING) ;
  attachInterrupt(digitalPinToInterrupt(BTN_8), Button8_Press, RISING) ;
  attachInterrupt(digitalPinToInterrupt(BTN_9), Button9_Press, RISING) ;
}

void loop() {

  if (bleKeyboard.isConnected()) {
    
    if (!green_flag) {
      red_flag = false; 
      TurnOnGreenLight();
    }

    if (btn1_flag) {
      delay(DEBOUNCE_VAL);
      if (digitalRead(BTN_1) == HIGH) {
        bleKeyboard.print("A");
        btn1_flag = false;
      }
    }
    if (btn2_flag) {
        delay(DEBOUNCE_VAL);
        if (digitalRead(BTN_2) == HIGH) {
        bleKeyboard.print("B");
        btn2_flag = false;
      }
    }
    if (btn3_flag) {
      delay(DEBOUNCE_VAL);
      if (digitalRead(BTN_3) == HIGH) {
        bleKeyboard.print("C");
        btn3_flag = false;
      }
    }
    if (btn4_flag) {
      delay(DEBOUNCE_VAL);
      if (digitalRead(BTN_4) == HIGH) {
        bleKeyboard.print("D");
        btn4_flag = false;
      }
    }
    if (btn5_flag) {
      delay(DEBOUNCE_VAL);
      if (digitalRead(BTN_5) == HIGH) {
        bleKeyboard.print("E");
        btn5_flag = false;
      }
    }
    if (btn6_flag) {
      delay(DEBOUNCE_VAL);
      if (digitalRead(BTN_6) == HIGH) {
        bleKeyboard.print("F");
        btn6_flag = false;
      }
    }
    if (btn7_flag) {
      delay(DEBOUNCE_VAL);
      if (digitalRead(BTN_7) == HIGH) {
        bleKeyboard.print("G");
        btn7_flag = false;
      }
    }
    if (btn8_flag) {
      delay(DEBOUNCE_VAL);
      if (digitalRead(BTN_8) == HIGH) {
        bleKeyboard.print("H");
        btn8_flag = false;
      }
    }
    if (btn9_flag) {
      delay(DEBOUNCE_VAL);
      if (digitalRead(BTN_9) == HIGH) {
        bleKeyboard.print("I");
        btn9_flag = false;
      }
    }
  }
  // if (bleKeyboard.isConnected()) {

  //   // read the state of the switch/button:
  //   currentState = digitalRead(BTN_1);

  //   if(lastState == LOW && currentState == HIGH) {
  //     bleKeyboard.print("H");
  //     Serial.println("The state changed from LOW to HIGH");
  //   }

  //   // save the last state
  //   lastState = currentState;
  // }

  // bleKeyboard.print("Hello world");
  // bleKeyboard.write(KEY_RETURN);
  // bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
  
   // Below is an example of pressing multiple keyboard modifiers 
   // which by default is commented out.
  /*
  Serial.println("Sending Ctrl+Alt+Delete...");
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press(KEY_LEFT_ALT);
  bleKeyboard.press(KEY_DELETE);
  delay(100);
  bleKeyboard.releaseAll();
  */

  else {
      if (!red_flag) {
        green_flag = false; 
        TurnOnRedLight();
    }
  }
  delay(CLOCK_VAL);
}

// HFCBIGEEDAHHHFCIBIGEDA
