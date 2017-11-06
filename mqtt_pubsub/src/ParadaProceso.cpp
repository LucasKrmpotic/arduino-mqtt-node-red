#include "ParadaProceso.h"

ParadaProceso::ParadaProceso(PubSubClient *cliente, int pin, char *topico, int alarma)
    : Componente(cliente, pin, topico){

        this->_alarma = alarma;
        pinMode(this->getPin(), INPUT);
        pinMode(this->_alarma, OUTPUT);
        digitalWrite(this->_alarma, HIGH);
    }

int ParadaProceso::leer(){
    return digitalRead(this->getPin());
}

bool ParadaProceso::esta_parado(){
    return digitalRead(this->_alarma) == false; 
}

void ParadaProceso::parar_proceso()
{
    this->accionar();
    while (this->esta_parado())
        ;
}

void ParadaProceso::togglear(){
    digitalWrite(this->_alarma, !digitalRead(this->getPin()));
}