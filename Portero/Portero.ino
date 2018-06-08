//Documentacion de la pixy camera: http://cmucam.org/projects/cmucam5/wiki/Arduino_API
#include <Pixy.h>
#include <PixyI2C.h>
#include <PixySPI_SS.h>
#include <PixyUART.h>
#include <SPI.h>
#include <Wire.h>
#include <NewPing.h>
#include <LiquidCrystal_I2C.h>
#include <TPixy.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

//MOTORES
int motores[10] = {42, 40, 38, 36, 10, 9, 12, 11, 28, 26};
int enable[5] = {6, 7, 8, 13, 5};

LiquidCrystal_I2C lcd(0x27,16,2);


///////////////////////////////////////DECLARACION DE VARIABLES/////////////////////////////////////////

///////////////////////////////////////PIXY/////////////////////////////////////////
Pixy pixy;                                        //2 = pelota
bool viendo_Pelota = true;
bool viendo_porteria = false;
int contador_porteria = 0;
int x_pelota = 0, y_pelota = 0;                                   
int x_porteria = 0, y_porteria = 0;  
int contador_pelota = 0;
uint16_t blocks;

///////////////////////////////////////BNO055/////////////////////////////////////////
Adafruit_BNO055 bno = Adafruit_BNO055(55);        //Declaracion del BNO
double angle = 0, ant = 0, cal = 0;
bool cambio = false, entre = true;
int anguloPermitido = 10;
int anguloBuscar = 40;
unsigned Kp = 5;
unsigned Ap = 3;
unsigned baseRotacion = 100;
int p1 = 170;
int p2 = 190;
int x = 0;


///////////////////////////////////////ULTRASONICOS/////////////////////////////////////////
NewPing izq(32, 32, 99);
NewPing der(34, 34, 99);
double anteIzq = 0, actIzq = 0;
double anteDer = 0, actDer = 0;
bool adentroIzq = true, adentroDer = true;
bool medio = true;
bool abajo = true;
short esp = -1;
unsigned limiteDistancia = 25;


///////////////////////////////////////FOTORRESISTENCIAS/////////////////////////////////////////
short on_color[4] = {3,2,18,19};                       
int direccion = -1; 
int tiempoT = 800;

//////////////////////////////////////Mov
String i;
String d;

void setup(){
  
  //Serial.begin(9600);

  //Inicializacion de pixy y BNO
  pixy.init();
  bno.begin();
  bno.setExtCrystalUse(true);
  
  //Declarar los pines de los motores como salidas
  for(int i = 0; i < 8; i++){
    pinMode(motores[i], OUTPUT);
  }
  
  //Declarar los enables como salidas
  for(int i = 0; i < 5; i++){
    pinMode(enable[i], OUTPUT);
  }
  
  
  //Declarar los pines de las fotorressistencias como entradas
  for(int i = 0; i < 4; i++){
    pinMode(on_color[i], INPUT);
  }

 anteIzq  = izq.ping_cm();
 anteDer  = der.ping_cm();

  lcd.begin();  
  lcd.clear();

  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("iz="); 
  lcd.setCursor(8, 0);
  lcd.print("de="); 
  lcd.setCursor(0, 1);
  lcd.print("Angle = ");  

  pinMode(24, OUTPUT);

  pinMode(47, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(45, OUTPUT);
}


void loop(){

  analisis_de_datos();
 //colores();
} 

