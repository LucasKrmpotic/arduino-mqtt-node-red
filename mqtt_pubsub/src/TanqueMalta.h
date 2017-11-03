#include "Componente.h"

class TanqueMalta: public Componente{
    TanqueMalta(PubSubClient *cliente, int pin, char *topico);
};