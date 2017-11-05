#include "config.h"
#include "conexion.h"
#include "Componente.h"
#include "ParadaProceso.h"
#include "TanqueMalta.h"
#include "TanqueElaboracion.h"
#include "Valvula.h"
#include "ISR.h"

/*Definimos las variables aca, 
en el config.h estan como "extern" 
para que puedan ser accedidas desde otros archivos*/
WiFiEspClient espClient;
PubSubClient *client;
SoftwareSerial *esp8266;  
int status; 

ParadaProceso *parada_proceso;
Componente *componentes[MAX_COMPONENTES];


void setup() {
  // initialize serial for debugging
  Serial.begin(BAUD_RATE);
  
  status = WL_IDLE_STATUS;
  client = new PubSubClient(SERVER, 1883, callback, espClient);
  
  //inicialización del ESP8266 como un dispositivo de comunicación serial
  esp8266 = new SoftwareSerial(TX_ESP8266, RX_ESP8266);  
  
  InitWiFi();
  
  componentes[0] = new TanqueMalta(client, PIN_TANQUE_MALTA, TOPICO_TANQUE_MALTA, PIN_ALARMA_MALTA);
  componentes[1] = new TanqueElaboracion(client, PIN_TEMP_TANQUE, TOPICO_TEMP_TANQUE, PIN_CALEFACCION);
  componentes[2] = new Componente(client, PIN_PRESION_TANQUE, TOPICO_PRESION_TANQUE);
  componentes[3] = new Componente(client, PIN_BRILLO_TANQUE, TOPICO_BRILLO_TANQUE);
  componentes[4] = new Valvula(client, PIN_VALVULA_AGUA, TOPICO_VALVULA_AGUA);
  componentes[5] = new Valvula(client, PIN_VALVULA_MALTA, TOPICO_VALVULA_MALTA);
  
  parada_proceso = new ParadaProceso(client, PIN_PARADA_PROCESO, TOPICO_PARADA_PROCESO, PIN_ALARMA_PARADA_PROCESO);
  componentes[6] = parada_proceso;
  
  /*Asociamos la ISR a la interrupción de la parada de proceso*/
  attachInterrupt(digitalPinToInterrupt(parada_proceso->getPin()), manejar_parada_proceso, CHANGE);
  
}

void loop() {
  status = WiFi.status();
  if ( status != WL_CONNECTED) {
    while ( status != WL_CONNECTED) {
      Serial.print("Attempting to connect to WPA SSID: ");
      Serial.println(WIFI_AP);
      // Connect to WPA/WPA2 network
      status = WiFi.begin(WIFI_AP, WIFI_PASSWORD);
      delay(500);
    }
    Serial.println("Connected to AP");
  }
  
  client->loop();
  
  if(!parada_proceso->esta_parado()){
    if(client->connected()){
      for(int i=0; i<MAX_COMPONENTES; i++){
        if(componentes[i]->accionar() != FALLO_ACCIONAR){
          Serial.println("Se pudo accionar en el tópico " + componentes[i]->getTopico());
        }else{
          Serial.println("Fallo al accionar en el tópico " + componentes[i]->getTopico());
        }
      }
    }else{
      reconnect();
    }
  }else{
    parada_proceso->parar_proceso();
  }
   
  delay(1000);   
}