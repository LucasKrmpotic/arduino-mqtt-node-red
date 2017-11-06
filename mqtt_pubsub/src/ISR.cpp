#include "ISR.h"
#include "ParadaProceso.h"

extern ParadaProceso *parada_proceso;

void manejar_parada_proceso(){

    parada_proceso->togglear();
    
}