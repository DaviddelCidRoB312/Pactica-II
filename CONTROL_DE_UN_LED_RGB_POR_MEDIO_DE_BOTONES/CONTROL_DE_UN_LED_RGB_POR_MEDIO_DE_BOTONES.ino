/*
* Fundacion Kinal
* Centro educativo tecnico laboral Kinal
* Perito en Electronica
* Seccion: A
* Curso: Taller de electronica digital y reparacion de computadoras I
* Alumno: David Alfredo del Cid Rodríguez
* Carnet: 2022482
* Proyecto: CONTROL DE UN LED RGB POR MEDIO DE BOTONES
*/
#define BOTON1 2 //boton amarillo 
#define BOTON2 3//boton verde
#define LEDROJO  4 // rojo
#define LEDVERDE 5 // verde
#define LEDAZUL  6 //  azul
#define entrada(pin) pinMode(pin, INPUT)
#define salida(pin) pinMode (pin, OUTPUT)
#define alto(pin) digitalWrite(pin, HIGH)
#define bajo(pin) digitalWrite(pin, LOW)
 //Macro para apagar un pin

void setup()
{
  entrada(BOTON1);
  entrada(BOTON2);
  salida(LEDROJO);
  salida(LEDVERDE);
  salida(LEDAZUL);
}
void loop() 
{
bool lectura_boton1 = digitalRead(BOTON1);
bool lectura_boton2 = digitalRead(BOTON2);
if((lectura_boton1==false)&&(lectura_boton2==false))// ROJO, VERDE, AZUL
{
  alto(LEDROJO);
  delay(500);
  bajo(LEDROJO);
  alto(LEDVERDE);
  delay(500);
  bajo(LEDVERDE);
  alto(LEDAZUL);
  delay(500);
  bajo(LEDAZUL);
}
if((lectura_boton1==true)&&(lectura_boton2==false))// ROJO, VERDE
{
  alto(LEDROJO);
  alto(LEDVERDE);
}
else
{bajo(LEDROJO);
 bajo(LEDVERDE);
 bajo(LEDAZUL);
}
if((lectura_boton1==false)&&(lectura_boton2==true))// VERDE, AZUL
{
  alto(LEDVERDE);
    alto(LEDAZUL);
}
else
{bajo(LEDROJO);
 bajo(LEDVERDE);
 bajo(LEDAZUL);
}

if((lectura_boton1==true)&&(lectura_boton2==true))//ROJO, AZUL
{
  alto(LEDROJO);
  alto(LEDAZUL);
}

else
{bajo(LEDROJO);
 bajo(LEDVERDE);
 bajo(LEDAZUL);
}
}
