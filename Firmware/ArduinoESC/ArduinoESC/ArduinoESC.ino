/*
        Arduino Brushless Motor Control
     by Dejan, https://howtomechatronics.com
*/
// #if defined(MILLIS_USE_TIMERA0) || defined(__AVR_ATtinyxy2__)
//   #error "This sketch takes over TCA0, don't use for millis here.  Pin mappings on 8-pin parts are different"
// #endif
// #include <Servo.h>

// Servo ESC;     // create servo object to control the ESC
#define ESC_Speed_Pin 1
#define POT_Speed_Pin 3
#define Toggle_Pin 4

// #define MinPW 750
// #define MaxPW 2250
#define MIN_ANALOG 128
int potValue;  // value from the analog pin
uint8_t analog = MIN_ANALOG;

void setup() {
  pinMode(Toggle_Pin, INPUT_PULLUP);
  pinMode(ESC_Speed_Pin, OUTPUT); //PA1 - 
  delay(1000);
  analogWrite(ESC_Speed_Pin, analog);

}

void loop() {
  if (digitalRead(Toggle_Pin) == LOW)
  {
    potValue = analogRead(POT_Speed_Pin);   // reads the value of the potentiometer (value between 0 and 1023)
    uint8_t value = (potValue / 8) + MIN_ANALOG;
    if(analog < value)
    { 
      analog ++;
      delay(10);
    } else {
      analog = value;
    }
  } else {
    analog = MIN_ANALOG;
  }
  analogWrite(ESC_Speed_Pin, analog);
}
