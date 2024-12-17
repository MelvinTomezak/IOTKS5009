//Test connexion wifi au microcontrolleur
//Après vérification nous avons fait du microcontrolleur un point d'accès wifi
#include <WiFi.h>

const char* ssid     = "MicrocontrolleurFAM";
const char* password = "oooooooooooo";

void setup()
{
    Serial.begin(115200);
    Serial.println("\n[*] Creating AP");
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);
    Serial.print("[+] AP Created with IP Gateway ");
    Serial.println(WiFi.softAPIP());
}
void loop(){}