/* This code should be run only once per ESC. 
 * This code calibrate ESC's minimum and maximum pulse width and 
 * arming pulse width.
 *
 *                                       _Vignesh Natarajan (Viki) 
 *
 */
#include "esc_controller.hpp"
#define LED_PIN 13
#define ESC_PIN 9
/*pulse width to arm ESC in microseconds*/
#define ARM_PW 500
/*minimum pulse width for ESC in microseconds*/
#define MIN_PW 1000
/*maximum pulse width for ESC in microseconds*/
#define MAX_PW 2000

esc_controller esc(ESC_PIN, ARM_PW, MIN_PW, MAX_PW);

/*flash led 4 times and turn on the led*/
void flash_led_on(int led)
{
  for(int i=0; i<4; i++){
      digitalWrite(led, HIGH);
      delay(250);
      digitalWrite(led, LOW);
      delay(250);
  }
  digitalWrite(led, HIGH);
}

/*flash led 4 times and turn off the led*/
void flash_led_off(int led)
{
  for(int i=0; i<4; i++){
      digitalWrite(led, HIGH);
      delay(250);
      digitalWrite(led, LOW);
      delay(250);
  }
  digitalWrite(led, LOW);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  flash_led_on(LED_PIN);
  esc.calibrate();
  esc.disarm();
  flash_led_off(LED_PIN);
}

void loop() {
}
