#include "config.h"
#include "conexion.h"
#include "Sensor.h"

/*Definimos las variables aca, 
en el config.h estan como "extern" 
para que puedan ser accedidas desde otros archivos*/
WiFiEspClient espClient;
PubSubClient *client;
SoftwareSerial *esp8266;  
int status; 

Sensor *sensores[MAX_SENSORES];


void setup() {
  // initialize serial for debugging
  Serial.begin(BAUD_RATE);
  
  status = WL_IDLE_STATUS;
  client = new PubSubClient(SERVER, 1883, callback, espClient);
  
  //inicialización del ESP8266 como un dispositivo de comunicación serial
  esp8266 = new SoftwareSerial(TX_ESP8266, RX_ESP8266);  
  
  pinMode(PIN_VALVULA_AGUA, INPUT);
  pinMode(PIN_VALVULA_MALTA, INPUT);
  
  InitWiFi();

  sensores[0] = new Sensor(client, PIN_TANQUE_MALTA, TOPICO_TANQUE_MALTA);
  sensores[1] = new Sensor(client, PIN_TEMP_TANQUE, TOPICO_TEMP_TANQUE);
  sensores[2] = new Sensor(client, PIN_PRESION_TANQUE, TOPICO_PRESION_TANQUE);
  sensores[3] = new Sensor(client, PIN_BRILLO_TANQUE, TOPICO_BRILLO_TANQUE);
  sensores[4] = new Sensor(client, PIN_VALVULA_AGUA, TOPICO_VALVULA_AGUA);
  sensores[5] = new Sensor(client, PIN_VALVULA_MALTA, TOPICO_VALVULA_MALTA);

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
  
  
  /*Leemos el potenciometro del tanque de malta y lo publicamos en su topico*/
  if(client->connected()){
    for(int i=0; i<MAX_SENSORES; i++){
      if(sensores[i]->publicar() != FALLO_PUBLICAR){
        Serial.println("Se pudo publicar en el tópico " + sensores[i]->getTopico());
      }else{
        Serial.println("Fallo al publicar en el tópico " + sensores[i]->getTopico());
      }
    }
  }else{
    reconnect();
  }
  
  delay(1000);   
}