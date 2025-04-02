//include the library for the temperature and humidity sensor
#include <DHT.h>;

//reassigning names to the pins
#define pump 4
#define DHTPIN 2
#define DHTTYPE DHT22

//initializing the devices
DHT dht(DHTPIN, DHTTYPE); 


void setup() {
  Serial.begin(9600);
  dht.begin();
  rtc.begin();
  last_time = millis();

 // put your setup code here, to run once:
  analogRead(sensorPin);
  //showing that the pump pin(D4) is meant to be a output pin
  pinMode(pump, OUTPUT);

}

void loop() {

  int soil_moisture =  analogRead(sensorPin);
  float temp =  dht.readTemperature();
  float humidity = dht.readHumidity();
 // put your main code here, to run repeatedly:
 Serial.print("The soil mositure value is:");
 Serial.print(soil_moisture);
 Serial.print(", The soil temperature value is:");
 Serial.print(temp);
  Serial.print(", The soil humidity level is:");
 Serial.println(humidity);
 //delay of 30 minutes
 delay(1800000);

 if ((soil_moisture > 30) && (temp > 15) && (humidity <= 25) && (abs(current_time - last_time) > 120000)){
  digitalWrite(pump,HIGH);
  current_time = millis();
  time_passed = (current_time - last_time);
  last_time = current_time;
  time = time_passed/60000;
  Serial.print("The time passed:");
  Serial.println(time);
 }
 else{
  digitalWrite(pump,LOW);
 }
}
