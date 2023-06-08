/*
  Fundacion Kinal
  Centro educativo tecnico laboral Kinal
  Perito en Electronica
  Seccion: A
  Curso: Taller de electronica digital y reparacion de computadoras I
  Alumno: David Alfredo del Cid Rodríguez
  Carnet: 2022482
  Proyecto:INTERRUPCIONES POR MEDIO DE HARDWARE
*/
// LIBRERIAS
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Ticker.h>  //esta libreria me permite hacer uso del timer
// PINES
#define ONE_WIRE_BUS 2
#define boton_arduino 3  //led on board, que posee mi arduino
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
//Funciones de ISR
void isr_boton(void);
//Variables
volatile static bool estado_boton;
//Constructores
Ticker isr_accion_boton(isr_boton, 3000); //cada tres segundos se encendera/apagara el led del pin 13;
void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
  pinMode(boton_arduino, INPUT);
  isr_accion_boton.start();   //Iniciando la interrupción que esperaria se repitiera cada 3 segundos
}

void loop(void)
{
  sensors.requestTemperatures(); // TEMPERATURA
  float tempC = sensors.getTempCByIndex(0);
  if (tempC != DEVICE_DISCONNECTED_C)
  {
    Serial.print("TEMPERATURA:");
    Serial.println(tempC);
    delay(650);
    ///ticker
    isr_accion_boton.update();
  }
}
void isr_boton(void)
{
  estado_boton = digitalRead(boton_arduino); //leo el estado digital del pin que estoy usando como salida.
  if ( estado_boton == HIGH)
  {
    Serial.println("apagado");
  }
  else if( estado_boton == LOW);
  {
    Serial.println("encendido");
  }
}//VOID isr_boton(void)
