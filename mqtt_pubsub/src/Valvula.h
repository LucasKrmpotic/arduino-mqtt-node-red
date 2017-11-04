#include "Componente.h"

class Valvula : public Componente
{
    public:
        Valvula(PubSubClient *cliente, int pin, char *topico);
};