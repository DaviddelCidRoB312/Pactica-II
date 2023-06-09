/*
  Fundacion Kinal
  Centro educativo tecnico laboral Kinal
  Perito en Electronica
  Seccion: A
  Curso: Taller de electronica digital y reparacion de computadoras I
  Alumno: David Alfredo del Cid Rodríguez
  Carnet: 2022482
  Proyecto:CONTROL DE UNA SECUENCIA DE COLORES RGB 
*/
#define ch_A0 A0   // potenciometro
#define analogOut_ledrojo  3 //pin conPWM 3
#define analogOut_ledverde 5 //pin conPWM 5
#define analogOut_ledazul  6 //pin conPWM 6
//Variables
int a = 0;
unsigned int raw_potenciometro = 0;
unsigned char speedledrojo = 0;
unsigned char speedledverde = 0;
unsigned char speedledazul = 0;

void setup() {
  pinMode(ch_A0, INPUT); // potenciometro
  pinMode(analogOut_ledrojo, OUTPUT);  //pin donde utilizo el PWM como salida.  led rojo
  pinMode(analogOut_ledverde, OUTPUT);  //pin donde utilizo el PWM como salida. led verde
  pinMode(analogOut_ledazul, OUTPUT);  //pin donde utilizo el PWM como salida.  led azul
}

void loop() {
  //-------------------------------------------------------------------
  raw_potenciometro = analogRead(ch_A0); //leo el canal analogico A0
  int d = map(raw_potenciometro, 0,  1023, 0,  255 );
  analogWrite(analogOut_ledrojo  , 174 );
  analogWrite(analogOut_ledverde , 92 );
  analogWrite(analogOut_ledazul , 230 );
  delay(d);
  analogWrite(analogOut_ledrojo  , 255 );
  analogWrite(analogOut_ledverde , 255 );
  analogWrite(analogOut_ledazul , 255 );
  delay(d);
  analogWrite(analogOut_ledrojo  , 0 );
  analogWrite(analogOut_ledverde , 255 );
  analogWrite(analogOut_ledazul , 255 );
  delay(d);
  analogWrite(analogOut_ledrojo  , 189 );
  analogWrite(analogOut_ledverde , 174 );
  analogWrite(analogOut_ledazul , 20 );
  delay(d);
  analogWrite(analogOut_ledrojo  , 225 );
  analogWrite(analogOut_ledverde , 87 );
  analogWrite(analogOut_ledazul , 35 );
  delay(d);
}
