#include "ParadaProceso.h"

ParadaProceso::ParadaProceso(PubSubClient *cliente, int pin, char *topico, int alarma)
    : Componente(cliente, pin, topico){

        this->_alarma = alarma;
        pinMode(this->getPin(), INPUT);
        pinMode(this->_alarma, OUTPUT);
        digitalWrite(this->_alarma, LOW);
    }

int ParadaProceso::leer(){
    return digitalRead(this->getPin());
}

void ParadaProceso::parar_proceso(){
    while (this->esta_parado())
        ;
}

bool ParadaProceso::esta_parado(){
    return digitalRead(this->_alarma) == LOW; 
}

int ParadaProceso::getPinAlarma(){
    return this->_alarma;
}