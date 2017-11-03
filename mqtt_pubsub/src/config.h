#ifndef _CONFIG_H
#define _CONFIG_H

#include <Arduino.h>
#include <WiFiEspClient.h>
#include <WiFiEsp.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>

#define MAX_COMPONENTES 6

#define WIFI_AP "SerruyaCisco(noConectar)"
#define WIFI_PASSWORD "Serruya5000050000Cisco"
#define CLIENT_ID "arduino_client"
#define TOKEN "ARDUINO_DEMO_TOKEN"
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
#define PIN_TANQUE_MALTA    2
#define PIN_TEMP_TANQUE     3
#define PIN_PRESION_TANQUE  4
#define PIN_BRILLO_TANQUE   5
#define PIN_VALVULA_MALTA   11
#define PIN_VALVULA_AGUA    10
#define PIN_PARADA_PROCESO  9
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