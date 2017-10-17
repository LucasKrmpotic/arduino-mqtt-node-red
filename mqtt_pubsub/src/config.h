#ifndef _CONFIG_H
#define _CONFIG_H

#include <Arduino.h>

/*PINES A UTILIZAR*/

//NO SE ESTA USANDO
// #define BUZZER_PIN 12

#define MINIMO_TANQUE_MALTA 1023 * 0.3

#include <WiFiEspClient.h>
#include <WiFiEsp.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>

#define WIFI_AP "SerruyaCisco(noConectar)"
#define WIFI_PASSWORD "Serruya5000050000Cisco"
#define CLIENT_ID "arduino_client"
#define TOKEN "ARDUINO_DEMO_TOKEN"
#define SERVER "192.168.1.119"

/*TOPICOS*/
#define PUB_TOPIC "out"
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
#define TX_ESP8266          13
#define RX_ESP8266          12

/*NO SE ESTA USANDO*/
// #define SUB_TOPIC "in"
// boolean llegoMensaje = false;



#define BAUD_RATE 9600



void InitWiFi();
void reconnect();

extern WiFiEspClient espClient;
extern PubSubClient *client;
extern SoftwareSerial *esp8266;  
extern int status; 


#endif