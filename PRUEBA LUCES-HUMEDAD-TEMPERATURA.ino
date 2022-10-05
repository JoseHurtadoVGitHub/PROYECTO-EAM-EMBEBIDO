#include <dummy.h>
#include "DHT.h"

//Sensor de temperatura y humedad 
#define DHTPIN 13
#define DHTTYPE DHT11


#define LED_UNO 15
#define LED_DOS 4
#define LED_TRES 19
#define LED_CUATRO 23


#define UPLOAD_SPEED 115200

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(UPLOAD_SPEED);
  pinMode(LED_UNO, OUTPUT);
  pinMode(LED_DOS, OUTPUT);
  pinMode(LED_TRES, OUTPUT);
  pinMode(LED_CUATRO, OUTPUT);
  dht.begin();
  
}




// the loop function runs over and over again forever
void loop() {
  Serial.println("Starting...");

  digitalWrite(LED_UNO, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000); 
  
  digitalWrite(LED_DOS, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);

  digitalWrite(LED_TRES, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);

  digitalWrite(LED_CUATRO, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250); 
  
                                 // wait for a second
  
  //Apagado 🙄

  digitalWrite(LED_UNO, LOW);    // turn the LED off by making the voltage LOW
  delay(300);
  digitalWrite(LED_DOS, LOW);    // turn the LED off by making the voltage LOW
  delay(250);
  digitalWrite(LED_TRES, LOW);    // turn the LED off by making the voltage LOW
  delay(250); 
  digitalWrite(LED_CUATRO, LOW);    // turn the LED off by making the voltage LOW
  delay(250); 
  

  // wait for a second
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (isnan(h) || isnan(t)) {
  Serial.println(F("Failed to read from DHT sensor!"));
  return;
  }
  
  Serial.print(F("Humedad: "));
  Serial.print(h);
  Serial.print(F("% Temperatura: "));
  Serial.print(t);
  Serial.println(F("°C "));

  Serial.println("..Ending");
}

