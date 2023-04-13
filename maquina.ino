/*
* Fundacion Kinal
* Centro educativo tecnico laboral Kinal
* Perito en Electronica
* Seccion: A
* Curso: Taller de electronica digital y reparacion de computadoras I
* Alumno: David Alfredo del Cid Rodríguez
* Carnet: 2022482
* Proyecto: MAQUINA EXPENDEDORA
*/
#define push_button1 2
#define push_button2 3
#define Productos
#define entra1(pin)     pinMode(pin,INPUT)      //Macro para configurar entradas
#define entra2(pin)   pinMode(pin,INPUT)   //Macro para configurar salidas.
struct productos{
String OREO;
String DORITOS;
String TORTRIXLIMON;
String ELOTITOS;
};
int i=0;
int a=0;
productos tienda={"OREO", "DORITOS", "TORTRIXLIMON", "ELOTITOS"};
productos pro;
void setup() {
  //PRUEBA 1
Serial.begin(9600);
entra1(push_button1);
entra2(push_button2);

//inicio de estructura del Menú
Serial.println("                                EXPENDEDORA EL CAFETALITO");

Serial.println("                 /////========== MENU DE PRODUCTOS A LA VENTA ==========/////");
pro.OREO=("OREO");
Serial.println(pro.OREO);
delay(100);
//otro
pro.DORITOS="DORITOS";
Serial.println(pro.DORITOS);
//producto
pro.TORTRIXLIMON="TORTRIXLIMON";
Serial.println(pro.TORTRIXLIMON);
delay(100);
//otro
pro.ELOTITOS="ELOTITOS";
Serial.println(pro.ELOTITOS);
delay(100);
Serial.println("=========================================================================================================");
}
void loop() {

bool prue1 = digitalRead(push_button1);
bool prue2 = digitalRead(push_button2);

if(prue1 == HIGH)// E PRESIONADO EL BOTON
{ delay(50);// anti rebote
i++;
delay(100);//antei retroseso
};


if(i==1) {
  Serial.println(tienda.OREO);
  Serial.println("10 en stock");
  Serial.println("caduce el 15/05/2040");
  Serial.println("contenido neto 432g");
  Serial.println("con mas crema");
  Serial.println("==========================================================================================================================");
  delay(100);
  delay(100);
  i++;
}

if(i==3){
  Serial.println(tienda.DORITOS);
   Serial.println("10 en stock");
  Serial.println("caduce el 8/01/2040");
    Serial.println("contenido neto 270g");
  Serial.println("quezo picante");
  Serial.println("==========================================================================================================================");
  delay(100);
  delay(100);
  i++;
}

if(i==5){
  Serial.println(tienda.TORTRIXLIMON);
   Serial.println("10 en stock");
  Serial.println("caduce el 30/09/2040");
    Serial.println("contenido neto 180g");
  Serial.println("sabor a limon :v");
  Serial.println("==========================================================================================================================");
  delay(100);
  delay(100);
  i++;
  }

if(i==7){
  Serial.println(tienda.ELOTITOS);
   Serial.println("10 en stock");
  Serial.println("caduce el 10/10/2040");
    Serial.println("contenido neto 183g");
  Serial.println("Sabor original");
  Serial.println("==========================================================================================================================");
  delay(100);
  delay(100);
  i++;
  }
if(i>8){
  i=0;
}

if(prue2 == HIGH)// E PRESIONADO EL BOTON
{ delay(50);// anti rebote
a++;
delay(100);//antei retroseso
};

if(a==1) {
  Serial.println(tienda.OREO);
  Serial.println("10 en stock");
  Serial.println("caduce el 15/05/2040");
  Serial.println("contenido neto 432g");
  Serial.println("con mas crema");
  Serial.println("==========================================================================================================================");
  delay(100);
  delay(100);
  a++;
}

if(a==3){
  Serial.println(tienda.DORITOS);
   Serial.println("10 en stock");
  Serial.println("caduce el 8/01/2040");
    Serial.println("contenido neto 270g");
  Serial.println("quezo picante");
  Serial.println("==========================================================================================================================");
  delay(100);
  delay(100);
  a++;
}

if(a==5){
  Serial.println(tienda.TORTRIXLIMON);
   Serial.println("10 en stock");
  Serial.println("caduce el 30/09/2040");
    Serial.println("contenido neto 180g");
  Serial.println("sabor a limon :v");
  Serial.println("==========================================================================================================================");
  delay(100);
  delay(100);
  a++;
  }

if(a==7){
  Serial.println(tienda.ELOTITOS);
   Serial.println("10 en stock");
  Serial.println("caduce el 10/10/2040");
    Serial.println("contenido neto 183g");
  Serial.println("Sabor original");
  Serial.println("==========================================================================================================================");
  delay(100);
  delay(100);
  a++;
  }
if(a>8){
  a=0;
}

}
