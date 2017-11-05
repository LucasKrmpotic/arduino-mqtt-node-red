#include "Componente.h"

Componente::Componente(PubSubClient *cliente, int pin, char *topico){

    this->_cliente = cliente;
    this->_pin = pin;
    this->_topico = (char *) malloc(strlen(topico) + 1);
    strcpy(this->_topico, topico);

}

Componente::~Componente(){
    free(this->_topico);
}

int Componente::leer(){
    return analogRead(this->_pin);
}

int Componente::accionar(){
    int _lectura = this->leer();

    return this->_cliente->publish(
        this->_topico, String(_lectura, DEC).c_str()
    ) == true ? _lectura : FALLO_ACCIONAR;
}

String Componente::getTopico(){
    return String(this->_topico);
}

int Componente::getPin(){
    return this->_pin;
}