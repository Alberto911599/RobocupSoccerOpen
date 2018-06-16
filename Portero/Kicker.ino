void kicker(){  
  //VERIFICAR SI LA PELOTA ESTA EN Y Y EN X CERCA PARA GOLPEAR
  bool Kb = millis() - tiempoKick > 8000 && !actKick;
  bool Rb = actKick && millis() - tiempoKick > 2000;
  if(Kb){
    if(y_pelota >= 170 && x_pelota > 130 && x_pelota < 190){
      actKick = true;
      tiempoKick = millis();
      digitalWrite(24,LOW);
    }
  }
  if(Rb){
    digitalWrite(24,HIGH);
    actKick = false;
  }
}
