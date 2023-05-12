/*
  Fundacion Kinal
  Centro educativo tecnico laboral Kinal
  Perito en Electronica
  Seccion: A
  Curso: Taller de electronica digital y reparacion de computadoras I
  Alumno: David Alfredo del Cid Rodríguez
  Fecha: 5/05/2023
  Carnet: 2022482
  Proyecto: Alarma de carro
*/
// LCD
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
//dfinir
/////////////////////////////////
// CONSTRUCCION
// define variables
long duration;
int distance;
void Ultrasonico(int trig, int echo) ;
int LCD_lleno;
/////////////////////
//cuadro lleno
byte lleno[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

/////////////////////////////////////////////////////////////
void setup() {
  //I2C
  lcd.init();
  lcd.backlight();
}
////////////////////////////////////////////////////////////////////////
void loop()
{
  Ultrasonico(8, 9);

  //////////////////////////////////
  //I2C

  lcd.setCursor(0, 0);
  /////////////////////////////////////
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
  /////////////////////////////////////////////////////////////////////////////////////////
  // circuito
  lcd.createChar(1, lleno);

  if (distance >= 30 && distance <= 50)
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(1);
    lcd.write(1);
    lcd.setCursor(4, 0);
    lcd.print("   50   ");
    lcd.setCursor(13, 0);
    lcd.write(1);
    lcd.write(1);
     lcd.write(1);  
    lcd.setCursor(0, 1);
    lcd.print("      Libre     ");
    delay(50);
  }
  if (distance >= 10 && distance <= 30)
  {

lcd.setCursor(0, 0);
lcd.write(1);
lcd.write(1);
lcd.write(1);
lcd.write(1);
lcd.write(1);
lcd.print("  30  ");
lcd.setCursor(11, 0);
lcd.write(1);
lcd.write(1);
lcd.write(1);
lcd.write(1);
lcd.write(1);
lcd.setCursor(0, 1);
lcd.print("     Cuidado    ");
delay(50);
  }
  if (distance >= 1 && distance <= 10)
  {

lcd.setCursor(0, 0);
lcd.write(1);
lcd.write(1);
lcd.write(1);
lcd.write(1); 
lcd.write(1);  
lcd.write(1); 
lcd.write(1); 
lcd.print("10");
lcd.setCursor(9,0); 
lcd.write(1);
lcd.write(1);
lcd.write(1);
lcd.write(1); 
lcd.write(1);  
lcd.write(1); 
lcd.write(1);   
lcd.setCursor(0, 1);
lcd.print("      Alto      ");
delay(50);
  }
}// ultrasonico
