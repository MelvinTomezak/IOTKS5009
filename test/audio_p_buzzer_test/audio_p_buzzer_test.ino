// Modification du code de test car la librarie ESP32TONE.h n'est plus prise en charge aujourd'hui.
#define BUZZER_PIN 25 
#define BUZZER_CHANNEL 0  
#define BUZZER_RESOLUTION 8  
#define BUZZER_FREQUENCY 0  

void setup() {
  ledcSetup(BUZZER_CHANNEL, BUZZER_FREQUENCY, BUZZER_RESOLUTION);
  ledcAttachPin(BUZZER_PIN, BUZZER_CHANNEL);

// Appel de la fonction pour jouer la Musique d'anniversaire
  playBirthdaySong();
}

void loop() {
}

// Fonction permettant de jouer un son sur une frequence
void playTone(int frequency, int duration) {
  if (frequency > 0) {
    ledcWriteTone(BUZZER_CHANNEL, frequency);  
    delay(duration); 
  }
  ledcWriteTone(BUZZER_CHANNEL, 0);  
  delay(50); 
}

//Fonction permettant de jouer la musique Happy Birthday (joyeux anniversaire en Fr)
void playBirthdaySong() {
  playTone(294, 250);  
  playTone(440, 250);  
  playTone(392, 250);  
  playTone(523, 250);  
  playTone(494, 250);  
  playTone(392, 250); 
  playTone(440, 250); 
  playTone(392, 250);  
  playTone(587, 250); 
  playTone(523, 250);  
  playTone(392, 250); 
  playTone(784, 250);  
  playTone(659, 250);  
  playTone(523, 250);  
  playTone(494, 250); 
  playTone(440, 250);
  playTone(698, 250);  
  playTone(659, 250);  
  playTone(523, 250);  
  playTone(587, 250);  
  playTone(523, 500);  
}
