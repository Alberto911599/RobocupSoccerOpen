  int colores[8];
  int out[11] = {2,3,4,5,6,7,8,9,10,11,12}; 
  int led = 13;
  
  void inicializacion(){
    for(int i = 0; i < 8; i++){
      colores[i] = 0;
    }
  }
  
  void lecturas_promedio(){
    //Lectura de fotorresistencias
    for(int j = 0; j < 10; j++){
      for(int i = 0; i < 8; i++){
        colores[i] += analogRead(i);
      }
    }
    for(int i = 0; i < 8; i++){
      colores[i] /= 10;
      Serial.print(colores[i]);
      Serial.print("\t");
    }  
    Serial.println("");
  }
  
  void prendepin(){
    for(int i = 2; i < 11; i++){
      digitalWrite(out[i], HIGH);
    }
  }
  
  void apagapin(){
    for(int i = 2; i < 11; i++){
      digitalWrite(out[i], LOW);
    }
  }
  
  void apagatodo(){
    for(int i = 0; i < 11; i++){
      digitalWrite(out[i], LOW);
    }
  }
  
  const int extra_high = 800;
  const int high = 600;
  const int down = 450;
  const int tm = 20;
  
  void setup(){
    
   Serial.begin(9600); 
    
   for(int i = 0; i < 12; i++){
    pinMode(out[i], OUTPUT);
   }
   inicializacion();
  }
  
  void loop(){
    
    inicializacion();
    lecturas_promedio();
    
    //Izquierdo
    if(colores[0] > extra_high || colores[1] > extra_high){
      digitalWrite(out[0], HIGH);
      digitalWrite(out[1], LOW);
      apagapin();
      digitalWrite(led, HIGH);
      delay(tm);      
    }
    //Derecho
    else if(colores[4] > extra_high || colores[5] > extra_high){
      digitalWrite(out[0], LOW);
      digitalWrite(out[1], HIGH);
      apagapin();
      digitalWrite(led, HIGH);
      delay(tm);
    }
    //Meta Arriba
    else if(colores[2] > down || colores[3] > down){
      digitalWrite(out[0], HIGH);
      digitalWrite(out[1], HIGH);
      prendepin();
      digitalWrite(led, HIGH);
      delay(tm);
    }
    
    //Meta Abajo
    else if(colores[6] > high || colores[7] > high){
      digitalWrite(out[0], HIGH);
      digitalWrite(out[1], HIGH);
      apagapin();
      digitalWrite(led, HIGH);
      delay(tm);
    }
    
    //Libre
    else{
      digitalWrite(out[0], LOW);
      digitalWrite(out[1], LOW);
      apagapin();
      digitalWrite(led, LOW);
    }
  }
