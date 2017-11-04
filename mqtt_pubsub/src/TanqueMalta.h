#include "Componente.h"

#define MINIMO_MALTA (MAX_LECTURA * 0.3)

class TanqueMalta: public Componente{
    public:
        TanqueMalta(PubSubClient *cliente, int pin, char *topico, int alarma);
        int accionar();
        void encender_alarma();
        void apagar_alarma();
    private:
        int _alarma;
};