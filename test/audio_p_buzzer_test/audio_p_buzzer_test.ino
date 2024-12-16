#include <ESP32Tone.h>

// On définit le buzzer sur la broche 25
#define buzzer_pin 25

void setup() {
pinMode(buzzer_pin, OUTPUT);
birthday();
}

void loop() {

}

//On génére des sons avec certaines fréquences pour faire la chanson Happy Birthday
void birthday()
{
tone(buzzer_pin,294,250,0);  //The four parameters are pin, frequency, delay and channel 
tone(buzzer_pin,440,250,0);
tone(buzzer_pin,392,250,0);
tone(buzzer_pin,532,250,0);
tone(buzzer_pin,494,250,0);
tone(buzzer_pin,392,250,0);
tone(buzzer_pin,440,250,0);
tone(buzzer_pin,392,250,0);
tone(buzzer_pin,587,250,0);
tone(buzzer_pin,532,250,0);
tone(buzzer_pin,392,250,0);
tone(buzzer_pin,784,250,0);
tone(buzzer_pin,659,250,0);
tone(buzzer_pin,532,250,0);
tone(buzzer_pin,494,250,0);
tone(buzzer_pin,440,250,0);
tone(buzzer_pin,698,250,0);
tone(buzzer_pin,659,250,0);
tone(buzzer_pin,532,250,0);
tone(buzzer_pin,587,250,0);
tone(buzzer_pin,532,500,0);
noTone(buzzer_pin,0);  //Close
}