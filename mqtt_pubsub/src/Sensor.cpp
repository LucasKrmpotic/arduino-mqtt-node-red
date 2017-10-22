#include "Sensor.h"

Sensor::Sensor(PubSubClient *cliente, int pin, char *topico){

    this->_cliente = cliente;
    this->_pin = pin;
    pinMode(this->_pin, INPUT);
    this->_topico = (char *) malloc(strlen(topico) + 1);
    strcpy(this->_topico, topico);

}

Sensor::~Sensor(){
    /*Destructor del objeto, libera la memoria pedida para el tópico*/
    free(this->_topico);
}

int Sensor::leer(){
    /*Lee desde el el pin que tiene asignado*/
    return analogRead(this->_pin);
}

int Sensor::publicar(){
    /*Publica en el tópico MQTT que tiene asignado lo leído desde su pin.
    Devuelve el valor publicado, o un FALLO_PUBLICAR si no pudo*/

    int _lectura = this->leer();

    return this->_cliente->publish(
        this->_topico, String(_lectura, DEC).c_str()
    ) == true ? _lectura : FALLO_PUBLICAR;
}

String Sensor::getTopico(){
    /*Devuelvo su tópico*/
    return String(this->_topico);
}

int Sensor::getPin(){
    /*Devuelve su pin*/
    return this->_pin;
}