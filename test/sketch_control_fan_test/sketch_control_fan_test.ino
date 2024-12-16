#define fanPin1 19
#define fanPin2 18

void setup() {
  pinMode(fanPin1, OUTPUT); // Configure la broche fanPin1 comme sortie
  pinMode(fanPin2, OUTPUT); // Configure la broche fanPin2 comme sortie
}

void loop() {
  // Étape 1 : FanPin1 LOW (PWM 0 sur fanPin2)
  digitalWrite(fanPin1, LOW); 
  analogWrite(fanPin2, 0); // Signal PWM à 0
  delay(3000); // Pause de 3 secondes
  
  // Étape 2 : Désactivation
  digitalWrite(fanPin1, LOW);
  digitalWrite(fanPin2, LOW); // Éteindre complètement
  delay(1000); // Pause de 1 seconde
  
  // Étape 3 : FanPin1 HIGH (PWM 255 sur fanPin2)
  digitalWrite(fanPin1, HIGH); 
  analogWrite(fanPin2, 255); // Signal PWM à 255 (pleine puissance)
  delay(3000); // Pause de 3 secondes
  
  // Étape 4 : Désactivation
  digitalWrite(fanPin1, LOW);
  digitalWrite(fanPin2, LOW); // Éteindre complètement
  delay(1000); // Pause de 1 seconde
}
