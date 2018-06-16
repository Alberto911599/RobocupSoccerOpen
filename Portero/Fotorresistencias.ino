void colores(){
  on_color[0] = digitalRead(2);
  on_color[1] = digitalRead(3);
  on_color[2] = digitalRead(18);
  on_color[3] = digitalRead(19);
  imprimirRes();
}

int all_meco(){

  adentroIzq = false;
  adentroDer = false;
  
  if(on_color[0] == 1){
    caso = 2;
  }
  else if(on_color[1] == 1){
    caso = 3;
  }
  
  aprieta();
  long tempTime = millis();
  while(millis() < tempTime + tiempoT){
    avanzar(caso, false);
  }

  return caso;
    
}
  
  


