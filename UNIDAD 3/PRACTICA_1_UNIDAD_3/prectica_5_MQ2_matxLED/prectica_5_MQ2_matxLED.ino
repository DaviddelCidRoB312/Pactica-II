/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: David Alfredo del Cid Rodríguez
 * Carnet: 2022482
 * Proyecto: Uso del controlador led max7219 y una matriz led 8x8
*/
//Librerias
#include <LedControl.h>  //libreria que me permite usar el controlador led max7219
#include <Ticker.h>  //esta libreria me permite hacer uso del timer
// Directivas de preprocesador
#define dataPin0 12    //pin 12 conectado al pin de datos del max7219.
#define dataClock0 11  //pin 11 conectado al pin de clock del max7219.
#define dataLoad0 10   //pin 10 conectado al pin de carga del max7219.

// Constructores
LedControl matrix_unidades = LedControl(dataPin0, dataClock0, dataLoad0, 1);

byte number_0[8] = {

B10011001,
B01000010,
B00100100,
B10011001,
B10011001,
B00100100,
B01000010,
B10011001


};

byte number_1[8] = {


B00011000,
B00110000,
B01100000,
B01110000,
B00110000,
B00111000,
B00111100,
B01111111

};

byte number_2[8] = {

B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
};

byte number_3[8] = {

B00011000,
B00110000,
B01100000,
B01110000,
B00110000,
B00111000,
B00111100,
B01111111

};

byte number_4[8] = {

B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
};

byte number_5[8] = {


B00011000,
B00110000,
B01100000,
B01110000,
B00110000,
B00111000,
B00111100,
B01111111

};
byte number_6[8] = {

B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
};

byte number_7[8] = {

B00011000,
B00110000,
B01100000,
B01110000,
B00110000,
B00111000,
B00111100,
B01111111
};


// Prototipos de funciones
int display_number(unsigned char number);

int valor_limite = 130;  // Fija el valor límite en el que se activa la animacion de la matriz

void setup() {
  Serial.begin(9600);
  matrix_unidades.shutdown(0, false);
  matrix_unidades.setIntensity(0, 15);
  matrix_unidades.clearDisplay(0);
}

void loop() {
  int sensorValue = analogRead(A0);  // Variable para almacenar el valor del sensor
  Serial.println(sensorValue);

  if (sensorValue > valor_limite) {
    for (int i = 0; i < 8; i++) {
      matrix_unidades.setRow(0, i, number_1[i]);
    }
    delay(1000);
    for (int i = 0; i < 8; i++) {
      matrix_unidades.setRow(0, i, number_2[i]);
    }
    delay(1000);
        for (int i = 0; i < 8; i++) {
      matrix_unidades.setRow(0, i, number_3[i]);
    }
    delay(1000);
    for (int i = 0; i < 8; i++) {
      matrix_unidades.setRow(0, i, number_4[i]);
    }
    delay(1000);
        for (int i = 0; i < 8; i++) {
      matrix_unidades.setRow(0, i, number_5[i]);
    }
    delay(1000);
            for (int i = 0; i < 8; i++) {
      matrix_unidades.setRow(0, i, number_6[i]);
    }
    delay(1000);
            for (int i = 0; i < 8; i++) {
      matrix_unidades.setRow(0, i, number_7[i]);
    }
    delay(1000);

  } else {
    for (int i = 0; i < 8; i++) {
      matrix_unidades.setRow(0, i, number_0[i]);
      delay(10);

    }  //for
  }    //else
}  //void loop
