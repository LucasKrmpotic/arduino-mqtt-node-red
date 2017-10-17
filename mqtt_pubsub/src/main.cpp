#include "config.h"

// String valor_tanque_malta;

void setup() {
  // initialize serial for debugging
  Serial.begin(BAUD_RATE);
  
  pinMode(PIN_VALVULA_AGUA, INPUT);
  pinMode(PIN_VALVULA_MALTA, INPUT);
  
  InitWiFi();
  //NO SE ESTA USANDO
  // pinMode(BUZZER_PIN, OUTPUT);
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
  
  if ( !client.connected() ) {
    reconnect();
  }
  
  client.loop();


  /*Leemos el potenciometro del tanque de malta y lo publicamos en su topico*/
  if(client.connected()){
    if (client.publish(TOPICO_TANQUE_MALTA, (char *) String(analogRead(PIN_TANQUE_MALTA)).c_str())
        && client.publish(TOPICO_TEMP_TANQUE, (char *) String(analogRead(PIN_TEMP_TANQUE)).c_str())
        && client.publish(TOPICO_PRESION_TANQUE, (char *) String(analogRead(PIN_PRESION_TANQUE)).c_str())
        && client.publish(TOPICO_BRILLO_TANQUE, (char *) String(analogRead(PIN_BRILLO_TANQUE)).c_str())
        && client.publish(TOPICO_VALVULA_AGUA, (char *) leer_valvula(PIN_VALVULA_AGUA).c_str())
        && client.publish(TOPICO_VALVULA_MALTA, (char *) leer_valvula(PIN_VALVULA_MALTA).c_str())){
      Serial.println("PUBLICANDO");
    }else{
      Serial.println("FALLO AL PUBLICAR");
    }
  }
  
  

  delay(1000);   
}

void InitWiFi()
{
  // initialize serial for ESP module
  esp8266.begin(9600);
  // initialize ESP module
  WiFi.init(&esp8266);

  Serial.println("Connecting to AP ...");
  // attempt to connect to WiFi network 
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(WIFI_AP);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(WIFI_AP, WIFI_PASSWORD);
    delay(500);
  }
  Serial.println("Connected to AP");

  
  /*nos suscribimos al topico SUB_TOPIC
  NO SE ESTA USANDO*/
  // if(client.connect(CLIENT_ID, TOKEN, NULL)){
  //   if(client.subscribe(SUB_TOPIC, 1)){
  //     Serial.println("Se pudo suscribir al topico " + String("\"") + String(SUB_TOPIC) + String("\"\n"));
  //   }
  //   else{
  //     Serial.println("No se pudo suscribir");
  //   }
  //   delay(2000);
  // }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Connecting to Thingsboard node ...");
    // Attempt to connect (clientId, username, password)
    if ( client.connect(CLIENT_ID, TOKEN, NULL) ) {
      Serial.println( "[DONE]" );

      /*NO SE ESTA USANDO*/
      // if(client.subscribe(SUB_TOPIC, 1)){
      //   Serial.print("Se pudo suscribir al topico " + String("\"") + String(SUB_TOPIC) + String("\""));
      //   }
      // else{
      //   Serial.println("No se pudo suscribir");
      // }

    } else {
      Serial.print( "[FAILED] [ rc = " );
      Serial.print( client.state() );
      Serial.println( " : retrying in 5 seconds]" );
      // Wait 5 seconds before retrying
      delay( 5000 );
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {}
//     Serial.print("Message arrived [");
//     Serial.print(topic);
//     Serial.print("] ");
//     for (int i=0;i<length;i++) {
//       Serial.print((char)payload[i]);
//     }
//     Serial.println();
//     llegoMensaje = true;
//   }


