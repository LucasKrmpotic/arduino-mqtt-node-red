/*  ----------------------------------------------------------------
    http://www.prometec.net/
    Prog_76_2
    
    Montando un servidor Web en WIFI mediante
    un WIFI esp8266 y comandos AT  
    http://www.prometec.net/servidor-web-esp8266
--------------------------------------------------------------------  
*/
#include <SoftwareSerial.h>
#define BAUD_RATE 19200

SoftwareSerial esp8266(3, 2); // RX | TX

String ordenes[]=
    {  //"AT+RST",
       "AT+CWMODE=3",
//       "AT+CIFSR" ,
       "AT+CIPMUX=1",
       "AT+CIPSERVER=1,80",
       "END"				// Para reconocer el fin de los comandos AT
    };

void setup()
{   esp8266.begin(BAUD_RATE);
    Serial.begin(BAUD_RATE); 
    delay (1000);
    int index = 0;
    while(ordenes[index] != "END")
        {  esp8266.println(ordenes[index++]);
           while ( true)
             {   String s = GetLineWIFI();
                 if ( s!= "") Serial.println(s);
                 if ( s.startsWith("no change"))   
                         break;
                 if ( s.startsWith("OK"))   
                         break;
                 if ( s.startsWith("ready"))   
                         break;
                // if (millis()-T >10000) break;  
             }
          Serial.println("....................");
      } 
}

void loop() 
{  while (esp8266.available() >0 )
    {  char c = esp8266.read();
       if (c == 71)   //G
          {   Serial.println("Enviada Web Request");
              webserver();
              delay(500);
          }
   }
   if (esp8266.available())
         { char c = esp8266.read() ;
           Serial.print(c);
         }
     if (Serial.available())
         {  char c = Serial.read();
            Serial.print(c);
            esp8266.print(c);
         }
}
//Envio de la pagina al WEB server
void http(String output)
{
    esp8266.print("AT+CIPSEND=0,");              // AT+CIPSEND=0, num
    esp8266.println(output.length());
    if (esp8266.find(">"))                       // Si recibimos la peticion del mensaje
       {    Serial.println(output);
            esp8266.println(output);            //Aqui va el string hacia el WIFI 
            delay(10);
            while ( esp8266.available() > 0 ) 
              { if (  esp8266.find("SEND OK") )    // Busca el OK en la respuesta del wifi
                      break; 
              }
       }
}
//Código insertado al WEb server
void webserver(void) 
    {    http("<!DOCTYPE HTML>");
         http("<html>");
         http("<head><title>LECTURAS ANALOGICAS.</title>");
         http("<meta http-equiv=\"refresh\" content=\"10\"></head>");
         http("<body><h1> Situacion Ambiente</h1>");
  
         for (int analogChannel = 0; analogChannel < 6; analogChannel++) 
         {
            int sensorReading = analogRead(analogChannel);
            http("analog input ");
            http( String(analogChannel));
            http(" is ");
            http(String(sensorReading));
            http("<br />");
          }
        http("<p><em> La pagina se actualiza cada 10 segundos.</em></p></body></html>");

       delay(1);
       esp8266.println("AT+CIPCLOSE=0");
       //delay(500);
    }
    
String GetLineWIFI()
   {   String S = "" ;
       if (esp8266.available())
          {    char c = esp8266.read(); ;
                while ( c != '\n' )            //Hasta que el caracter sea intro
                  {     S = S + c ;
                        delay(25) ;
                        c = esp8266.read();
                   }
                 return( S ) ;
          }
   }


