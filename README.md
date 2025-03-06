# Groupe : 
 ABDIOU Nassime

 GIBAULT Alexandre
 
 SAADAOUI Fayrouz
 
 TOMEZAK Melvin
# Répartition des tâches :

## Etape 1 : Construction de la Smart Home

Alexandre : Construction et assemblement des pièces

Fayrouz : Construction et assemblement des pièces

Melvin : Construction et assemblement des pièces

## Etape 2 : Câblages et Test des différentes pièces :

Tous les tests ont été réalisés depuis le Pc d'Alexandre, mais chacun d'entre nous s'est inspirer de la documentation pour créer différents tests afin de vérifier la fonctionnalité des différentes pièces.

Alexandre : Câblage, Code et test des différentes pièces

Fayrouz : Câblage, Code et test des différentes pièces

Melvin : Câblage, Code et test des différentes pièces

## Etape 3 : Code et test installation MQTT Microcontroleur 

Le microcontrolleur est désormais capable de se connnecter à un réseau et d'envoyer un message.

Alexandre : Code et Test de la solution

Fayrouz : Code et Test de la solution

Melvin : Code et Test de la solution

(Pour cette étape, merci au professeur de nous avoir aider à résoudre les problèmes réseaux).

## Etape 4 : Configuration Rapberry 

Configuration de la carte sd du Raspberry avec Raspberry Pi imager 
- Modèle du Raspberry : Raspberry PI 4
- Système d'exploitation : Raspberry PI OS (64-BIT)
- Stockage : (carte sd)

Configuration également de l'utilisateur et du réseau sur le Raspberry.

## Etape 5 : Configuration Serveur MQTT + Envoie d'un message depuis le Raspberry

Configuration du serveur MQTT pour recevoir des messages envoyé depuis le Raspberry 
Il faut se connecter en ssh au raspberry puis executer la commande suivante :
mosquitto_pub -h adresseip -t test/test -m test

## Etape 6 : Configuration ModBus sur le Rapberry 

On commence par mettre à jour les différents package :

`sudo apt update && sudo apt upgrade -y`

On installe build-essential, cmake et git

`sudo apt install build-essential cmake git -y`

On installe les librairies nécessaires

`sudo apt-get install libmodbus-dev`

`sudo apt install libssl-dev libboost-dev -y`

On clone un premier repo qui correspond à la librairie paho MQTT en c

`git clone https://github.com/eclipse/paho.mqtt.c.git`

`cd paho.mqtt.c`

`cmake -Bbuild -H. -DPAHO_WITH_SSL=TRUE`

`sudo cmake --build build/ --target install`

`cd ..`

Même chose avec le second sauf que celui-ci correspond à la librairie paho MQTT en c++

`git clone https://github.com/eclipse/paho.mqtt.cpp.git`

`cd paho.mqtt.cpp`

`cmake -Bbuild -H. -DPAHO_BUILD_SAMPLES=TRUE`

`sudo cmake --build build/ --target install`

`cd ..`

Pour finir on lance la commande 

`ldconfig -p | grep paho`

et on doit avoir une sortie similaire a ("libpaho-mqtt3cs.so.1 (libc6,AArch64) =>")




## Etape 7 : Création Dashboard

Configuration de la connexion au mqtt.
Ajout de noeuds qui correspondent aux différents capteurs de l'esp32.

