/*
    Sensor de Arduino que puede publicar en un tópico MQTT lo que lee
    Recibe un cliente PubSub (para la comunicación), un número de pin, y un tópico
*/

#ifndef SENSOR_H
#define SENSOR_H

#include "Arduino.h"
#include <PubSubClient.h>

#define FALLO_PUBLICAR -1

class Sensor{

    public:
        
        Sensor(PubSubClient*, int, char*);
        ~Sensor();
        int leer();
        int publicar();
        String getTopico();
        int getPin();
    private:
        int _pin;
        char *_topico;
        PubSubClient *_cliente;
};


#endif