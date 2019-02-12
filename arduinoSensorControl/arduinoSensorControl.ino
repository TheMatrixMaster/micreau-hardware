#include <OneWire.h>
#include <DallasTemperature.h>
#include <dht.h>

#define dht_apin 6
dht DHT;
#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

 float Celcius=0;
 float Fahrenheit=0;
void setup(void)
{
  
  Serial.begin(9600);
  sensors.begin();
}

void loop(void)
{ 
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  Fahrenheit=sensors.toFahrenheit(Celcius);
  DHT.read11(dht_apin);

  Serial.print("Y");
  Serial.print(DHT.temperature);
  Serial.print("C ");
  
  Serial.print(DHT.humidity);
  Serial.print("% ");
  
  Serial.print(Celcius);
  Serial.print("C");
  Serial.println("Y");

//  Serial.print(Fahrenheit);
//  Serial.println("F ");
  delay(5000);
}
