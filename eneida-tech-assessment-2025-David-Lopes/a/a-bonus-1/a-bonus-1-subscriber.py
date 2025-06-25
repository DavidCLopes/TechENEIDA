import paho.mqtt.client as mqtt


# Função chamada ao receber mensagem
def on_message(_, __, msg):
    print(f"{msg.topic} -> {msg.payload.decode()}")


# Cria o cliente MQTT e define a função de callback
client = mqtt.Client()
client.on_message = on_message

# Liga ao broker público e subscreve ao tópico
client.connect("test.mosquitto.org", 1883)
client.subscribe("sensor/rms")

# Fica à escuta de mensagens
client.loop_forever()
