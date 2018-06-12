String formatoGral(int n){
  String str = String((int)n);
  if(n < 10){
    str = "00" + str;
  }
  else if(n < 100){
    str = "0" + str;
  }
  return str;
}

void imprimirAng(int rot){
  lcd.setCursor(13, 0);
  lcd.print(formatoGral(rot));
}

void imprimirRes(){
  lcd.setCursor(8, 1);
  lcd.print(on_color[0]);
  lcd.setCursor(9, 1);
  lcd.print(on_color[1]);
  lcd.setCursor(10, 1);
  lcd.print(on_color[2]);
  lcd.setCursor(11, 1);
  lcd.print(on_color[3]);
}

void imprimirPixy(){
  lcd.setCursor(0,0);
  if(viendo_Pelota){
    lcd.print("1");
  }
  else{
    lcd.print("0");
  }
  lcd.setCursor(1,0);
  if(viendo_porteria){
    lcd.print("1");
  }
  else{
    lcd.print("0");
  }
  lcd.setCursor(3,0);
  lcd.print(formatoGral(contador_pelota));
  lcd.setCursor(7,0);
  lcd.print(formatoGral(contador_porteria));
  lcd.setCursor(11,0);
  lcd.print(caso);
}

void imprimirUltrasonicos(){
  lcd.setCursor(0, 1);
  lcd.print(formatoGral(actIzq));
  lcd.setCursor(4, 1);
  lcd.print(formatoGral(actDer));
  lcd.setCursor(14,1);
  lcd.print(adentroIzq);
  lcd.setCursor(15,1);
  lcd.print(adentroDer);
}

