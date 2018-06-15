void colores(){
  on_color[0] = digitalRead(3);
  on_color[1] = digitalRead(2);
  on_color[2] = digitalRead(18);
  on_color[3] = digitalRead(19);
  imprimirRes();
}

void all_meco(int aux){
    afloja(); 
    int rotacion = CalAng();
    long tempTime = millis();
    
    //Lados
    if(aux  == -1){ 
      direccion = tendencia ? 0 : 1;
      while(millis() < tempTime + tiempo){
        avanzar(direccion);
        colores();
      }
    }
    
    //Frentes
    else if(aux == -2){
      direccion = rotacion < 180 ? (tendencia ? 3 : 2) : (tendencia ? 2 : 3);
      while(millis() < tempTime + tiempo){
        avanzar(direccion);
        colores();
      }
    }  

  else{

    bool correctaRotacion;
          
    int tempPos;
    int proxPos;
    
    //lados
    if(on_color[0] == 1 || on_color[1] == 1){
      proxPos = -1;
      contadorDesmarque = 0;
      
      
      //izquierda
      if(on_color[1] == 1){
        tempPos= 0;
//        correctaRotacion = rotacion < 180;
        direccion = /*correctaRotacion ?*/ (tendencia ? 3 : 6) /*: 3*/;
      }
      //derecha
      else{
        tempPos= 1;
//        correctaRotacion = rotacion > 180;
        direccion = /*correctaRotacion ? */(tendencia ? 2 : 5) /*:  2*/;
      }
    }
    //frentes
    else{
      proxPos = -2;
      //arriba
      if(on_color[3] == 1){
        tempPos= 2;
        contadorDesmarque = 0;
        direccion = 0;
      }
      //abajo
      else{
        tempPos= 3;
        contadorDesmarque++;
        direccion = 1;
      }
    }

    if(direccion == 5 || direccion == 6){
      aprieta();
    }
    
    while(millis() < tempTime + tiempo){
      avanzar(direccion);
      colores();
      if(on_color[tempPos] == 1){
        all_meco(proxPos);
      }
    }
  }
  
  afloja();
  
  if((direccion == 4 || direccion == 6 || direccion == 3) && !viendo_Pelota)
    x_pelota = 399;
  if((direccion == 7 || direccion == 5 || direccion == 2) && !viendo_Pelota)
    x_pelota = 0;
 
}
  
  


