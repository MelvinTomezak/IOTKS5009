from pymodbus.client.sync import ModbusSerialClient as ModbusClient
import time
import json
import paho.mqtt.client as mqtt

# === Configuration ===
MODBUS_PORT = "/dev/ttyUSB0"  # Port série où l'ESP32 est connecté
MQTT_BROKER = "192.168.1.100"  # Adresse IP du broker MQTT
MQTT_TOPIC = "sensor/data"

def read_sensors(client):
    try:
        response = client.read_holding_registers(0, 2, unit=1)
        if not response.isError():
            return {
                "sensor1_state": response.registers[0],
                "sensor2_value": response.registers[1]
            }
        else:
            print("Erreur Modbus : impossible de lire les registres.")
            return None
    except Exception as e:
        print(f"Erreur lors de la lecture Modbus : {e}")
        return None

def send_mqtt(data, client):
    try:
        payload = json.dumps(data)
        client.publish(MQTT_TOPIC, payload)
        print(f"Données envoyées via MQTT : {payload}")
    except Exception as e:
        print(f"Erreur MQTT : {e}")

def main():
    modbus_client = ModbusClient(
        method="rtu",
        port=MODBUS_PORT,
        baudrate=9600,
        timeout=1
    )
    if not modbus_client.connect():
        print("Erreur : connexion Modbus impossible.")
        return

    mqtt_client = mqtt.Client("RPI_Client")
    mqtt_client.connect(MQTT_BROKER)

    print("Démarrage du script...")
    try:
        while True:
            data = read_sensors(modbus_client)
            if data:
                send_mqtt(data, mqtt_client)

            time.sleep(5)
    except KeyboardInterrupt:
        print("Arrêt demandé par l'utilisateur.")
    finally:
        modbus_client.close()

if __name__ == "__main__":
    main()