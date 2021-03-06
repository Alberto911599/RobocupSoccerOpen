void avanzar(int evento, bool rapido) {
  P(evento, rapido);
  switch (evento) {
    case -2:
    for(int i = 0; i < 8; i++){
      digitalWrite(motores[i], HIGH); 
    }
//      Serial.println("Esperando...");
    break;
    case -1:
      for(int i = 0; i < 8; i++){
        digitalWrite(motores[i], LOW); 
      }
//      Serial.println("Esperando...");
    break;
    case 0://0
      for(int i = 0; i < 8; i++){
        if(i % 2 == 0)
          digitalWrite(motores[i], LOW);
        else
          digitalWrite(motores[i], HIGH);
      }      
//      Serial.println("Retrocediendo");
      break;
    case 1://1
      for(int i = 0; i < 8; i++){
        if(i % 2 == 0)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);
      }
//      Serial.println("Avanzando");
      break;
    case 2://2
      for(int i = 0; i < 8; i++){
        if(i == 0 || i == 3 || i == 4 || i == 7)
          digitalWrite(motores[i], LOW);
        else
          digitalWrite(motores[i], HIGH);
      }
//      Serial.println("Izquierdeando");
    break;
    case 3://3
      for(int i = 0; i < 8; i++){
        if(i == 0 || i == 3 || i == 4 || i == 7)
          digitalWrite(motores[i], HIGH);
        else
          digitalWrite(motores[i], LOW);
      }
//      Serial.println("Derecheando");
    break;
    case 4://4
      for(int i = 0; i < 8; i++){
        if(i == 3 || i == 7)
          digitalWrite(motores[i], HIGH);
         else
          digitalWrite(motores[i], LOW);
      }
//      Serial.println("Diagonal Back Derecha");
    break;
    case 5://5
      for(int i = 0; i < 8; i++){
        if(i == 2 || i == 6)
          digitalWrite(motores[i], HIGH);
         else
          digitalWrite(motores[i], LOW);
      }
//      Serial.println("Diagonal Front Izquierda");
    break;
    case 6://6
      for(int i = 0; i < 8; i++){
        if(i == 0 || i == 4)
          digitalWrite(motores[i], HIGH);
         else
          digitalWrite(motores[i], LOW);
      }
//      Serial.println("Diagonal Front Derecha");
    break;
    case 7://7
      for(int i = 0; i < 8; i++){
        if(i == 1 || i == 5)
          digitalWrite(motores[i], HIGH);
         else
          digitalWrite(motores[i], LOW);
      }
//      Serial.println("Diagnoal Back Izquierda");
    break;
    case 8:
      for(int i = 0; i < 8; i++){
       if(i == 1 || i == 3 || i == 4 || i == 6)
         digitalWrite(motores[i], HIGH);
       else
         digitalWrite(motores[i], LOW);
      }
    break;
    case 9:
      for(int i = 0; i < 8; i++){
       if(i == 1 || i == 3 || i == 4 || i == 6)
         digitalWrite(motores[i], LOW);
       else
         digitalWrite(motores[i], HIGH);
      }
    break;
    case 10:
     digitalWrite(motores[8], HIGH);
     digitalWrite(motores[9], LOW);
    break;
    case 11:
     digitalWrite(motores[8], LOW);
     digitalWrite(motores[9], LOW);
    break;
    case 12:
     digitalWrite(motores[8], LOW);
     digitalWrite(motores[9], HIGH);
    break;
  }
  
}

//Funcion utilizada para ir hacia algun objetivo ya identificado
//en este caso catch la pelota y fire la porteria
int recorrido(int i, int y){
  
  int bajo = y > 99 ? 120 : y > 69 ? 139 : 145;
  int alto = y > 200 ? 200 : y > 69 ? 191 : 181;
  
//La pelota esta en el primer tercio de cancha
  if(i > bajo && i < alto){
  //    Serial.println("Adelante");
//    lcd.setCursor(9,1);
//    lcd.print("Cen");
    return -1;
  }
  //La pelota esta a la izquierda
  else if(i <= bajo){
  //    Serial.println("Izquierda");
//    lcd.setCursor(9,1);
//    lcd.print("Izq");
    return 2;
  }
  //La pelota esta a la derecha
  else{
  //    Serial.println("Derecha");
//    lcd.setCursor(9,1);
//    lcd.print("Der");
    return 3;
  }
}  

void aprieta(){
  analogWrite(enable[0], 170);
  analogWrite(enable[1], 170);
  analogWrite(enable[2], 205);
  analogWrite(enable[3], 205);
}

void afloja(){
  analogWrite(enable[0], 120);
  analogWrite(enable[1], 120);
  analogWrite(enable[2], 120);
  analogWrite(enable[3], 120);
}

void cubrePorteria(){
  
  if(!adentroIzq && !adentroDer){
    scanPixy();
    if(viendo_porteria){
      lcd.setCursor(15,0);
      lcd.print("1");
      direccion = x_porteria > 160 ? 3 : 2;
    }
    else{
      lcd.setCursor(15,0);
      lcd.print("0");
      direccion = direccion == 2 ? 3 : 2;
    }
      
  }
  
  else{
    lcd.setCursor(15,0);
    lcd.print("2");
    direccion = !adentroIzq ? 3 : 2;

  }
  
  bool falloResistencia = false;
  
  while(!adentroIzq || !adentroDer){ 
    avanzar(direccion, true);
    colores();
    
//    if(on_color[0] == 1 || on_color[1] == 1){
//      falloResistencia = true; 
//      direccion = on_color[1] == 1 ? 3 : 2;
//      while(!adentroIzq || !adentroDer){
//        avanzar(direccion);
//        centro(adentroIzq, adentroDer);
//      }
//    }
    
    if(falloResistencia)
      break; 
    centro(adentroIzq, adentroDer);     
  }
 
  esp = direccion == 2 ? 3 : 2;

}


