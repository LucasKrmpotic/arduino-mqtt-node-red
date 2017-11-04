#include "TanqueElaboracion.h"

TanqueElaboracion::TanqueElaboracion(PubSubClient *cliente, int pin, char *topico, int calefaccion)
    : Componente(cliente, pin, topico)
{

    this->_calefaccion = calefaccion;
    pinMode(this->_calefaccion, OUTPUT);
}

int TanqueElaboracion::accionar()
{
    if (MINIMO_TEMPERATURA)
    {
        this->encender_calefaccion();
    }
    else
    {
        this->apagar_calefaccion();
    }

    return Componente::accionar();
}

void TanqueElaboracion::encender_calefaccion()
{
    digitalWrite(this->_calefaccion, HIGH);
}
void TanqueElaboracion::apagar_calefaccion()
{
    digitalWrite(this->_calefaccion, LOW);
}