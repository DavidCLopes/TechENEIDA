# A-Bonus 1 – Simulador MQTT em Python

Simula o envio periódico (5s) de valores RMS (Root Mean Square) em formato JSON, usando o protocolo MQTT em Python.  
O sistema é composto por um **publisher** (que envia os dados) e um **subscriber** (que recebe os dados), ambos ligados a um **broker público**.

## Tecnologias utilizadas

- **Biblioteca:** `paho-mqtt` (cliente MQTT)
- **Formato de dados:** JSON
- **Broker usado:** `test.mosquitto.org` (porta 1883)

O **publisher** (`publisher.py`) gera um valor RMS simulado entre 990 e 1020 a cada 5 segundos  
e publica no tópico `sensor/rms`.

```json
{"rms": 1002.47}

```

O **subscriber** (`subscriber.py`) liga-se ao mesmo broker, subscreve o tópico `sensor/rms` e imprime os valores recebidos no terminal.