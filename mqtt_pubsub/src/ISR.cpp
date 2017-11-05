#include "ISR.h"
#include "ParadaProceso.h"

extern ParadaProceso *parada_proceso;

void manejar_parada_proceso(){

    digitalWrite(parada_proceso->getPinAlarma(), !digitalRead(parada_proceso->getPin()));
    
}