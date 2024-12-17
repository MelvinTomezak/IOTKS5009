//Test connexion wifi sur un partage de connexion
#include <WiFi.h>

const char* ssid     = "iPhone de JogaBonito";
const char* password = "melvinledz";

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