/*
  Fundacion Kinal
  Centro educativo tecnico laboral Kinal
  Perito en Electronica
  Seccion: A
  Curso: Taller de electronica digital y reparacion de computadoras I
  Alumno: David Alfredo del Cid Rodríguez
  Carnet: 2022482
  Proyecto:CONTROL DE BRILLO DE UN LED 
*/
//Directivas del preprocesador
#define ch_A0 A0   //canal 0 o pin A0 del arduino
#define analogOut_led 3  //pin 3 para PWM 

//Variables
unsigned int raw_led = 0;
unsigned char speedled=0;


void setup() {
  
 pinMode(ch_A0, INPUT); // pin A0 como entrado. NOTA: no usar la instrucción de INPUT_PULLUP
 pinMode(analogOut_led, OUTPUT);  //pin donde utilizo el PWM como salida.

}

void loop() {
  raw_led = analogRead(ch_A0); //leo el canal analogico A0
  speedled = map(raw_led, 0, 1023, 0, 255);
  analogWrite(analogOut_led, speedled);
}
