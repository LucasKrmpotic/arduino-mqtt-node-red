#include "Componente.h"

#define MINIMO_TEMPERATURA 150

class TanqueElaboracion : public Componente{
    public:
        /*Recibe lo mismo que un Componente, y el pin que corresponderá a la calefacción*/
        TanqueElaboracion(PubSubClient*, int, char*, int);
        int accionar();
        void encender_calefaccion();
        void apagar_calefaccion();
    private:
        int _calefaccion;
};