bool comprobacion(double d, bool ad){
  if(d <= 27 && !ad){
    ad = true;
  }
  return ad;
}

void centro(bool &adentroIzq, bool &adentroDer){
   
   actIzq = izq.ping_cm();
  
   if(actIzq > 0 && actIzq < 100){
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

   if(actDer > 0 && actDer < 100){
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

   imprimirUltrasonicos();
}
