//Test de connexion à un réseau
#include <WiFi.h>
#include <LiquidCrystal_I2C.h>

const char* ssid = "Fayrouz";
const char* password = "123sf3_8";
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
    lcd.begin();
    lcd.backlight();
    Serial.begin(115200);
    delay(1000);

    WiFi.mode(WIFI_STA); 
    WiFi.begin(ssid, password);
    Serial.println("\nConnecting");

    unsigned long startAttemptTime = millis();  

    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(100);
// Si après les dix secondes on est pas connecté on affiche wifi non connecte
         if (millis() - startAttemptTime >= 10000) {
            lcd.clear();  
            lcd.setCursor(0, 0);
            lcd.print("WiFi non connecte");
            return;  
        }
    }
    
    lcd.clear(); 
    lcd.setCursor(0, 0);
    lcd.print("WiFi connecte");
    lcd.setCursor(0, 1); 
    lcd.print("IP: ");
    lcd.print(WiFi.localIP());
}

void loop(){
  if ()
}
