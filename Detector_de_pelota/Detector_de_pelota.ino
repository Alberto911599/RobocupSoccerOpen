
//Documentacion de la pixy camera: http://cmucam.org/projects/cmucam5/wiki/Arduino_API
#include <Pixy.h>
#include <PixyI2C.h>
#include <PixySPI_SS.h>
#include <PixyUART.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <Wire.h>
#include <math.h>
#include <TPixy.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>


//MOTORES
int motores[10] = {10, 9, 11, 12, 36, 38, 42, 40, 28, 26};
int enable[5] = {8, 13, 7, 6, 5};

//MOTORES
//int motores[10] = {42, 40, 38, 36, 10, 9, 12, 11, 28, 26};
//int enable[5] = {6, 7, 8, 13, 5};

int p1 = 180;
int p2 = 200;

LiquidCrystal_I2C lcd(0x27,16,2);


/////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////DECLARACION DE VARIABLES/////////////////////////////////////////
Pixy pixy;                                         

Adafruit_BNO055 bno = Adafruit_BNO055(55);        //Declaracion del BNO

//////////////////////////////////////PIXY//////////////////////////////////////
uint16_t blocks;                                                 
bool viendo_Pelota = false;                                                                    
bool viendo_porteria = false;
short alineado = 0; 
double angPixy = 0;
int x_pelota = 0, y_pelota = 0;                           
int y_porteria = 0;                                   
int x_porteria = 0; 
int contador_pelota = 0;
int contador_porteria = 0;
int signature_porteria;
bool tendencia;
bool defensa;
unsigned bajoPor = 110, altoPor = 210;

//////////////////////////////////////KICKER//////////////////////////////////////
unsigned long tiempoKick = 0;
bool actKick = false;
int conta_kicker = 0;
//////////////////////////////////////FOTORRESISTENCIAS//////////////////////////////////////
short on_color[4] = {3,2,18,19};                       
                                 

//////////////////////////////////////BNO055//////////////////////////////////////                            
unsigned int direccion;  
bool equipo = true;
int contadorDesmarque = 0;
double angle = 0, ant = 0, cal = 0;
bool cambio = false, entre = true;
int tiempo = 600;
long tiempo_kicker = 0;
short Kp = 1.2;
short Ap = 3;
int anguloBNO = 40;
int anguloPorteria = 30;


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
  digitalWrite(24, HIGH);
  
  //Debugeo
  pinMode(47, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(45, OUTPUT);

  //Motores
  analogWrite(enable[0], 180);
  analogWrite(enable[1], 200);
  analogWrite(enable[2], 180);
  analogWrite(enable[3], 200);
  analogWrite(enable[4], 255);
 
  //LCD
  lcd.begin();  
  lcd.clear();
  lcd.backlight(); 
}

void loop() {
//  scanPixy();
  analisis_de_datos();
//  delay(50);
}
