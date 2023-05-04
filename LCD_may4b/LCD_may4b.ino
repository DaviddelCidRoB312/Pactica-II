/*
* Fundacion Kinal
* Centro educativo tecnico laboral Kinal
* Perito en Electronica
* Seccion: A
* Curso: Taller de electronica digital y reparacion de computadoras I
* Alumno: David Alfredo del Cid Rodríguez
* Fecha: 4/05/2023
* Carnet: 2022482
* Proyecto: LCD
*/
//libreria
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

void setup() 
{
LCD_David.begin(16,2); //LCD de 16 columnas X 2 filas
LCD_David.print("David");

}

void loop() 
{
LCD_David.setCursor(0,1); //primera columna y segunda fila 
  LCD_David.setCursor(0,1);
  LCD_David.print("2022482");
}