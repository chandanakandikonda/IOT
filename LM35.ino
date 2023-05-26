#include <DHT.h>

#define outPin 8
#define ledPin 13

DHT DHT_U(8,DHT11);

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  delay(2000);

  DHT_U.read();

  float t = DHT_U.readTemperature();
  float h = DHT_U.readHumidity();

  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" °C | ");
  Serial.print((t * 9.0) / 5.0 + 32.0);
  Serial.println(" °F ");
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println("% ");
  Serial.println(" ");


  if (t > 25.0) {
    digitalWrite(ledPin,HIGH);
    delay(5000);
    digitalWrite(ledPin,LOW);
    delay(500);
  } else {
    digitalWrite(ledPin,LOW);
    delay(10000);
  }
}
