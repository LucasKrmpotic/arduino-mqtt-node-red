#include "Componente.h"

#define MINIMO_MALTA (MAX_LECTURA * 0.3)

class TanqueMalta: public Componente{
    public:
      /*Recibe lo mismo que un Componente, más un número de pin que corresponderá al de la alarma
        para indicar si el nivel de malta está bajo o no*/
      TanqueMalta(PubSubClient*, int, char*, int);
      int accionar();
      void encender_alarma();
      void apagar_alarma();
    private:
        int _alarma;
};