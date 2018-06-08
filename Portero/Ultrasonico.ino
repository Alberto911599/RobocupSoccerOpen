bool comprobacion(double d, bool ad){
  if(d >= 60 && ad){
    ad = false;
  }
  if(d <= 20 && !ad){
    ad = true;
  }
  return ad;
}


void centro(bool &adentroIzq, bool &adentroDer){
   
   actIzq = izq.ping_cm();
  
   if(actIzq > 0){
      if(abs(actIzq - anteIzq) > 15){
        if(anteIzq > actIzq)
          adentroIzq = true;
        else
          adentroIzq = false;
      }
   }
    else{
      actIzq = anteIzq;
    }

   anteIzq = actIzq;

   adentroIzq = comprobacion(actIzq, adentroIzq); 

   delay(6);

   actDer = der.ping_cm();

   if(actDer > 0){
      if(abs(actDer - anteDer) > 17){
        if(anteDer > actDer)
          adentroDer = true;
        else
          adentroDer = false;
      }
   }
   else{
    actDer = anteDer;
}

   anteDer = actDer;

   adentroDer = comprobacion(actDer, adentroDer);

   i = String((int) actIzq); 
   lcd.setCursor(4,0);
   if(actIzq < 10 )
    i = " " + i;
   lcd.print(i);

   d = String((int) actDer); 
   lcd.setCursor(12,0);
   if(actDer < 10 )
    d = " " + d;
   lcd.print(d);

     
   if(adentroIzq){
      lcd.setCursor(14,1);
      lcd.print("1");
   }
   else{
      lcd.setCursor(14,1);
      lcd.print("0");
   }
   if(adentroDer){
      lcd.setCursor(15,1);
      lcd.print("1");
   }
   else{
      lcd.setCursor(15,1);
      lcd.print("0");
   }
   
}
