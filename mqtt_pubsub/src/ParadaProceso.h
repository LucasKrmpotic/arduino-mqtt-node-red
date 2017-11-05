#include "Componente.h"

class ParadaProceso : public Componente
{
    public:
        /*Recibe lo mismo que un Componente, más un número de pin que corresponderá al de la alarma
        para indicar que el proceso está parado o no*/
        ParadaProceso(PubSubClient*, int, char*, int);
        int leer();
        void parar_proceso();
        bool esta_parado();
        int getPinAlarma();
    private:
        int _alarma;
};

