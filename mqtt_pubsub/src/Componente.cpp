#include "Componente.h"

Componente::Componente(PubSubClient *cliente, int pin, char *topico){

    this->_cliente = cliente;
    this->_pin = pin;
    pinMode(this->_pin, INPUT);
    this->_topico = (char *) malloc(strlen(topico) + 1);
    strcpy(this->_topico, topico);

}

Componente::~Componente(){
    /*Destructor del objeto, libera la memoria pedida para el tópico*/
    free(this->_topico);
}

int Componente::leer(){
    /*Lee desde el el pin que tiene asignado*/
    return analogRead(this->_pin);
}

int Componente::accionar(){
    /*Publica en el tópico MQTT que tiene asignado lo leído desde su pin.
    Devuelve el valor publicado, o un FALLO_ACCIONAR si no pudo*/

    int _lectura = this->leer();

    return this->_cliente->publish(
        this->_topico, String(_lectura, DEC).c_str()
    ) == true ? _lectura : FALLO_ACCIONAR;
}

String Componente::getTopico(){
    /*Devuelvo su tópico*/
    return String(this->_topico);
}

int Componente::getPin(){
    /*Devuelve su pin*/
    return this->_pin;
}