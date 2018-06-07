
int CalAng(){
  int rotacion = 0;
  sensors_event_t event; 
  bno.getEvent(&event);
  rotacion = event.orientation.x;
  imprimirAng(rotacion);
  return rotacion;
}
  /*double aux = event.orientation.x;
  double difIzq = 0, difDer = 0;


  //////////////////////////
  String a = String((int)aux);
  if(aux < 10){
    a = "00" + a;
  }
  else if(aux < 100){
    a = "0" + a;
  }
  lcd.setCursor(8, 1);
  lcd.print(a);

  /////////////////////////
  if(cambio){
     aux = aux  - cal;
  }
  else{
    aux = aux + cal;
  }
  
 

  if(aux < 0){
    aux = 360 + aux;
  }

  if(aux > 360){
    aux = (int)aux % 360;
  }

  //Para la izquierda
  difDer = abs(aux - ant);
  difIzq = 360 - difDer;

  if(!(difDer < 40 || difIzq < 40)  entre){
   //Serial.println("Angulo movido**************************************************************************************************************************************");
    lcd.setCursor(0,1);
    lcd.print((int)aux);
    lcd.setCursor(4,1);
    lcd.print((int)ant);
    lcd.setCursor(15,0);
    lcd.print("C");
    
    cal = abs(ant - aux);

    if(ant >= aux){
      cambio = false;
    }
    else{
      cambio = true;
    }

    entre = false;
    return CalAng();
  }
  
  ant = aux;
  
  return aux;

}*/


