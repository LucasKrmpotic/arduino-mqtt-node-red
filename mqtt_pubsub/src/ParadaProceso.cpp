#include "ParadaProceso.h"

ParadaProceso::ParadaProceso(PubSubClient *cliente, int pin, char *topico, int alarma)
    : Componente(cliente, pin, topico){

        this->_alarma = alarma;
        attachInterrupt(digitalPinToInterrupt(this->_pin), ParadaProceso::manejar_parada_proceso, CHANGE);
    }

void ParadaProceso::encender_alarma(){
    digitalWrite(this->_alarma, HIGH);
}

void ParadaProceso::apagar_alarma(){
    digitalWrite(this->_alarma, LOW);
}

bool ParadaProceso::proceso_parado(){
    return (bool)this->_alarma;
}

void manejar_parada_proceso(){

}