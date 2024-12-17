#include <WiFi.h>
 
// Identifiants du réseau Wi-Fi
const char* ssid = "Fayrouz";
const char* password = "123sf3_8";
 
void setup() {
  Serial.begin(115200); // Initialisation de la communication série
 
  // Connexion au réseau Wi-Fi
  WiFi.begin(ssid, password);
  Serial.println("\nConnexion au Wi-Fi...");
 
  unsigned long startAttemptTime = millis();  
 
  // Tentative de connexion pendant 10 secondes
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print("."); // Affichage d'un point pour chaque tentative
 
    // Si après 10 secondes, la connexion échoue
    if (millis() - startAttemptTime >= 10000) {
      Serial.println("\nEchec de la connexion.");
      return; // Fin de la fonction si non connecté
    }
  }
 
  // Si la connexion réussit
  Serial.println("\nConnecté au réseau Wi-Fi !");
  Serial.print("Adresse IP : ");
  Serial.println(WiFi.localIP());  // Affiche l'adresse IP locale de l'ESP32
}
 
void loop() {
  // Code à exécuter en boucle (si nécessaire)
}
