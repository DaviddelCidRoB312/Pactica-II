/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Electronica
   Grado: Quinto
   Sección: A
   Curso: Taller de electronica digital y reparación de computadoras I
   Nombre: David Alfredo del Cid Rodriguez
   Carnet: 2022482
   Proyecto: Acelerometro ADXL345
*/
#include <Wire.h>
#include <SPI.h>
#include <SparkFun_ADXL345.h>
#include <LedControl.h>
//Directivas
#define ancho_matriz 8
#define alto_matriz 8
#define bajo_matriz 8
#define DATO_PIN 12
#define CLK_PIN 11
#define CS_PIN 10
ADXL345 acelerometro_ADXL345 = ADXL345();    //constructor para poder utilizar el acelerometro.

//Variables donde guardo las aceleraciones.
int x;
int y;
int z;
//-----------------
const byte derecha0 [8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000011,
  B00000011,
  B00000000,
  B00000000,
  B00000000
};
const byte derecha1 [8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000110,
  B00000110,
  B00000000,
  B00000000,
  B00000000
};
const byte derecha2 [8] = {
  B00000000,
  B00000000,
  B00000000,
  B00001100,
  B00001100,
  B00000000,
  B00000000,
  B00000000
};
const byte centro [8] = {
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00000000
};
const byte izquierda0 [8] = {
  B00000000,
  B00000000,
  B00000000,
  B00110000,
  B00110000,
  B00000000,
  B00000000,
  B00000000
};
const byte izquierda1 [8] = {
  B00000000,
  B00000000,
  B00000000,
  B01100000,
  B01100000,
  B00000000,
  B00000000,
  B00000000
};
const byte izquierda2 [8] = {
  B00000000,
  B00000000,
  B00000000,
  B11000000,
  B11000000,
  B00000000,
  B00000000,
  B00000000
};
LedControl ledMatrix = LedControl(DATO_PIN, CLK_PIN, CS_PIN, 1);
ADXL345 NIVEL = ADXL345();
void setup() {
  Serial.begin(9600);     //Inicio la comunicacion serial a 9600 baudios.
  Serial.println("Uso del acelerometro ADXL345");
  acelerometro_ADXL345.powerOn();             //Enciendo el acelerometro.
  acelerometro_ADXL345.setRangeSetting(8);    //Configuro para medir la aceleracion con 8g.
  //
  ledMatrix.shutdown(0, false);
  ledMatrix.setIntensity(0, 15); //Brilo a la mitad
  ledMatrix.clearDisplay(0);    //limpio el display
  NIVEL.powerOn();
  NIVEL.setRangeSetting(8);       //Definir el rango
}

void loop() {
  acelerometro_ADXL345.readAccel(&x, &y, &z);
  Serial.print("La aceleracion en x es de: ");
  Serial.println(x);
  delay(10);
  //-----------------
  if (x> -2 && x < 3 ) {
    for (int i = alto_matriz; i > 0; i--) {
      ledMatrix.setColumn(0, i, centro[i]);
    }
  }
    if (x> 5 && x < 10 ) {
    for (int i = alto_matriz; i > 0; i--) {
      ledMatrix.setColumn(0, i, derecha2[i]);
    }
  }
    if (x> 11 && x < 20 ) {
    for (int i = alto_matriz; i > 0; i--) {
      ledMatrix.setColumn(0, i, derecha1[i]);
    }
  }
      if (x > 21 && x < 60 ) {
    for (int i = alto_matriz; i > 0; i--) {
      ledMatrix.setColumn(0, i, derecha0[i]);
    }
  }
      if (x> -10 && x < -5 ) {
    for (int i = alto_matriz; i > 0; i--) {
      ledMatrix.setColumn(0, i, izquierda0[i]);
    }
  }
        if (x>-25 && x < -11 ) {
    for (int i = alto_matriz; i > 0; i--) {
      ledMatrix.setColumn(0, i, izquierda1[i]);
    }
  }
        if (x> -61 && x < -26 ) {
    for (int i = alto_matriz; i > 0; i--) {
      ledMatrix.setColumn(0, i, izquierda2[i]);
    }
  }
}//void loop
