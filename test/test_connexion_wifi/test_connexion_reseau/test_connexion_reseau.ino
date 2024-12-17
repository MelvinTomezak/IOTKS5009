#include "WiFi.h"
#include "PubSubClient.h"
#include  "Wire.h"

const char *ssid = "Xperia_5_2665";   
const char *password = "00000000"; 
  
// MQTT Broker
//C'est les parametres avec lequelles ça marche  
const char *mqtt_broker = "192.168.147.67"; 
const char *topic = "Test"; 
const char *mqtt_username = ""; 
const char *mqtt_password = ""; 
const int mqtt_port = 1883; 
WiFiClient espClient; 
PubSubClient client(espClient); 

void setup() { 
 Serial.begin(115200); 
 Serial.println("Start"); 
 WiFi.begin(ssid, password); 
 while (WiFi.status() != WL_CONNECTED) { 
 delay(500); 
 Serial.println("Connecting to WiFi.."); 
  } Serial.println("Connected to the Wi-Fi network");   
 client.setServer(mqtt_broker, mqtt_port); 
 client.setCallback(callback); 
 while (!client.connected()) { 
 String client_id = "esp32-client-"; 
 client_id += String(WiFi.macAddress()); 
 Serial.printf("The client %s connects to the public MQTT brokern", client_id.c_str()); 
 if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) { 
  Serial.println("Public EMQX MQTT broker connected"); 
  } else { 
  Serial.println("failed with state "); 
  Serial.println(client.state()); 
  delay(2000); 
  } 
  } 

  client.publish(topic, "Hi, I'm ESP32"); 
  client.subscribe(topic);
  } 
void callback(char *topic, byte *payload, unsigned int length) { 
Serial.print("Message arrived in topic: "); 
Serial.println(topic); 
  Serial.print("Message:"); 
  for (int i = 0; i < length; i++) { 
Serial.print((char) payload[i]); 
  } 
  Serial.println(); 
  Serial.println("-----------------------"); 
}
void loop() { 

  client.loop(); 

  } 