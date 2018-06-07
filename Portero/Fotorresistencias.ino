void colores(){
  on_color[0] = digitalRead(3);
  on_color[1] = digitalRead(2);
  on_color[2] = digitalRead(18);
  on_color[3] = digitalRead(19);
  imprimirRes();
}

//int all_meco(){
//  
//    int temp;
//    
////    //lados
////    if(on_color[0] == 1){
////     
////      temp = on_color[1] == 1 ? 3 : 2;
////
////      while(!adentroIzq && !adentroDer){
////        avanzar(temp);
////        alineacion(false);
////        centro(adentroIzq, adentroDer);
////      }
////
////    }
//    //frentes
////    else{
////      long time = millis();
////      while(millis() < time + 250){
////        avanzar(1);
////        centro(adentroIzq, adentroDer);
////      }
////    }
//
//    return -1;
//}
  
  


