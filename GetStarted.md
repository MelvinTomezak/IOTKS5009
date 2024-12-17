Installer notre environnement de travail :

## Etape 1 : Installer ARDUINO

Suivez le lien suivant : (https://www.arduino.cc/en/software).

<img width="669" alt="image" src="https://github.com/user-attachments/assets/dc10a6e9-85b1-415c-9260-344c6a630875" />

Sélectionner l'option de téléchargement correspondant à votre système d'exploitation.

## Etape 2 : Configurer ARDUINO 

Ouvrez ARDUINO, puis aller dans File -> Preferences

Coller le lien suivant dans le champ : Additional boards manager URL's
(https://dl.espressif.com/dl/package_esp32_index.json)

Aller dans Tools -> Board -> Board Manager
Chercher "ESP32" et cliquez sur Install.
Chercher "PubSubClient" et cliquez sur Install.

<img width="153" alt="image" src="https://github.com/user-attachments/assets/775d6291-cb57-43ef-952e-c324f1a3d66b" />

Une fois installer, retourner dans Tools -> Board -> Board Manager et séléctionner ESP32 -> ESP32 Dev Module.

Aller dans Tools -> Board -> Port et sélectionner "COM4"

## Etape 3 : Installer Mosquito et MQTT

Commencer par installer Mosquito disponible au lien suivant (mosquitto.org).

Une fois l'installation terminer, modifier le fichier mosquitto.conf (trouvable dans l'archive suivante : C:/Program Files/mosquitto)
et ajouter c'est trois lignes :

listener 1883 0.0.0.0

allow_anonymous true

log_timestamp_format %Y-%m-%d T %H:%M:%S

Enregistrer et lancer un terminal en tant qu'administrateur afin de démarrer mosquitto a l'aide de la commande suivante : "net start mosquitto".

Installer MQTTExplorer (disponible au lien suivant mqtt-explorer.com).

Démarrer MQTTExplorer et remplisser les différents champs comme sur la capture ci-dessous : 

![image](https://github.com/user-attachments/assets/769b0153-c4c5-4fe6-b28d-9069200a7bfe)

Remplacer localhost par l'adresse IP de votre machine.

