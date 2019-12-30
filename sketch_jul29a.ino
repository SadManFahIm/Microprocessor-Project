#include <SoftwareSerial.h>
#include <DHT.h>
#include <Servo.h>
Servo myservo;
#define DHTPIN 3     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11  (AM2302)
// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

int temp;
int hum;
char data = 0;

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin (9600);
  pinMode(2,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  myservo.attach(9);
digitalWrite(2,HIGH);
delay(200);
}


void loop() {
  // put your main code here, to run repeatedly:


if (Serial.available())
{
 temp= dht.readTemperature();
 hum = dht.readHumidity();  

data = Serial.read();

if(data=='A')

{
  digitalWrite(5,HIGH);
 delay(20);
 
}

else if(data=='B')

{
  digitalWrite(5,LOW);
 delay(20);
}

else if(data=='C')

{
  digitalWrite(6,HIGH);
   delay(20);
}

else if(data=='D')

{
  digitalWrite(6,LOW);
    delay(20);
}


else  if(data=='E')

{
  digitalWrite(7,HIGH);
  delay(20);
}

else if(data=='F')

{
  digitalWrite(7,LOW);
   delay(20);
}

else  if(data=='G')

{
  digitalWrite(8,HIGH);
   delay(20);
}

else   if(data=='H')

{
  digitalWrite(8,LOW);
   delay(20);
}


else if(data=='I')

{
 myservo.write(20);
    delay(1000);
}

else if(data=='J')

{
 myservo.write(70);
   delay(1000);
}


}
Serial.print("*X+"+String(temp)+"*");
Serial.print("*Y+"+String(hum)+"*");
delay(2);
}
