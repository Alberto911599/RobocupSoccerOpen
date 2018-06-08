void scanPixy(){
  
  int signature;
  int area_temp;
  
  blocks = pixy.getBlocks();
  
  viendo_Pelota = contador_pelota < 10;
  viendo_porteria = contador_porteria < 10;
  tendencia = y_porteria >= 60;

  if(!viendo_Pelota){
    if((direccion == 4 || direccion == 6 || direccion == 3))
      x_pelota = 399;
    if((direccion == 7 || direccion == 5 || direccion == 2))
      x_pelota = 0;
  }
  
  if(contador_pelota < 10)
    contador_pelota++; 
      
  if(contador_porteria < 10)
    contador_porteria++;
 
  
  if(blocks){

    for (int h = 0; h < blocks; h++){
     
      signature = pixy.blocks[h].signature;
      area_temp = pixy.blocks[h].height * pixy.blocks[h].width;
      //Naranja Pelota
      if(signature == 2){

          contador_pelota = 0;
          x_pelota = pixy.blocks[h].x; //Regresa la coordenada x del centro del rectangulo (de 0 a 319)
          y_pelota = pixy.blocks[h].y; //Regresa la coordenada x del centro del rectangulo (de 0 a 199) 
  
      }
      
      //Porteria
      else if(signature == signature_porteria && area_temp  > 100){
                  
            contador_porteria = 0;
            x_porteria = pixy.blocks[h].x; //Regresa la coordenada x del centro del rectangulo de la porteria amarilla(de 0 a 319)
            y_porteria = pixy.blocks[h].y; //Regresa la coordenada x del centro del rectangulo de la porteria amarilla (de 0 a 199)
            alineado = x_porteria >= 80 && x_porteria <= 260 ? 0 : x_porteria < 60 ? 8 : 9;
            
       }
     }
   }
   imprimirPixy();  
} 



