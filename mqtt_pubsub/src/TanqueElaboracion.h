#include "Componente.h"

class TanqueElaboracion : public Componente
{
    TanqueElaboracion(PubSubClient *cliente, int pin, char *topico);
};