#include "Componente.h"

class Valvula : public Componente
{
    public:
        Valvula(PubSubClient*, int, char*);
        int leer();
};