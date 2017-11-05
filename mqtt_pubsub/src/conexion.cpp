#include "config.h"


void InitWiFi()
{
  // initialize serial for ESP module
  esp8266->begin(9600);
  // initialize ESP module
  WiFi.init(esp8266);

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

  
}

void reconnect() {
  // Loop until we're reconnected
  while (!client->connected()) {
    Serial.print("Connecting to Thingsboard node ...");
    // Attempt to connect (clientId, username, password)
    if ( client->connect(CLIENT_ID, TOKEN, NULL) ) {
      Serial.println( "[DONE]" );


    } else {
      Serial.print( "[FAILED] [ rc = " );
      Serial.print( client->state() );
      Serial.println( " : retrying in 5 seconds]" );
      // Wait 5 seconds before retrying
      delay( 5000 );
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {}