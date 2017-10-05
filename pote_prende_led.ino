#define POTE 2
#define LED 6
#define ESPERA 1000
#define BAUD_RATE 9600
#define MINIMO 1023 * 0.3

/*
    circuito:
        - potenciómetro conectado al pin analógico 2 (A2)
        - led conectado al pin digital 6 (puede ser cualquiera, no estamos utilizando PWM)
*/

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(BAUD_RATE);
  int val = ESPERA;
}

void loop() {

  val = analogRead(POTE);
  if (val < MINIMO){
    digitalWrite(LED, LOW);  
  }else digitalWrite(LED, HIGH);
  
}
