/*
  Fundacion Kinal
  Centro educativo tecnico laboral Kinal
  Perito en Electronica
  Seccion: A
  Curso: Taller de electronica digital y reparacion de computadoras I
  Alumno: David Alfredo del Cid Rodríguez
  Fecha: 5/05/2023
  Carnet: 2022482
  Proyecto: alarma
*/
// LCD
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
//dfinir
/////////////////////////////////
//alarma
int a=800;
/////////////////////////////////
// CONSTRUCCION
// define variables
long duration;
int distance;
void Ultrasonico(int trig, int echo) ;
void barraled(int ledA, int ledB, int ledC, int ledD, int ledE, int ledF, int ledG, int ledH, int ledI, int ledJ, int buzzer);//BARRA LED


/////////////////////////////////////////////////////////////
void setup() {
  //I2C
  lcd.init();
  lcd.backlight();
  pinMode (2, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (A2, OUTPUT);
  pinMode (A3, OUTPUT);

}
////////////////////////////////////////////////////////////////////////
void loop() {

  Ultrasonico(8, 9);

  barraled(2, 3, 4, 5, 6, 7, 11, 12, A2, A3, 10);
  //////////////////////////////////
  //I2C
  lcd.clear();
  lcd.setCursor(0, 0);


  ///////////////////////////////

}
void Ultrasonico(int trig, int echo)//ULTRASONICO
{
  pinMode(trig, OUTPUT); //Establece el trigPin como Salida
  pinMode(echo, INPUT); // Establece el echoPin como Entrada
  Serial.begin(9600); // Inicia la comunicación serie
  int lecturaecho = digitalRead(echo); //lectura eco sumador
  // Clears the trig
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  // Pone el trigPin en estado HIGH durante 10 micro segundos
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  // Lee el echoPin, devuelve el tiempo de viaje de la onda sonora en microsegundos
  duration = pulseIn(echo, HIGH);
  // Calcular la distancia
  distance = duration / 59;
  // Imprime la distancia en el monitor serie
  Serial.print(String(distance));
  Serial.println(" cm");
  delay(400);

}// ultrasonico
/////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
void barraled(int ledA, int ledB, int ledC, int ledD, int ledE, int ledF, int ledG, int ledH, int ledI, int ledJ, int buzzer)// BARRA LED
{
  ///alarma
  if (distance >= 55 ) //0
  {
    lcd.println("Fuera de alcance");
    delay(500);
    pinMode (2, LOW);
    pinMode (3, LOW);
    pinMode (4, LOW);
    pinMode (5, LOW);
    pinMode (6, LOW);
    pinMode (7, LOW);
    pinMode (11, LOW);
    pinMode (12, LOW);
    pinMode (A2, LOW);
    pinMode (A3, LOW);
    delay(500);
  }

  //////////////////////////////////////////////////////////////
  if (distance >= 50 && distance <= 55) //1
  { lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("espacio Privado ");
    delay(500);
    pinMode (2, HIGH);
    pinMode (3, LOW);
    pinMode (4, LOW);
    pinMode (5, LOW);
    pinMode (6, LOW);
    pinMode (7, LOW);
    pinMode (11, LOW);
    pinMode (12, LOW);
    pinMode (A2, LOW);
    pinMode (A3, LOW);
    tone(buzzer,  800, 500);

  }
  //////////////////////////////////////////////////////////////
  if (distance >= 45 && distance <= 50) //2
  { lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("espacio Privado ");
    delay(500);
    pinMode (2, HIGH);
    pinMode (3, HIGH);
    pinMode (4, LOW);
    pinMode (5, LOW);
    pinMode (6, LOW);
    pinMode (7, LOW);
    pinMode (11, LOW);
    pinMode (12, LOW);
    pinMode (A2, LOW);
    pinMode (A3, LOW);
    tone(buzzer, 800, 500);

  }
  //////////////////////////////////////////////////////////////
  if (distance >= 40 && distance <= 45) //3
  { lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("espacio Privado ");
    delay(500);
    pinMode (2, HIGH);
    pinMode (3, HIGH);
    pinMode (4, HIGH);//
    pinMode (5, LOW);
    pinMode (6, LOW);
    pinMode (7, LOW);
    pinMode (11, LOW);
    pinMode (12, LOW);
    pinMode (A2, LOW);
    pinMode (A3, LOW);
    tone(buzzer, 800, 500);

  }
  //////////////////////////////////////////////////////////////
  if (distance >= 35 && distance <= 40) //4
  { lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("espacio Privado ");
    delay(500);
    pinMode (2, HIGH);
    pinMode (3, HIGH);
    pinMode (4, HIGH);
    pinMode (5, HIGH);//
    pinMode (6, LOW);
    pinMode (7, LOW);
    pinMode (11, LOW);
    pinMode (12, LOW);
    pinMode (A2, LOW);
    pinMode (A3, LOW);
    tone(buzzer, 800, 500);

  }
  //////////////////////////////////////////////////////////////
  if (distance >= 30 && distance <= 35) //5
  { lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("espacio Privado ");
    delay(500);
    pinMode (2, HIGH);
    pinMode (3, HIGH);
    pinMode (4, HIGH);
    pinMode (5, HIGH);
    pinMode (6, HIGH);//
    pinMode (7, LOW);
    pinMode (11, LOW);
    pinMode (12, LOW);
    pinMode (A2, LOW);
    pinMode (A3, LOW);
    tone(buzzer, 800, 500 );

  }
  //////////////////////////////////////////////////////////////

  if (distance >= 25 && distance <= 30) //6
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("Invadiendo   ");
    delay(500);
    pinMode (2, HIGH);
    pinMode (3, HIGH);
    pinMode (4, HIGH);
    pinMode (5, HIGH);
    pinMode (6, HIGH);
    pinMode (7, HIGH);//
    pinMode (11, LOW);
    pinMode (12, LOW);
    pinMode (A2, LOW);
    pinMode (A3, LOW);
    tone(buzzer, 587, 1000);

  }
  //////////////////////////////////////////////////////////////

  if (distance >= 20 && distance <= 25) //7
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("Invadiendo   ");
    delay(500);
    pinMode (2, HIGH);
    pinMode (3, HIGH);
    pinMode (4, HIGH);
    pinMode (5, HIGH);
    pinMode (6, HIGH);
    pinMode (7, HIGH);//
    pinMode (11, HIGH);//
    pinMode (12, LOW);
    pinMode (A2, LOW);
    pinMode (A3, LOW);
    tone(buzzer, 587, 1000);

  }
  //////////////////////////////////////////////////////////////


  if (distance >= 15 && distance <= 20) //8
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("Invadiendo   ");
    delay(500);
    pinMode (2, HIGH);
    pinMode (3, HIGH);
    pinMode (4, HIGH);
    pinMode (5, HIGH);
    pinMode (6, HIGH);
    pinMode (7, HIGH);
    pinMode (11, HIGH);
    pinMode (12, HIGH);//
    pinMode (A2, LOW);
    pinMode (A3, LOW);
    tone(buzzer, 587, 1000);

  }
  //////////////////////////////////////////////////////////////

  if (distance >= 10 && distance <= 15) //9
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("Invadiendo   ");
    delay(500);
    pinMode (2, HIGH);
    pinMode (3, HIGH);
    pinMode (4, HIGH);
    pinMode (5, HIGH);
    pinMode (6, HIGH);
    pinMode (7, HIGH);
    pinMode (11, HIGH);
    pinMode (12, HIGH);
    pinMode (A2, HIGH);//
    pinMode (A3, LOW);
    tone(buzzer, 587, 1000);

  }
  ///////////////////////////////////////////////////////////////

  if (distance >= 5 && distance <= 10) //10
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("Invadiendo   ");
    delay(500);
    pinMode (2, HIGH);
    pinMode (3, HIGH);
    pinMode (4, HIGH);
    pinMode (5, HIGH);
    pinMode (6, HIGH);
    pinMode (7, HIGH);
    pinMode (11, HIGH);
    pinMode (12, HIGH);
    pinMode (A2, HIGH);
    pinMode (A3, HIGH);
    tone(buzzer, 587, 1000);

  }
  ///////////////////////////////////////////////////////////////
}//barra led
