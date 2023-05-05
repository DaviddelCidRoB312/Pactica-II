/*
* Fundacion Kinal
* Centro educativo tecnico laboral Kinal
* Perito en Electronica
* Seccion: A
* Curso: Taller de electronica digital y reparacion de computadoras I
* Alumno: David Alfredo del Cid Rodríguez
* Fecha: 5/05/2023
* Carnet: 2022482
* Proyecto: CONTADOR DE AFORO CON ANIMACION
*/
// LCD
#include <LiquidCrystal.h>
//dfinir
#define RS 6
#define Enable 7
#define D4 2
#define D5 3
#define D6 4
#define D7 5
// CONSTRUCCION
LiquidCrystal LCD_David(RS, Enable, D4, D5, D6, D7); //ME PERMITE USAR EL LCD
byte nose1[] = {
  B00000,
  B01110,
  B01110,
  B01110,
  B00101,
  B01110,
  B10100,
  B01010
};

byte nose2[] = {
  B01110,
  B01110,
  B01110,
  B00100,
  B01110,
  B10101,
  B01110,
  B01010
};
int a=0;
// define variables
long duration;
int distance;
void Ultrasonico(int trig, int echo) ;
void sonido(int buzzer);
/////////////////////////////////////////////////////////////
void setup() {
LCD_David.begin(16,2); //Objeto de una LCD de 16 columnas x 2 filas
LCD_David.print("No Personas:0");

}
////////////////////////////////////////////////////////////////////////
void loop() {
LCD_David.setCursor(0,1);
Ultrasonico(8, 9);
sonido(10);
}
void Ultrasonico(int trig, int echo)//ULTRASONICO
{
pinMode(trig, OUTPUT); //Establece el trigPin como Salida
pinMode(echo, INPUT); // Establece el echoPin como Entrada
Serial.begin(9600); // Inicia la comunicación serie
int lecturaecho =digitalRead(echo);//lectura eco sumador
// Clears the trigPin
digitalWrite(trig, LOW);
delayMicroseconds(2);
// Pone el trigPin en estado HIGH durante 10 micro segundos
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
// Lee el echoPin, devuelve el tiempo de viaje de la onda sonora en microsegundos
duration = pulseIn(echo, HIGH);
// Calcular la distancia
distance= duration/59;
// Imprime la distancia en el monitor serie
Serial.print(String(distance));
Serial.println(" cm");
delay(400);
}
void sonido(int buzzer)//BUZZER
{
  pinMode(buzzer, OUTPUT); // definimos la variable ZumbadorPin como una salida.

  if(distance<11 && distance >0)
{
a++;
////////////////////////////////////////////////////
if(distance<11 && a==1)//1
{
LCD_David.begin(16,2); //LCD de 16 columnas X 2 filas
LCD_David.print("No Personas:1");
a++;  
}
if(distance<11 && a==3)//2
{
 LCD_David.begin(16,2); //LCD de 16 columnas X 2 filas
LCD_David.print("No Personas:2");
a++;
}
if(distance<11 && a==7)//3
{
  LCD_David.begin(16,2); //LCD de 16 columnas X 2 filas
LCD_David.print("No Personas:3");
a++;
}
if(distance<11 && a==9)//4
{
  LCD_David.begin(16,2); //LCD de 16 columnas X 2 filas
LCD_David.print("No Personas:4");
a++;
}
if(distance<11 && a==11)//5
{
  LCD_David.begin(16,2); //LCD de 16 columnas X 2 filas
LCD_David.print("No Personas:5");
a++;
}
if(distance<11 && a==13)//6
{
  LCD_David.begin(16,2); //LCD de 16 columnas X 2 filas
LCD_David.print("No Personas:6");
a++;
}
if(distance<11 && a==15)//7
{
  LCD_David.begin(16,2); //LCD de 16 columnas X 2 filas
LCD_David.print("No Personas:7");
a++;
}
if(distance<11 && a==17)//8
{
  LCD_David.begin(16,2); //LCD de 16 columnas X 2 filas
LCD_David.print("No Personas:8");
a++;
}
if(distance<11 && a==19)//9
{
  LCD_David.begin(16,2); //LCD de 16 columnas X 2 filas
LCD_David.print("No Personas:9");
a++;
}

if(distance<11 && a==21)//10
{
  LCD_David.begin(16,2); //LCD de 16 columnas X 2 filas
LCD_David.print("No Personas:10");
a++;
}

if(distance<11 && a==23)//11
{
  LCD_David.begin(16,2); //LCD de 16 columnas X 2 filas
LCD_David.print("No Personas:11");
a++;
}

if(distance<11 && a==25)//12
{
  LCD_David.begin(16,2); //LCD de 16 columnas X 2 filas
LCD_David.print("No Personas:12");
a++;
}

if(distance<11 && a==27)//13
{
  LCD_David.begin(16,2); //LCD de 16 columnas X 2 filas
LCD_David.print("No Personas:13");
a++;
}

if(distance<11 && a==29)//14
{
  LCD_David.begin(16,2); //LCD de 16 columnas X 2 filas
LCD_David.print("No Personas:14");
a++;
}
if(distance<11 && a==31)//15
{
  LCD_David.begin(16,2); //LCD de 16 columnas X 2 filas
LCD_David.print("No Personas:15");
a++;
}
if(distance<11 && a==33)//16
{
LCD_David.begin(16,2); //LCD de 16 columnas X 2 filas
LCD_David.print("No Personas:16");
tone(buzzer, 800.755, 5000);
LCD_David.setCursor(0,1);  //Primera columna y segunda fila  
LCD_David.write(1);
delay(500);
LCD_David.setCursor(0,1);
LCD_David.write(2);
delay(500);
LCD_David.createChar(1,nose1);
LCD_David.createChar(2,nose2);

}
if(distance<11 && a==33)
{
LCD_David.setCursor(0,1);  //Primera columna y segunda fila  
LCD_David.write(1);
delay(500);
LCD_David.setCursor(0,1);
LCD_David.write(2);
delay(500);
LCD_David.createChar(1,nose1);
LCD_David.createChar(2,nose2);

}
}//if grtande
}