#include "Valvula.h"

Valvula::Valvula(PubSubClient *cliente, int pin, char *topico)
    : Componente(cliente, pin, topico)
{
}