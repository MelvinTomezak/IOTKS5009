//Test de connexion à un réseau
#include <WiFi.h>

const char* ssid = "Fayrouz";
const char* password = "123sf3_8";

void setup(){
    Serial.begin(115200);
    delay(1000);

    WiFi.mode(WIFI_STA); 
    WiFi.begin(ssid, password);
    Serial.println("\nConnecting");

    unsigned long startAttemptTime = millis();  

    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(100);

        // Si on attend plus de 10 secondes alors fin
        if (millis() - startAttemptTime >= 10000) {
            Serial.println("\nFailed to connect to WiFi. Check credentials or signal.");
            return;  
        }
    }

    Serial.println("\nConnected to the WiFi network");
    Serial.print("Local ESP32 IP: ");
    Serial.println(WiFi.localIP());
}

void loop(){
}
