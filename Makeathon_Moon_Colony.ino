//temperature sensor
#include "dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to Farm water level
#define dht_apin1 A1 // Analog Pin sensor is connected to for Housing
dht DHT;

//water sensor
int sensor; //sensor variable
int led1=12; //led variable

//light sensor
int led2=11; //led variable for center 1
int led3=10; //led variable for center 2
int led4= 9; //led variable for center 3
int led5= 8; //led variable for farm 1
int led6= 7; //led variable for farm 2
int led7= 6; //led variable for farm 3
int led8= 5; //led variable for work out 1
int led9= 4; //led variable for work out 2
int led10= 3; //led variable for work out 3
int led11= 2; //led variable for housing

//pinMode
pinMode(sensor,INPUT); 
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT); //led for light sensor 
pinMode(led3, OUTPUT); //led for light sensor 
pinMode(led4, OUTPUT); //led for light sensor 

void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor

  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);}
}//end "setup()"
 
void loop(){

//Temperature sensor
    DHT.read11(dht_apin);
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    float celsius = DHT.temperature;
    float F=celsius*1.8+32;
    Serial.print("temperature = ");
    Serial.print(F); 
    Serial.println("F");

    DHT.read11(dht_apin1);
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    float celsius = DHT.temperature;
    float F=celsius*1.8+32;
    Serial.print("temperature = ");
    Serial.print(F); 
    Serial.println("F");
    delay(5000);//Wait 5 seconds before accessing sensor again.
 

  //water sensor
  sensor=analogRead(A2); // Incoming analog signal read and appointed sensor
   Serial.println(sensor)  ;   //Wrote serial port
  delay(5000); //5 second delay
  if(sensor=0)
  {
    digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else
  {
    digitalWrite(led1,LOW); // turn the led off (LOW is the voltage level) 
  }
 unsigned int Analog; //analog variable used for printing light value read by light intensity sensor

//light sensor
AnalogValue = analogRead(A3);
Serial.println(Analog);
delay(5000); //5 second delay
  if(AnalogValue<300)
  {
    digitalWrite(led2, LOW);   // turn the LED off 
    digitalWrite(led3, LOW);   // turn the LED off 
    digitalWrite(led4, LOW);   // turn the LED off 
    digitalWrite(led5, LOW);   // turn the LED off 
    digitalWrite(led6, LOW);   // turn the LED off 
    digitalWrite(led7, LOW);   // turn the LED off 
    digitalWrite(led8, LOW);   // turn the LED off 
    digitalWrite(led9, LOW);   // turn the LED off 
    digitalWrite(led10, LOW);   // turn the LED off 
    digitalWrite(led11, LOW);   // turn the LED off 
  }
  else
  {
    digitalWrite(led2, HIGH);   // turn the LED on
    digitalWrite(led3, HIGH);   // turn the LED on
    digitalWrite(led4, HIGH);   // turn the LED on
    digitalWrite(led5, HIGH);   // turn the LED on
    digitalWrite(led6, HIGH);   // turn the LED on
    digitalWrite(led7, HIGH);   // turn the LED on
    digitalWrite(led8, HIGH);   // turn the LED on
    digitalWrite(led9, HIGH);   // turn the LED on
    digitalWrite(led10, HIGH);   // turn the LED on
    digitalWrite(led11, HIGH);   // turn the LED on
  }

  
}
