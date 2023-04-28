/*

* Fundacion Kinal
* Centro educativo tecnico laboral Kinal
* Perito en Electronica
* Seccion: A
* Curso: Taller de electronica digital y reparacion de computadoras I
* Alumno: David Alfredo del Cid Rodríguez
* Fecha: 28/042023
* Carnet: 2022482
* Proyecto: ultrasonicco
*/

const int trigPin = 2;
const int echoPin = 3;
const int pin = 11;
int a=0;


// define variables
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); //Establece el trigPin como Salida
  pinMode(echoPin, INPUT); // Establece el echoPin como Entrada
  Serial.begin(9600); // Inicia la comunicación serie
  pinMode (4,OUTPUT);
  pinMode (5,OUTPUT);
  pinMode (6,OUTPUT);
  pinMode (7,OUTPUT);
  pinMode (8,OUTPUT);
  pinMode (9,OUTPUT);
  pinMode (10,OUTPUT);
  ///RELEY
  Serial.begin(9600); // INICIA EL PUERTO SERIE
  pinMode(11, OUTPUT);// DEFINE PIN COMO SALIDA
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
if(distance<11 && distance >0)
{
a++;
if(distance<11 && a==1)//1
{
  digitalWrite (4,LOW);  //a
  digitalWrite (5,HIGH);   //b
  digitalWrite (6,HIGH);   //c
  digitalWrite (7,LOW);  // d
  digitalWrite (8,LOW);  //e
  digitalWrite (9,LOW);  //f
  digitalWrite (10,LOW); //g
a++;  
}
if(distance<11 && a==3)//2
{
  digitalWrite (4,HIGH);   //a
  digitalWrite (5,HIGH);   //b
  digitalWrite (6,LOW);  //c
  digitalWrite (7,HIGH);   // d
  digitalWrite (8,HIGH);   //e
  digitalWrite (9,LOW);  //f
  digitalWrite (10,HIGH);  //g
a++;
}
if(distance<11 && a==7)//3
{
  digitalWrite (4,HIGH);   //a
  digitalWrite (5,HIGH);   //b
  digitalWrite (6,HIGH);  //c
  digitalWrite (7,HIGH);   // d
  digitalWrite (8,LOW);   //e
  digitalWrite (9,LOW);  //f
  digitalWrite (10,HIGH);  //g
a++;
}
if(distance<11 && a==9)//4
{
  digitalWrite (4,LOW);   //a
  digitalWrite (5,HIGH);   //b
  digitalWrite (6,HIGH);  //c
  digitalWrite (7,LOW);   // d
  digitalWrite (8,LOW);   //e
  digitalWrite (9,HIGH);  //f
  digitalWrite (10,HIGH);  //g
a++;
}
if(distance<11 && a==11)//5
{
  digitalWrite (4,HIGH);   //a
  digitalWrite (5,LOW);   //b
  digitalWrite (6,HIGH);  //c
  digitalWrite (7,HIGH);   // d
  digitalWrite (8,LOW);   //e
  digitalWrite (9,HIGH);  //f
  digitalWrite (10,HIGH);  //g
a++;
}
if(distance<11 && a==13)//6
{
  digitalWrite (4,HIGH);   //a
  digitalWrite (5,LOW);   //b
  digitalWrite (6,HIGH);  //c
  digitalWrite (7,HIGH);   // d
  digitalWrite (8,HIGH);   //e
  digitalWrite (9,HIGH);  //f
  digitalWrite (10,HIGH);  //g
a++;
}
if(distance<11 && a==15)//7
{
  digitalWrite (4,HIGH);   //a
  digitalWrite (5,HIGH);   //b
  digitalWrite (6,HIGH);  //c
  digitalWrite (7,LOW);   // d
  digitalWrite (8,LOW);   //e
  digitalWrite (9,LOW);  //f
  digitalWrite (10,LOW);  //g
a++;
}
if(distance<11 && a==17)//8
{
  digitalWrite (4,HIGH);   //a
  digitalWrite (5,HIGH);   //b
  digitalWrite (6,HIGH);  //c
  digitalWrite (7,HIGH);   // d
  digitalWrite (8,HIGH);   //e
  digitalWrite (9,HIGH);  //f
  digitalWrite (10,HIGH);  //g
a++;
}
if(distance<11 && a==19)//9
{
  digitalWrite (4,HIGH);   //a
  digitalWrite (5,HIGH);   //b
  digitalWrite (6,HIGH);  //c
  digitalWrite (7,LOW);   // d
  digitalWrite (8,LOW);   //e
  digitalWrite (9,HIGH);  //f
  digitalWrite (10,HIGH);  //g
a++;
}

}//if general mente grande
//RELEY
  int estado4 = digitalRead(4);
  int estado5 = digitalRead(5);
  int estado6 = digitalRead(6);
  int estado7 = digitalRead(7);
  int estado8 = digitalRead(8);
  int estado9 = digitalRead(9);
  int estado10 = digitalRead(10);
 
  if (estado4 == HIGH && estado5 == HIGH && estado6 == HIGH && estado7==LOW && estado8==LOW && estado9==HIGH && estado10==HIGH)
{
digitalWrite(11, HIGH);
delay(1000);

}
} // void loop