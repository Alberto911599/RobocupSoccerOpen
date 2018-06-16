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

//SEGUNDA LINEA AL INICIO
void imprimirAng(int rot){
  lcd.setCursor(12, 0);
  lcd.print(formatoGral(rot));
}


//SEGUNDA LINEA AL FINAL
void imprimirRes(){
  lcd.setCursor(12, 1);
  lcd.print(on_color[0]);
  lcd.setCursor(13, 1);
  lcd.print(on_color[1]);
  lcd.setCursor(14, 1);
  lcd.print(on_color[2]);
  lcd.setCursor(15 , 1);
  lcd.print(on_color[3]);
}


//PRIMER LINEA
void imprimirPixy(){
//  lcd.setCursor(0,0);
//  if(viendo_Pelota){
//    lcd.print("1");
//  }
//  else{
//    lcd.print("0");
//  }
//  lcd.setCursor(1,0);
//  if(viendo_porteria){
//    lcd.print("1");
//  }
//  else{
//    lcd.print("0");
//  }
  lcd.setCursor(2,0);
  if(tendencia){
    lcd.print("1");
  }
  else{
    lcd.print("0");
  }

  lcd.setCursor(4, 0);
  lcd.print(formatoGral(x_pelota));

  lcd.setCursor(8, 0);
  lcd.print(formatoGral(y_pelota));
//
  lcd.setCursor(0, 1);
  lcd.print(formatoGral(angPixy));
  
  lcd.setCursor(4,1);
  lcd.print(formatoGral(contador_pelota));
//  lcd.print(y_pelota);

  lcd.setCursor(8,1);
//  lcd.print(x_pelota);
  lcd.print(formatoGral(contador_porteria));

//  lcd.setCursor(5,1);
//  lcd.print(alineado);

  
}


void imprimirmovimiento(int evento){
//  lcd.setCursor(0,1);
//  lcd.print(evento);
  }

void imprimirkicker(){
  lcd.setCursor(0,1);
  lcd.print(conta_kicker);
}
