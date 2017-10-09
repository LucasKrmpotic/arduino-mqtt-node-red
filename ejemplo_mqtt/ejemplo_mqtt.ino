#include <WiFiEspClient.h>
#include <WiFiEsp.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>

#define WIFI_AP "unSSID"
#define WIFI_PASSWORD "unaClave"
#define PUB_TOPIC "out"
#define SUB_TOPIC "in"
#define CLIENT_ID "arduino_client"
#define BAUD_RATE 9600

#define TOKEN "ARDUINO_DEMO_TOKEN"

char server[] = "192.168.0.22";

// Initialize the Ethernet client object
WiFiEspClient espClient;


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

PubSubClient client(server, 1883, callback, espClient);




SoftwareSerial esp8266(3, 2); // RX, TX

int status = WL_IDLE_STATUS;
unsigned long lastSend;

void setup() {
  // initialize serial for debugging
  Serial.begin(BAUD_RATE);
  lastSend = 0;

  InitWiFi();
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


//
//  static int counter = 0;
//  
//  String payload = "{\"micros\":";
//  payload += micros();
//  payload += ",\"counter\":";
//  payload += counter;
//  payload += "}";
//  
//  if (client.connected()){
//    Serial.print("Sending payload: ");
//    Serial.println(payload);
//    
//    if (client.publish(PUB_TOPIC, (char*) payload.c_str())) {
//      Serial.println("Publish ok");
//    }
//    else {
//      Serial.println("Publish failed");
//    }
//  }
//  ++counter;
//  delay(5000);
}


void InitWiFi()
{
  // initialize serial for ESP module
  esp8266.begin(9600);
  // initialize ESP module
  WiFi.init(&esp8266);
  // check for the presence of the shield
  //ESTO ESTA DE MAS
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }

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

  if(client.connect(CLIENT_ID, TOKEN, NULL)){
    if(client.subscribe(SUB_TOPIC, 1)){
      Serial.println("Se pudo suscribir");
    }
    else{
      Serial.println("No se pudo suscribir");
    }
    delay(2000);
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Connecting to Thingsboard node ...");
    // Attempt to connect (clientId, username, password)
    if ( client.connect(CLIENT_ID, TOKEN, NULL) ) {
      Serial.println( "[DONE]" );
      if(client.subscribe(SUB, 1)){
        Serial.println("Se pudo suscribir");
      }
      else{
        Serial.println("No se pudo suscribir");
      } 
    } else {
      Serial.print( "[FAILED] [ rc = " );
      Serial.print( client.state() );
      Serial.println( " : retrying in 5 seconds]" );
      // Wait 5 seconds before retrying
      delay( 5000 );
    }
  }
}

