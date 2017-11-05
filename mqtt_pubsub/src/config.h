#ifndef _CONFIG_H
#define _CONFIG_H

#include <Arduino.h>
#include <WiFiEspClient.h>
#include <WiFiEsp.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>

//Maxima cantidad de componentes (sensores, actuadores, ...) utilizados
#define MAX_COMPONENTES 7

/*Nombre de la red a conectarse y contrasenia*/
#define WIFI_AP ""
#define WIFI_PASSWORD ""

/*ID y Token con el cual va a publicar la placa*/
#define CLIENT_ID "arduino_client"
#define TOKEN "ARDUINO_DEMO_TOKEN"

/*IP del broker MQTT*/
#define SERVER "192.168.0.22"

/*TOPICOS*/
#define TOPICO_TANQUE_MALTA "tanque_malta"
#define TOPICO_TEMP_TANQUE "temp_tanque_elab"
#define TOPICO_PRESION_TANQUE "presion_tanque_elab"
#define TOPICO_BRILLO_TANQUE "brillo_tanque_elab"
#define TOPICO_VALVULA_MALTA "valvula_malta"
#define TOPICO_VALVULA_AGUA "valvula_agua"
#define TOPICO_PARADA_PROCESO "parada_proceso"

/*PINES*/
#define PIN_TANQUE_MALTA    A2
#define PIN_TEMP_TANQUE     A3
#define PIN_PRESION_TANQUE  A4
#define PIN_BRILLO_TANQUE   A5
#define PIN_VALVULA_MALTA   11
#define PIN_VALVULA_AGUA    10
#define PIN_PARADA_PROCESO  2

#define PIN_ALARMA_PARADA_PROCESO   7 
#define PIN_ALARMA_MALTA            6
#define PIN_CALEFACCION             5

//Pin TX del ESP8266 tiene que ir al pin 13 del Arduino
#define TX_ESP8266          13
//Pin RX del ESP8266 tiene que ir al pin 12 del Arduino
#define RX_ESP8266          12

#define BAUD_RATE 9600

void InitWiFi();
void reconnect();

extern WiFiEspClient espClient;
extern PubSubClient *client;
extern SoftwareSerial *esp8266;  
extern int status; 


#endif