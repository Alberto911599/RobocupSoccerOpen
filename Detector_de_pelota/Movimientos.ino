void avanzar(int evento) {
  imprimirmovimiento(evento);
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

void aprieta(){
  for(int i = 0; i < 5; i++){
    analogWrite(enable[i], 255);
  }
}

void afloja(){
  analogWrite(enable[0], 180);
  analogWrite(enable[1], 200);
  analogWrite(enable[2], 180);
  analogWrite(enable[3], 200);
}

void alineacion(){
  int rotacion = CalAng();
  
  if(viendo_porteria){
    if(alineado != 0 && (rotacion > 360 - 40 || rotacion < 40)){
      //int temp = x_porteria > 260 ? 9 : 8;
      avanzar(alineado);
    }
  }
  
//  else if (tendencia){
//    if(x_porteria > 160){
//      
//      if(rotacion > 40 || rotacion < 20){
//        if(rotacion > 30 && rotacion < 210)
//          avanzar(8);
//         else
//          avanzar(9);
//      }
//    }
//    else{
//       if(rotacion > 340 || rotacion < 310){
//        if(rotacion > 150 && rotacion < 330)
//          avanzar(9);
//         else
//          avanzar(8);
//      }
//    } 
//  }
  if(!(rotacion > 360 - 50 || rotacion < 50)){
     int temp =  rotacion > 180 ? 9 : 8;
     avanzar(temp);
     delay(6);
     rotacion = CalAng();
   }
}


