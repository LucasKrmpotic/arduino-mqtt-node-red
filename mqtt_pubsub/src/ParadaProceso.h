#include "Componente.h"

class ParadaProceso : public Componente
{
    public:
        ParadaProceso(PubSubClient *cliente, int pin, char *topico, int alarma);
        int accionar();
        void encender_alarma();
        void apagar_alarma();
        bool proceso_parado();
    private:
        int _alarma;
        void manejar_parada_proceso();
};

