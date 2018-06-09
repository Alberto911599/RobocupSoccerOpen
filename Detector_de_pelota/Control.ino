int catch_fire_direct(){
  
  int temp = angPixy <= 35 ? (x_pelota < 160 ? 2 : 3) : 1;

  Kp = angPixy > 35 ? 5 : 17;

  int diferencia = abs(angPixy - 35) * Kp;
  
  p1 = x_pelota >= 145 ? 180 : diferencia;
  p2 = x_pelota <= 175 ? 200 : diferencia;

  p1 > 180 ? 180 : p1;
  p2 > 200 ? 200 : p2;

  if(p1 + p2 < 250){
    if(p1 > p2)
      p1 += 30;
    else
      p2 += 30;
  }

  analogWrite(enable[0], p1);
  analogWrite(enable[1], p2);
  analogWrite(enable[2], p1);
  analogWrite(enable[3], p2);

  return temp;
}

void alineacion(){
  int rotacion = CalAng();
  
  if(viendo_porteria){
    if(alineado != 0 && (rotacion > 360 - 40 || rotacion < 40)){

       int diferencia = x_porteria > altoPor ? x_porteria - altoPor : x_porteria - bajoPor;
    
       p1 = 100 + diferencia * 2;
       p2 = 100 + diferencia * 3;
  
       p1 > 180 ? 180 : p1;
       p2 > 200 ? 200 : p2;
  
      analogWrite(enable[0], p1);
      analogWrite(enable[1], p2);
      analogWrite(enable[2], p1);
      analogWrite(enable[3], p2);
        
      avanzar(alineado);
    }
  }
  
  if(!(rotacion > 360 - 45 || rotacion < 45)){

     int diferencia = rotacion < 180 ? rotacion : rotacion - 360;
    
     p1 = diferencia * 2;
     p2 = diferencia * 2.3;

     p1 > 180 ? 180 : p1;
     p2 > 200 ? 200 : p2;

    analogWrite(enable[0], p1);
    analogWrite(enable[1], p2);
    analogWrite(enable[2], p1);
    analogWrite(enable[3], p2);
     
     int temp =  rotacion > 180 ? 9 : 8;
     avanzar(temp);
   }
}
