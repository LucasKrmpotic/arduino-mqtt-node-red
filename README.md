# arduino-mqtt-node-red

Proyecto realizado para el curso de **IoTA** de la **Escuela de Informática Patagónica 2017** dictado durante el periodo 18/09/2017 al 22/09/2017.

Dictado por:
- Mg. Ricardo López

Integrantes:
- Luciano Serruya Aloisi
- Lucas Krmpotic

**El directorio del proyecto es `mqtt_pubsub`**

[Demo de funcionamiento](https://www.youtube.com/watch?v=uqkqxmfkv90)

--- 

### docker-compose

El archivo `docker-compose.yml` define dos servicios:

- Broker MQTT (puerto 1883)
- Node-RED (puerto 1880)

Para levantar los contenedores, ejecutar el comando

```bash
docker-compose up -d
```

Para eliminar los contenedores y la red, ejecutar el siguiente comando (estando dentro del mismo directorio donde está el `docker-compose.yml`)

```bash
docker-compose down
```
