/*
* Fundacion Kinal
* Centro educativo tecnico laboral Kinal
* Perito en Electronica
* Seccion: A
* Curso: Taller de electronica digital y reparacion de computadoras I
* Alumno: David Alfredo del Cid Rodríguez
* Carnet: 2022482
* Proyecto: LUCES del AUTO FANTASTICO
*/

void setup()
{
for(int i =2; i<=11; i++) //del led 1 al led 8
{  
pinMode(i,OUTPUT); //declarar pine como salida
}
}
void loop()
{
for(int i =2; i<=11; i++)
{
digitalWrite(i,HIGH); //enciende led
delay(500);        //tiempo :v
digitalWrite(i,LOW);  //apaga led
}  
for(int i =11; i>=3; i--)
{
digitalWrite(i,HIGH); //enciende led
delay(500);        //tiempo :v
digitalWrite(i,LOW);  //apaga
}
}
