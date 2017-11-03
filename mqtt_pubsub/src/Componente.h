/*
    Componente de Arduino que puede publicar en un tópico MQTT lo que lee
    Recibe un cliente PubSub (para la comunicación), un número de pin, y un tópico
*/

#ifndef COMPONENTE_H
#define COMPONENTE_H

#include "Arduino.h"
#include <PubSubClient.h>

#define FALLO_ACCIONAR -1

class Componente{

    public:
        
        Componente(PubSubClient*, int, char*);
        ~Componente();
        int leer();
        virtual int accionar();
        String getTopico();
        int getPin();
    private:
        int _pin;
        char *_topico;
        PubSubClient *_cliente;
};


#endif