#include "Componente.h"

class ParadaProceso : public Componente
{
    public:
        /*Recibe lo mismo que un Componente, más un número de pin que corresponderá al de la alarma
        para indicar que el proceso está parado o no*/
        ParadaProceso(PubSubClient*, int, char*, int);
        int leer();
        /*Detiene el proceso*/
        void parar_proceso();
        /*Indica si el proceso está parado o no*/
        bool esta_parado();
        /*Detiene el proceso si está corriendo, o lo reanuda si estaba detenido*/
        void togglear();
    private:
        int _alarma;
};

