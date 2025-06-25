import paho.mqtt.client as mqtt
import json
import time
import random

# Cria o cliente MQTT e liga ao broker público
client = mqtt.Client()
client.connect("test.mosquitto.org", 1883)

while True:
    # Simula valor RMS entre 990 e 1020
    payload = json.dumps({"rms": round(random.uniform(990, 1020), 2)})
    # Envia no tópico sensor/rms
    client.publish("sensor/rms", payload)
    print("Enviado:", payload)
    # Aguarda 5 segundos antes de enviar novamente
    time.sleep(5)
