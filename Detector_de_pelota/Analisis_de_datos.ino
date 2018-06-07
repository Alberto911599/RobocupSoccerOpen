//Funcion utilizada para ir hacia algun objetivo ya identificado
//en este caso catch la pelota y fire la porteria
int catch_fire(int i){
  int temp;

  if(i > 80 && i < 240){
      temp = 1;     
  }
  //La pelota esta a la izquierda
  else if(i <= 80){
      temp = 2;
  }
  //La pelota esta a la derecha
  else{
      temp = 3;
  }
  
  return temp;
}

void dribbler(){
  if(y_pelota > 100 && viendo_Pelota)
    avanzar(10);    
  else
    avanzar(11);
}

//void catch_fire_direct(int i, int j){
//  if(i > 100 && i < 220){
////    Serial.println("Adelante");
//    direccion = 1;
//  }
//  //La pelota esta a la izquierda
//  else if(i <= 100){
//    //La peota esta muy cerca
//    if(j > 110){
//      //Izquierda
//      direccion = 2;
//    }
//    //La pelota esta lejos
//    else{
//      //Frente izquierda
//      direccion = 5;
//    }
//  }
//  else{
//    if(j > 110){
//      //Derecha
//      direccion = 3;
//    }
//    //La pelota esta lejos
//    else{
//      //Frente derecha
//      direccion = 6;
//    }
//  }
//}

//Funcion que se utiliza para buscar un objetivo
int find_objective(int i){
  int temp;
  //Si no se detecta, y la ultima vez que se vio fue en medio
  if( i >= 40 && i <= 280 ){
//    Serial.println("Se perdio de vista por distancia, echa reversa");
    direccion = 0;
  }
//  Si no se detecta, y la ultima vez que se vio i fue mayor a 270, el objetivo esta a la derecha
  else if(i > 280){
//    Serial.println("El objetivo salio por la derecha, diagonal hacia atras a la derecha");
    direccion = 4;
  }
  //Si no se detecta, y la ultima vez que se vio i fue menor a 50, el objetivo esta a la izquierda
  else{
//    Serial.println("El objetivo salio por la izquierda, diagonal hacia atras a la izuqierda");
    direccion = 7;
  }
  
  return temp;
  
}

void desmarque(){
  int tempDir = x_porteria < 160 ? 5 : 6;
  long temp = millis();
  while(millis() < temp + 7500 && !viendo_Pelota){
    scanPixy();
    avanzar(tempDir);
    colores();
    if(on_color[2] == 1){
      all_meco(2);
    }
  }
}


void analisis_de_datos(){
  
  alineacion();
  
  colores();
  
  scanPixy();
  
// Libre
  if(on_color[0] == 0 && on_color[1] == 0 && on_color[2] == 0 && on_color[3] == 0){  
    
  //Si no esta viendo la pelota, buscala
    if(!viendo_Pelota){
      direccion = find_objective(x_pelota);
    }


//  Mete gol
    else{
      direccion = catch_fire(x_pelota);
    }
    avanzar(direccion);
  }

  else if(on_color[0] == 1 && on_color[1] == 1){
    all_meco(-1);
  }

  else if(on_color[2] == 1 && on_color[3] == 1){
    all_meco(-2);
  }

  else{
    all_meco(1);
  }

  if(contadorDesmarque >= 3){
    desmarque();
  }
    
}


