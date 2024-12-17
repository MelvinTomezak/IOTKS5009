Installer notre environnement de travail :

## Etape 1 : Installer ARDUINO

Suivez le lien suivant : (https://www.arduino.cc/en/software).

<img width="669" alt="image" src="https://github.com/user-attachments/assets/dc10a6e9-85b1-415c-9260-344c6a630875" />

Sélectionner l'option de téléchargement correspondant à votre système d'exploitation.

## Etape 2 Configurer ARDUINO 

Ouvrez ARDUINO, puis aller dans File -> Preferences

Coller le lien suivant dans le champ : Additional boards manager URL's
(https://dl.espressif.com/dl/package_esp32_index.json)

Aller dans Tools -> Board -> Board Manager
Chercher "ESP32" et cliquez sur Install.

<img width="153" alt="image" src="https://github.com/user-attachments/assets/775d6291-cb57-43ef-952e-c324f1a3d66b" />

Une fois installer, retourner dans Tools -> Board -> Board Manager et séléctionner ESP32 -> ESP32 Dev Module.

Aller dans Tools -> Board -> Port et sélectionner "COM4"
