void imprimirAng(int rot){
  String angulo = String((int)rot);
  if(rot < 10){
    angulo = "00" + angulo;
  }
  else if(rot < 100){
    angulo = "0" + angulo;
  }
  lcd.setCursor(5, 1);
  lcd.print(angulo);
}

void imprimirRes(){
  lcd.setCursor(4, 1);
  lcd.print(on_color[0]);
  lcd.setCursor(5, 1);
  lcd.print(on_color[1]);
  lcd.setCursor(6, 1);
  lcd.print(on_color[2]);
  lcd.setCursor(7 , 1);
  lcd.print(on_color[3]);
}

void imprimirPixy(){
  lcd.setCursor(13,1);
  if(viendo_Pelota){
    lcd.print("1");
  }
  else{
    lcd.print("0");
  }
  lcd.setCursor(14,1);
  if(viendo_porteria){
    lcd.print("1");
  }
  else{
    lcd.print("0");
  }
  lcd.setCursor(15,1);
  if(tendencia){
    lcd.print("1");
  }
  else{
    lcd.print("0");
  }
  lcd.setCursor(0,1);

    lcd.print(y_porteria);
}

