#include "TanqueElaboracion.h"

TanqueElaboracion::TanqueElaboracion(PubSubClient *cliente, int pin, char *topico)
    : Componente(cliente, pin, topico)
{
}