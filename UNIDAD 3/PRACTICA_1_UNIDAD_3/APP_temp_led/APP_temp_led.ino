/*
  Fundacion Kinal
  Centro educativo tecnico laboral Kinal
  Perito en Electronica
  Seccion: A
  Curso: Taller de electronica digital y reparacion de computadoras I
  Alumno: David Alfredo del Cid Rodríguez
  Carnet: 2022482
  Proyecto:app
*/
#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>
//Constructores
OneWire ourWire(2);                //Se establece el pin 2  como bus OneWire
DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro sensor

int Tx = 7;
int Rx = 8;
SoftwareSerial BT(Tx, Rx);

char letra;
int LED  =  12;

void setup()
{
  pinMode(LED, OUTPUT);
  BT.begin(9600);
  //
  Serial.begin(9600);
  sensors.begin();   //Se inicia el sensor

}

void loop()
{

  if (BT.available())
    letra = BT.read();
  if (letra == '1')
  {
    digitalWrite(LED, 1);
  }
  if (letra == '2')
  {
    digitalWrite(LED, 0);
  }
  //
  sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
  float tempC = sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  Serial.print(tempC);
  BT.print(tempC);
  BT.print(";");

}
