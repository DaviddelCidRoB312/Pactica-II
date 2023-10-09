#include <SoftwareSerial.h>

// Fundacion Kinal
// Centro educativo tecnico laboral Kinal
// Electronica
// Grado: Quinto
// Sección: A
// Curso: Taller de electronica digital y reparación de computadoras I
// Nombre: David del Cid
// Carnet: 2022482
// Proyecto: Medición de Voltaje, Corriente y Resistencia con Bluetooth HC-05

#define sensorVoltajepin A0       // Pin A0 para el sensor de voltaje
#define sensorCorrientepin A1     // Pin A1 para el sensor de corriente (debes conectar uno)
#define sensorResistenciapin A2   // Pin A2 para la medición de resistencia mediante divisor de voltaje
#define resistenciaFija 10000.0   // Resistencia fija de 10k ohmios

unsigned int raw_sensor_voltaje = 0;
unsigned int raw_sensor_corriente = 0;
unsigned int raw_sensor_resistencia = 0;
float voltaje_sensado = 0;
float corriente_sensada = 0;
float resistencia_sensada = 0;

// Configura la comunicación serial con el módulo Bluetooth HC-05
SoftwareSerial bluetooth(10, 11); // RX, TX

void setup() {
  Serial.begin(9600); // Inicio de la comunicación serial a 9600 baudios.
  bluetooth.begin(9600); // Inicia la comunicación serial con el módulo Bluetooth
  pinMode(sensorVoltajepin, INPUT); // Pin A0 como entrada para el sensor de voltaje
  pinMode(sensorCorrientepin, INPUT); // Pin A1 como entrada para el sensor de corriente
  pinMode(sensorResistenciapin, INPUT); // Pin A2 para la medición de resistencia mediante divisor de voltaje
  Serial.println("Medición de Voltaje, Corriente y Resistencia con Bluetooth HC-05");
}

void loop() {
  raw_sensor_voltaje = analogRead(sensorVoltajepin); // Leer el valor medido por el sensor de voltaje
  raw_sensor_corriente = analogRead(sensorCorrientepin); // Leer el valor medido por el sensor de corriente
  raw_sensor_resistencia = analogRead(sensorResistenciapin); // Leer el valor medido por el divisor de voltaje en el pin A2

  voltaje_sensado = map(raw_sensor_voltaje, 0, 1023, 0.0, 25.0); // Ajusta los valores según tus especificaciones
  corriente_sensada = map(raw_sensor_corriente, 0, 1023, 0.0, 10.0); // Ajusta los valores según tus especificaciones

  // Calcular la resistencia medida usando el divisor de voltaje
  float tensionEntrada = 5.0; // Tensión de entrada al divisor de voltaje
  float resistenciaVariable = resistenciaFija * (tensionEntrada / voltaje_sensado - 1);

  // Enviar los resultados a través del módulo Bluetooth HC-05
  bluetooth.print("V:");
  bluetooth.print(voltaje_sensado);
  bluetooth.print(", I:");
  bluetooth.print(corriente_sensada);
  bluetooth.print(", R:");
  bluetooth.println(resistenciaVariable);

  // Mostrar los resultados en el puerto serie
  Serial.print("Voltaje medido: ");
  Serial.print(voltaje_sensado);
  Serial.println(" V");
  Serial.print("Corriente medida: ");
  Serial.print(corriente_sensada);
  Serial.println(" A");
  Serial.print("Resistencia medida: ");
  Serial.print(resistenciaVariable);
  Serial.println(" ohmios");

  delay(1500);
}
