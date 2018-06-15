void scanPixy(){
  
  int signature;
  int area_temp;
  
  for(int i = 0; i < 20; i++){
    
    blocks = pixy.getBlocks();
    
    viendo_Pelota = contador_pelota < 100;
    viendo_porteria = contador_porteria < 100;
    tendencia = y_porteria >= 40;
  
    if(!viendo_Pelota){
      if((direccion == 4 || direccion == 6 || direccion == 3))
        x_pelota = 399;
      if((direccion == 7 || direccion == 5 || direccion == 2))
        x_pelota = 0;
    }
    
    if(contador_pelota < 100)
      contador_pelota++; 
        
    if(contador_porteria < 100)
      contador_porteria++;
   
    
    if(blocks){
  
      for (int h = 0; h < blocks; h++){
       
        signature = pixy.blocks[h].signature;
        area_temp = pixy.blocks[h].height * pixy.blocks[h].width;
  
        
        //Naranja Pelota
        if(signature == 2 && area_temp  > 40){
  
            contador_pelota = 0;
            x_pelota = pixy.blocks[h].x; //Regresa la coordenada x del centro del rectangulo (de 0 a 319)
            y_pelota = pixy.blocks[h].y; //Regresa la coordenada x del centro del rectangulo (de 0 a 199)
            angPixy = x_pelota > 157 && x_pelota < 163 ? 90 : atan((199 - y_pelota)/abs(x_pelota - 160))*180/3.1416; 
    
        }
        
        //Porteria
        else if(signature == signature_porteria && area_temp  > 50){
                    
              contador_porteria = 0;
              x_porteria = pixy.blocks[h].x; //Regresa la coordenada x del centro del rectangulo de la porteria amarilla(de 0 a 319)
              y_porteria = pixy.blocks[h].y; //Regresa la coordenada x del centro del rectangulo de la porteria amarilla (de 0 a 199)
              alineado = x_porteria >= bajoPor && x_porteria <= altoPor ? 0 : x_porteria < bajoPor ? 8 : 9;
              
         }
       }
     }
   }
  imprimirPixy();  
} 



