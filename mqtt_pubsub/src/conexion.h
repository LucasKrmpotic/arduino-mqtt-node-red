#ifndef _CONEXION_H
#define _CONEXION_H

/*Archivos que maneja conexiones a la red WiFi del módulo ESP8266*/

void InitWiFi();
void reconnect();
void callback(char*, byte*, unsigned int);





#endif