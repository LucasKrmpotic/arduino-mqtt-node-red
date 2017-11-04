#include "Componente.h"

#define MINIMO_TEMPERATURA 150

class TanqueElaboracion : public Componente{
    public:
        TanqueElaboracion(PubSubClient *cliente, int pin, char *topico, int calefaccion);
        int accionar();
        void encender_calefaccion();
        void apagar_calefaccion();
    private:
        int _calefaccion;
};