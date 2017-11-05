/*
    Componente de Arduino que puede publicar en un tópico MQTT lo que lee
    Recibe un cliente PubSub (para la comunicación), un número de pin, y un tópico
*/

#ifndef COMPONENTE_H
#define COMPONENTE_H

#include "Arduino.h"
#include <PubSubClient.h>

#define FALLO_ACCIONAR -1
#define MAX_LECTURA 658

class Componente{
    public:
        /*Constructor, recibe el cliente PubSub, un número de pin, y un tópico MQTT*/
        Componente(PubSubClient*, int, char*);
        /*Destructor del objeto, libera la memoria pedida para el tópico*/
        ~Componente();
        /*Lectura del pin*/
        virtual int leer();
        /*Acción que va a realizar cada componente, principalmente leer su pin y publicar en el tópico
        Devuelve el valor publicado, o un FALLO_ACCIONAR si no pudo*/
        virtual int accionar();
        /*Devuelve su tópico*/
        String getTopico();
        /*Devuelve su número de pin*/
        int getPin();
    private:
        int _pin;
        char *_topico;
        PubSubClient *_cliente;
};


#endif