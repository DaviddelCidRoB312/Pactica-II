/*
* Fundacion Kinal
* Centro educativo tecnico laboral Kinal
* Perito en Electronica
* Seccion: A
* Curso: Taller de electronica digital y reparacion de computadoras I
* Alumno: David Alfredo del Cid Rodríguez
* Fecha: 18/14/2023
* Carnet: 2022482
* Proyecto: buzzer
*/

const int trigPin = 2;
const int echoPin = 3;
int ZumbadorPin = 4;
long duration;
int distance;
int a=0;
//////////////////////////////////////////////////////
//NOTAS FRECUENCIA
int Do=523.25; //DO
int Re=587.33; //RE
int Mi= 659.26;//MI
int Fa=698.46 ; //FA
int Sol=783.99; //SOL
int La=880; //LA
int Si=497; //SI
int Doo=554.37;//Do#



void setup() {
pinMode(trigPin, OUTPUT); //Establece el trigPin como Salida
pinMode(echoPin, INPUT); // Establece el echoPin como Entrada
Serial.begin(9600); // Inicia la comunicación serie
pinMode(ZumbadorPin, OUTPUT); // definimos la variable ZumbadorPin como una salida.

}

void loop() {
   int lecturaecho =digitalRead(echoPin);//lectura eco sumador
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Pone el trigPin en estado HIGH durante 10 micro segundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lee el echoPin, devuelve el tiempo de viaje de la onda sonora en microsegundos
  duration = pulseIn(echoPin, HIGH);

  // Calcular la distancia
  distance= duration/59;

  // Imprime la distancia en el monitor serie
  Serial.print(String(distance));
  Serial.println(" cm");
  delay(400);

///notas
  if(distance>=45 && distance<=50)//1
{
}
//////////////////////////////////////////////////////////////
  if(distance>=40 && distance<=45)//1
{
    tone(ZumbadorPin, Do, 523.25);
}
//////////////////////////////////////////////////////////////

  if(distance>=35 && distance<=40)//1
{
    tone(ZumbadorPin, Re, 587.33);


}
//////////////////////////////////////////////////////////////

  if(distance>=30 && distance<=35)//1
{
    tone(ZumbadorPin, Mi, 659.26);

}
//////////////////////////////////////////////////////////////

  if(distance>=25 && distance<=30)//1
{
    tone(ZumbadorPin, Fa, 698.46);

}
//////////////////////////////////////////////////////////////

  if(distance>=20 && distance<=25)//1
{
    tone(ZumbadorPin, Sol, 783.99);

}
//////////////////////////////////////////////////////////////

  if(distance>=15 && distance<=20)//1
{
    tone(ZumbadorPin, La, 1760.00);

}
//////////////////////////////////////////////////////////////


  if(distance>=10 && distance<=15)//1
{
    tone(ZumbadorPin, Si,497 );

}
//////////////////////////////////////////////////////////////

  if(distance>=5 && distance<=10)//1
{
    tone(ZumbadorPin, Doo, 554.37);

}
///////////////////////////////////////////////////////////////

}///VOID LOOP

