#include "config.h"
#include "conexion.h"

/*Definimos las variables aca, 
en el config.h estan como "extern" 
para que puedan ser accedidas desde otros archivos*/
WiFiEspClient espClient;
PubSubClient *client;
SoftwareSerial *esp8266;  
int status; 

String leer_valvula(int);

void setup() {
  // initialize serial for debugging
  Serial.begin(BAUD_RATE);
  

  status = WL_IDLE_STATUS;
  client = new PubSubClient(SERVER, 1883, callback, espClient);
  esp8266 = new SoftwareSerial(RX_ESP8266, TX_ESP8266);  
  
  pinMode(PIN_VALVULA_AGUA, INPUT);
  pinMode(PIN_VALVULA_MALTA, INPUT);
  
  InitWiFi();
  //NO SE ESTA USANDO
  // pinMode(BUZZER_PIN, OUTPUT);
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
  
  if ( !client->connected() ) {
    reconnect();
  }
  
  client->loop();
  
  
  /*Leemos el potenciometro del tanque de malta y lo publicamos en su topico*/
  if(client->connected()){
    if (client->publish(TOPICO_TANQUE_MALTA, (char *) String(analogRead(PIN_TANQUE_MALTA)).c_str())
    && client->publish(TOPICO_TEMP_TANQUE, (char *) String(analogRead(PIN_TEMP_TANQUE)).c_str())
    && client->publish(TOPICO_PRESION_TANQUE, (char *) String(analogRead(PIN_PRESION_TANQUE)).c_str())
    && client->publish(TOPICO_BRILLO_TANQUE, (char *) String(analogRead(PIN_BRILLO_TANQUE)).c_str())
    && client->publish(TOPICO_VALVULA_AGUA, (char *) leer_valvula(PIN_VALVULA_AGUA).c_str())
    && client->publish(TOPICO_VALVULA_MALTA, (char *) leer_valvula(PIN_VALVULA_MALTA).c_str())){
      Serial.println("PUBLICANDO");
    }else{
      Serial.println("FALLO AL PUBLICAR");
    }
  }
  
  
  
  delay(1000);   
}

String leer_valvula(int pin){
  int lectura = digitalRead(pin);
  // if(lectura == HIGH){
  //   Serial.println("CERRADA");
  // }else{
  //   Serial.println("ABIERTA");
  // }
  Serial.println(lectura);
  return digitalRead(pin) == HIGH ? "Cerrada" : "Abierta";
}