int catch_fire_direct(){
  
  int temp = angPixy <= 35 ? (x_pelota < 160 ? 2 : 3) : 1;
  if(angPixy < 24u){
    if(x_pelota < 160)
      temp = 7;
    else
      temp = 4;
    p1 = 180;
    p2 = 190;
  }
  else{
    Kp = angPixy > 35 ? 7 : 20;
  
    int diferencia = abs(angPixy - 35) * Kp;
    
    p1 = x_pelota >= 145 ? 180 : diferencia;
    p2 = x_pelota <= 175 ? 200 : diferencia;
  
    p1 > 170 ? 170 : p1;
    p2 > 180 ? 180 : p2;
  
    if(p1 + p2 < 280){
      if(p1 > p2)
        p1 += 45;
      else
        p2 += 45;
    }
  }

  analogWrite(enable[0], p1);
  analogWrite(enable[1], p2);
  analogWrite(enable[2], p1);
  analogWrite(enable[3], p2);

  return temp;
}

bool alineacionPorteria(){
  
  int rotacion = CalAng();
  
  if(viendo_porteria){
    if((alineado == 8  && !(rotacion > 180 && rotacion < 360 - anguloPorteria)) || (alineado == 9 && !(rotacion < 180 && rotacion > anguloPorteria))){

       int diferencia = x_porteria > altoPor ? x_porteria - altoPor : x_porteria - bajoPor;
    
       p1 = 140 + diferencia * 2;
       p2 = 140 + diferencia * 2.3;
  
       p1 > 180 ? 180 : p1;
       p2 > 180 ? 180 : p2;
  
      analogWrite(enable[0], p1);
      analogWrite(enable[1], p2);
      analogWrite(enable[2], p1);
      analogWrite(enable[3], p2);
        
      avanzar(alineado);
      delay(20);
      return true;
    }
    return false;
  }
}

void alineacionBNO(){
  
  int rotacion =  CalAng();
  
  if(!(rotacion > 360 - anguloBNO || rotacion < anguloBNO)){

     int diferencia = rotacion < 180 ? rotacion : 360 - rotacion;
    
     p1 = 120 + diferencia * Kp;
     p2 = 120 + diferencia * Kp;

     p1 > 165 ? 165 : p1;
     p2 > 170 ? 170 : p2;

    analogWrite(enable[0], p1);
    analogWrite(enable[1], p2);
    analogWrite(enable[2], p1);
    analogWrite(enable[3], p2);
     
     int temp =  rotacion > 180 ? 9 : 8;
     avanzar(temp);
   }
}

void postP(int dir){
  int ang = CalAng();
  int diferencia = ang > 180 ? 360 - ang : ang;

  diferencia *= Ap;

  if(dir == 7 || dir == 4){
    p1 = 170;
    p2 = 190;
  }
  else{
    p1 = 140;
    p2 = 140;
  }

  analogWrite(enable[0], p1);
  analogWrite(enable[1], p2);
  analogWrite(enable[2], p1);
  analogWrite(enable[3], p2);
  
  p1 += diferencia;
  p2 += diferencia;

   if(p1 > 255)
    p1 = 255;
   if(p2 > 255)
    p2 = 255;

 if(ang <= 180){
  if(dir == 0){
    analogWrite(enable[0], p1);
    analogWrite(enable[1], p2);
  }
  else if(dir == 3){
    analogWrite(enable[1], p2);
    analogWrite(enable[2], p1);
  }
  else if(dir == 4){
    analogWrite(enable[1], p2);
  }
  else if(dir == 7){
    analogWrite(enable[0], p1);
  }
  else{
    analogWrite(enable[0], p1);
    analogWrite(enable[3], p2);
  }
 }
 else{
  if(dir == 0){
    analogWrite(enable[2], p1);
    analogWrite(enable[2], p2);
  }
  else if(dir == 4){
    analogWrite(enable[3], p2);
  }
  else if(dir == 3){
    analogWrite(enable[0], p1);
    analogWrite(enable[3], p2);
  }
  else if(dir == 2){
    analogWrite(enable[1], p2);
    analogWrite(enable[2], p1);
  }
  else{
    analogWrite(enable[2], p1);
  }
 }
}

