
//Documentacion de la pixy camera: http://cmucam.org/projects/cmucam5/wiki/Arduino_API
#include <Pixy.h>
#include <PixyI2C.h>
#include <PixySPI_SS.h>
#include <PixyUART.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <Wire.h>
#include <TPixy.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>


//MOTORES
int motores[10] = {10, 9, 11, 12, 38, 36, 42, 40, 28, 26};
int enable[5] = {8, 13, 7, 6, 5};

LiquidCrystal_I2C lcd(0x27,16,2);


/////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////DECLARACION DE VARIABLES/////////////////////////////////////////
Pixy pixy;                                         

Adafruit_BNO055 bno = Adafruit_BNO055(55);        //Declaracion del BNO
                                                   
bool viendo_Pelota = false;                                                                    
bool viendo_porteria = false;
short alineado = 0; 
short on_color[4] = {3,2,18,19};                       //000 = libre; 010 = derecha; 100 = izquierda; 111 = meta rival; 110 = propia meta
int x_pelota = 0, y_pelota = 0;                           
int y_porteria = 0;                                   
int x_porteria = 0;                                   
int contador_pelota = 0;
int contador_porteria = 0;
int contador_alineacion = 0;
uint16_t blocks;                                  
unsigned int direccion;  
bool equipo = true;
int signature_porteria;
int contadorDesmarque = 0;
double angle = 0, ant = 0, cal = 0;
bool cambio = false, entre = true;
int tiempo = 500;
bool tendencia;
unsigned long long tiempo_kicker = 0;

//////////////////////////////////////////  ////////////////////////////////////////////////////////////////  

                                                  

void setup() {
  
  //Inicializacion de la pixy  
  pixy.init();
  
  //Inicializacion BNO
  bno.begin();
  bno.setExtCrystalUse(true);
  
  
  //Declarar los pines de los motores como salidas
  for(int i = 0; i < 10; i++){
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
  
  signature_porteria = equipo ? 3 : 5;

  //Disparador
  pinMode(24, OUTPUT);
  
  //Debugeo
  pinMode(47, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(45, OUTPUT);

  //Motores
  analogWrite(enable[0], 180);
  analogWrite(enable[1], 200);
  analogWrite(enable[2], 180);
  analogWrite(enable[3], 200);
 
  //LCD
  lcd.begin();  
  lcd.clear();
  lcd.backlight(); 

  digitalWrite(24,HIGH);
}

void loop() {
  analisis_de_datos();
  //scanPixy();
  //avanzar(1);
  //colores();
  }
