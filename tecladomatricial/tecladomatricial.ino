/*
* Fundacion Kinal
* Centro educativo tecnico laboral Kinal
* Perito en Electronica
* Seccion: A
* Curso: Taller de electronica digital y reparacion de computadoras I
* Alumno: David Alfredo del Cid Rodríguez
* Fecha: 18/14/2023
* Carnet: 2022482
* Proyecto: MAQUINA EXPENDEDORA
*/
//Librerias
#include <Keypad.h>    //Libreria que me permite usar el teclado matricial.

//Macros o directivas de preprocesador
#define filas_teclado 4   //cantidad de filas que posee el teclado matricial.
#define columnas_teclado 4 //cantidad de columnas que posee el teclado matricial.
#define f1_teclado 2  //pin2 conectado a la fila 1
#define f2_teclado 3  //pin3 conectado a la fila 2
#define f3_teclado 4  //pin4 conectado a la fila 3
#define f4_teclado 5  //pin5 conectado a la fila 4
#define c1_teclado 6  //pin6 conectado a la columna 1
#define c2_teclado 7  //pin7 conectado a la columna 2
#define c3_teclado 8  //pin8 conectado a la columna 3
#define c4_teclado 9  //pin9 conectado a la columna 4
//display



int i;

//Creo una matriz led con la disposicion fisica de las teclas
char keys[filas_teclado][columnas_teclado] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

//Arreglos en los que defino los pines a utilizar, tanto para las columnas como para las filas
byte pines_filas[filas_teclado] = {f1_teclado,f2_teclado,f3_teclado,f4_teclado};
byte pines_columnas[columnas_teclado] = {c1_teclado,c2_teclado,c3_teclado,c4_teclado};


//Creo el constructor para poder usar el teclado matricial.
Keypad teclado_profe = Keypad( makeKeymap(keys), pines_filas, pines_columnas, filas_teclado,columnas_teclado);
///////////////////////////////////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600);    //Inicio la comunicacion serial.
  Serial.println("Prueba del teclado matricial");   //Envio de mensaje
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
}
///////////////////////////////////////////////////////////////////////////////
void loop()
{

char tecla = teclado_profe.getKey();  //Obtengo la tecla que presione


  //  1
  switch(tecla){
    case('1'):{
      digitalWrite(10, LOW);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, LOW);//D
      digitalWrite(A1, LOW);//E
      digitalWrite(A2, LOW);//F
      digitalWrite(A3, LOW);//G
      delay(500);
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, LOW);//G
      break;
    }
  }
  // 2
    switch(tecla){
    case('2'):{
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, LOW);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, LOW);//F
      digitalWrite(A3, HIGH);//G
      delay(500);
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, LOW);//G
      break;
    }
  }
    switch(tecla){
    case('3'):{
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, LOW);//E
      digitalWrite(A2, LOW);//F
      digitalWrite(A3, HIGH);//G
      delay(500);
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, LOW);//G
      break;
    }
  }  

      switch(tecla){
    case('4'):{
      digitalWrite(10, LOW);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, LOW);//D
      digitalWrite(A1, LOW);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, HIGH);//G
      delay(500);
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, LOW);//G
      break;
    }
  }

        switch(tecla){
    case('5'):{
      digitalWrite(10, HIGH);//A
      digitalWrite(11, LOW);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, LOW);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, HIGH);//G
      delay(500);
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, LOW);//G
      break;
    }
  }
        switch(tecla){
    case('6'):{
      digitalWrite(10, HIGH);//A
      digitalWrite(11, LOW);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, HIGH);//G
      delay(500);
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, LOW);//G
      break;
    }
  }

            switch(tecla){
    case('7'):{
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, LOW);//D
      digitalWrite(A1, LOW);//E
      digitalWrite(A2, LOW);//F
      digitalWrite(A3, LOW);//G
      delay(500);
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, LOW);//G
      break;
    }
  }
          switch(tecla){
    case('8'):{
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, HIGH);//G
      delay(500);
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, LOW);//G
      break;
    }
  }
            switch(tecla){
    case('9'):{
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, LOW);//D
      digitalWrite(A1, LOW);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, HIGH);//G
      delay(500);
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, LOW);//G
      break;
    }
  }

            switch(tecla){
    case('A'):{
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, LOW);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, HIGH);//G
      delay(500);
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, LOW);//G
      break;
    }
  }

            switch(tecla){
    case('B'):{
      digitalWrite(10, LOW);//A
      digitalWrite(11, LOW);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, HIGH);//G
      delay(500);
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, LOW);//G
      break;
    }
  }

            switch(tecla){
    case('C'):{
      digitalWrite(10, LOW);//A
      digitalWrite(11, LOW);//B
      digitalWrite(12, LOW);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, LOW);//F
      digitalWrite(A3, HIGH);//G
      delay(500);
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, LOW);//G
      break;
    }
  }
            switch(tecla){
    case('D'):{
      digitalWrite(10, LOW);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, LOW);//F
      digitalWrite(A3, HIGH);//G
      delay(500);
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, LOW);//G
      break;
    }
  }
            switch(tecla){
    case('#'):{
      digitalWrite(10, HIGH);//A
      digitalWrite(11, LOW);//B
      digitalWrite(12, LOW);//C
      digitalWrite(A0, LOW);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, HIGH);//G
      delay(500);
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, LOW);//G
      break;
    }
  }
            switch(tecla){
    case('*'):{
      digitalWrite(10, HIGH);//A
      digitalWrite(11, LOW);//B
      digitalWrite(12, LOW);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, HIGH);//G
      delay(500);
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, LOW);//G
      break;
    }
  }
            switch(tecla){
    case('0'):{
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, LOW);//G
      delay(500);
      digitalWrite(10, HIGH);//A
      digitalWrite(11, HIGH);//B
      digitalWrite(12, HIGH);//C
      digitalWrite(A0, HIGH);//D
      digitalWrite(A1, HIGH);//E
      digitalWrite(A2, HIGH);//F
      digitalWrite(A3, LOW);//G
      break;
    }
  }

  //Si alguna tecla ha sido presionada
  if(tecla)
  {
    Serial.print("La tecla presionada es: ");   //Envio el mensaje
    Serial.println(tecla);    //Muestro por la terminal la tecla presionada
  }
   
  }
   