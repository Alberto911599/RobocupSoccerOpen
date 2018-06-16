  
  int colores[8];
  int out[4] = {3,4,5,6}; 
  int led = 13;
  int constantes[8];
  
  void inicializacion(){
    for(int i = 0; i < 8; i++){
      colores[i] = 0;
    }
  }
  
  void lecturas_promedio(){
    //Inicializas en 0 todos los los valores de las lecturas.
    inicializacion();
    //Lectura de fotorresistencias
    for(int j = 0; j < 10; j++){
      for(int i = 0; i < 8; i++){
        colores[i] += analogRead(i);
      }
    }
    for(int i = 0; i < 8; i++){
      colores[i] /= 10;
      //Serial.print(colores[i]);
      //Serial.print("\t");
    } 
    //Serial.println("");
  }
  
  
  const int right_r = 180;//150
  const int right_s = 180;//150
  const int front_r = 140;
  const int front_s = 140;
  const int back_r = 120;
  const int back_s = 150;
  const int left_r = 370;
  const int left_s = 140;
  const int tm = 5;
  const int umbral = 50;
  void setup(){
    
   //Serial.begin(9600); 
    
   for(int i = 0; i < 4; i++){
    pinMode(out[i], OUTPUT);
   }

   calibracion();
   
  }
  
  void loop(){
    
    lecturas_promedio();    

    digitalWrite(led, LOW);

    digitalWrite(out[0], LOW);
    digitalWrite(out[1], LOW);
    digitalWrite(out[2], LOW);
    digitalWrite(out[3], LOW);
//    out[0] = 0; 
//    out[1] = 0; 
//    out[2] = 0; 
//    out[3] = 0; 
//    
//    
    if(colores[0] > (constantes[0] + umbral) || colores[1] > (constantes[1] + umbral)){
        digitalWrite(out[0], HIGH);
        digitalWrite(led, HIGH);
//        out[0] = 1; 
      }
      

    if(colores[4] > (constantes[4] + umbral)|| colores[5] > (constantes[5] + umbral)){
      digitalWrite(out[1], HIGH);
      digitalWrite(led, HIGH);

    }
//      out[1] = 1; 

    if(colores[2] > (constantes[2] + umbral) || colores[3] > (constantes[3] + umbral)){
      digitalWrite(out[2], HIGH);
      digitalWrite(led, HIGH);
    }
//      out[2] = 1; 

    if(colores[6] > (constantes[6] + umbral) || (colores[7] > constantes[7] + umbral)){
      digitalWrite(out[3], HIGH);
      digitalWrite(led, HIGH);
    }

    ///******imprimir pines*****///////
   
    
//      out[3] = 1; 
//
//    Serial.print(out[0]);
//    Serial.print(out[1]);
//    Serial.print(out[2]);
//    Serial.println(out[3]);
//
    delayMicroseconds(tm); 
    

  }

void calibracion(){
   //incializacion en 0
   for(int k = 0; k < 8; k++){
      constantes[k] = 0;
   }
   
   //Calibracion de constantes
   for(int i = 0; i < 3; i++){
      lecturas_promedio();   
      for(int j = 0; j < 8; j++){
        constantes[j] += colores[j];
      }
   }

   for(int k = 0; k < 8; k++){
      constantes[k] /= 3;
      //Serial.print(constantes[k]);
      //Serial.print("    ");
   }
   //Serial.println(" Y as e calibro ");

}

