#include "TanqueMalta.h"

TanqueMalta::TanqueMalta(PubSubClient *cliente, int pin, char *topico, int alarma) 
    : Componente(cliente, pin, topico){

        this->_alarma = alarma;
        pinMode(this->_alarma, OUTPUT);
        
    }
    
int TanqueMalta::accionar(){
    if(MINIMO_MALTA){
        this->encender_alarma();
    }
    else{
        this->apagar_alarma();
    }

    return Componente::accionar();
}

void TanqueMalta::encender_alarma(){
    digitalWrite(this->_alarma, HIGH);
}
void TanqueMalta::apagar_alarma(){
    digitalWrite(this->_alarma, LOW);
}