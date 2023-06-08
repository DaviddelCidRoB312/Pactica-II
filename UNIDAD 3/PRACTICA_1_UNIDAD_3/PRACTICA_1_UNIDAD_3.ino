/*
  Fundacion Kinal
  Centro educativo tecnico laboral Kinal
  Perito en Electronica
  Seccion: A
  Curso: Taller de electronica digital y reparacion de computadoras I
  Alumno: David Alfredo del Cid Rodríguez
  Carnet: 2022482
  Proyecto:Uso de interrupciones externas
*/
#define Rising 2
#define Falling 3

unsigned int unidades = 1;
unsigned int decenas = 1 ;

void Rising_suma(void);
void Falling_resta(void);
void Casos_display();

void setup()
{

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);


  pinMode(Rising, INPUT);
  pinMode(Falling, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(Falling), Falling_resta, FALLING); //Establecemos el constructor de la interrupción
  attachInterrupt(digitalPinToInterrupt(Rising), Rising_suma, RISING);




}

void loop()
{
  Casos_display();

}

void Falling_resta(void)
{
  unidades--;
  if (unidades == 0 && decenas == 1)
  {
    unidades = 10;
    decenas = 6;
    decenas--;
  }
  if (unidades == 0 )
  {
    unidades = 10;
    decenas--;
  }
}

void Rising_suma(void)
{
  unidades++;
}

void Casos_display()
{

  if (unidades == 1 ) //0
  {
    digitalWrite(4, LOW); //a
    digitalWrite(5, LOW); //b
    digitalWrite(6, LOW); //c
    digitalWrite(7, LOW); //d
  }

  else if (unidades == 2)//1
  {
    digitalWrite(4, HIGH); //a
    digitalWrite(5, LOW); //b
    digitalWrite(6, LOW); //c
    digitalWrite(7, LOW); //d
  }

  else if (unidades == 3)//2
  {
    digitalWrite(4, LOW); //a
    digitalWrite(5, HIGH); //b
    digitalWrite(6, LOW); //c
    digitalWrite(7, LOW); //d
  }

  else if (unidades == 4)//3
  {
    digitalWrite(4, HIGH); //a
    digitalWrite(5, HIGH); //b
    digitalWrite(6, LOW); //c
    digitalWrite(7, LOW); //s
  }

  else if (unidades == 5)//4
  {
    digitalWrite(4, LOW); //a
    digitalWrite(5, LOW); //b
    digitalWrite(6, HIGH); //c
    digitalWrite(7, LOW); //d
  }

  else if (unidades == 6)//5
  {
    digitalWrite(4, HIGH); //a
    digitalWrite(5, LOW); //b
    digitalWrite(6, HIGH); //c
    digitalWrite(7, LOW); //d
  }

  else if (unidades == 7)//6
  {
    digitalWrite(4, LOW); //a
    digitalWrite(5, HIGH); //b
    digitalWrite(6, HIGH); //c
    digitalWrite(7, LOW); //d
  }

  else if (unidades == 8)//7
  {
    digitalWrite(4, HIGH); //a
    digitalWrite(5, HIGH); //b
    digitalWrite(6, HIGH); //c
    digitalWrite(7, LOW); //d
  }

  else if (unidades == 9)//8
  {
    digitalWrite(4, LOW); //a
    digitalWrite(5, LOW); //b
    digitalWrite(6, LOW); //c
    digitalWrite(7, HIGH); //d
  }

  else if (unidades == 10)//9
  {
    digitalWrite(4, HIGH); //a
    digitalWrite(5, LOW); //b
    digitalWrite(6, LOW); //c
    digitalWrite(7, HIGH); //ad

  }
  if (unidades == 11)
  {
    unidades = 1;
    decenas++;
  }

  //---------------------------------------------------------
  if (decenas == 6 && unidades == 2) //Límite de más de 50
  {
    unidades = 1;
    decenas = 1;
  }

  if (decenas == 1)//0
  {
    digitalWrite(8, LOW); //a
    digitalWrite(9, LOW); //b
    digitalWrite(10, LOW); //c
    digitalWrite(11, LOW); //d
  }
  else if (decenas == 2)//1
  {
    digitalWrite(8, HIGH); //a
    digitalWrite(9, LOW); //b
    digitalWrite(10, LOW); //c
    digitalWrite(11, LOW); //d
  }
  else if (decenas == 3)//2
  {
    digitalWrite(8, HIGH); //a
    digitalWrite(9, HIGH); //b
    digitalWrite(10, LOW); //c
    digitalWrite(11, LOW); //d
  }
  else if (decenas == 4)//3
  {
    digitalWrite(8, HIGH); //a
    digitalWrite(9, HIGH); //b
    digitalWrite(10, LOW); //b
    digitalWrite(11, LOW); //d
  }
  else if (decenas == 5)//4
  {
    digitalWrite(8, LOW); //a
    digitalWrite(9, LOW); //b
    digitalWrite(10, HIGH); //c
    digitalWrite(11, LOW); //d
  }
  else if (decenas == 6)//5
  {
    digitalWrite(8, HIGH); //a
    digitalWrite(9, LOW); //b
    digitalWrite(10, HIGH); //c
    digitalWrite(11, LOW); //d
  }
}//void caso_display
