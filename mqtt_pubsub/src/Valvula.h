#include "Componente.h"

class Valvula : public Componente
{
    Valvula(PubSubClient *cliente, int pin, char *topico);
};