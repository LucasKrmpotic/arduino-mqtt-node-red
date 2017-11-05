#include "Valvula.h"

Valvula::Valvula(PubSubClient *cliente, int pin, char *topico)
    : Componente(cliente, pin, topico){
        pinMode(this->getPin(), INPUT);
    }

    int Valvula::leer(){
        return digitalRead(this->getPin());
    }