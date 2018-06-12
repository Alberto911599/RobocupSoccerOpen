void P(int dir, bool rapido){
    int ang = CalAng();
    int diferencia = ang > 180 ? 360 - ang : ang;
    int diferenciaCam = abs(x_pelota - 160);
    
    if(diferencia > 40)
      Ap = 3.5;
    else if(diferencia > 30)
      Ap = 3;
    else
      Ap = 2.5;
    
    diferencia *= Ap;
    
    if(rapido){
      p1 = diferenciaCam > 50 ? 170 : 1.5*diferenciaCam;
      p2 = diferenciaCam > 50 ? 190 : 1.5*diferenciaCam;;
    }

    else{
      p1 = 150;
      p2 = 170;
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
    
    if(ang > 180){

        if(dir == 1){
          analogWrite(enable[0], p1);
          analogWrite(enable[1], p2);
        }
        else if(dir == 0){
          analogWrite(enable[2], p1);
          analogWrite(enable[3], p2);
        }
        else if(dir == 3){
          analogWrite(enable[0], p1);
          analogWrite(enable[3], p2);
        }
        else{
          analogWrite(enable[1], p2);
          analogWrite(enable[2], p1);
        }
    }
    else{
       if(dir == 0){
          analogWrite(enable[0], p1);
          analogWrite(enable[1], p2);
        }
        else if(dir == 1){
          analogWrite(enable[2], p1);
          analogWrite(enable[3], p2);
        }
        else if(dir == 2){
          analogWrite(enable[0], p1);
          analogWrite(enable[3], p2);
        }
        else{
          analogWrite(enable[1], p2);
          analogWrite(enable[2], p1);
        }
    }
}

void alineacionP(int ang){
    int diferencia = 0;
    int tempDir;
    if(ang > 180){
      diferencia = (360 - ang)*Kp;
      tempDir = 9; 
    }
    else{
      tempDir = 8;
      diferencia = ang * Kp;
    }
    diferencia = diferencia > 160 - baseRotacion ? 160 - baseRotacion : diferencia;
    lcd.setCursor(0,0);
    lcd.print(formatoGral(diferencia));
    analogWrite(enable[0], baseRotacion + diferencia);
    analogWrite(enable[1], baseRotacion + diferencia);
    analogWrite(enable[2], baseRotacion + diferencia);
    analogWrite(enable[3], baseRotacion + diferencia);
    avanzar(tempDir, true);
}

