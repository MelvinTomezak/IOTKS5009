//Test de connexion avec bluetooth 
#include "BluetoothSerial.h"

BluetoothSerial BT; 

void setup() {
  Serial.begin(115200);
  BT.begin("ESP32_BT"); 
  Serial.println("Bluetooth prêt !");
}

void loop() {
  if (BT.available()) {
    char received = BT.read();
    Serial.print("Données reçues : ");
    Serial.println(received);
  }
  BT.println("Hello depuis ESP32 !");
  delay(1000);
}
