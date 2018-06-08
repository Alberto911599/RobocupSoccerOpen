void scanPixy(){
  
  int signature;
  int area_temp;
  
  for(int i = 0; i < 20; i++){
    
    blocks = pixy.getBlocks();
    
    viendo_porteria = contador_porteria < 50;
    viendo_Pelota = contador_pelota < 50;
     
    if(contador_pelota < 51)
      contador_pelota++;
  
    if(contador_porteria < 51)
      contador_porteria++;
    
    if(blocks){
  
      for (int h = 0; h < blocks; h++){
  
  //      pixy.blocks[h].print();      
        
        signature = pixy.blocks[h].signature;
        area_temp = pixy.blocks[h].height * pixy.blocks[h].width;
        
        //Naranja Pelota
        if(signature == 2){
          
          contador_pelota = 0;
          x_pelota = pixy.blocks[h].x; //Regresa la coordenada x del centro del rectangulo (de 0 a 319)
          y_pelota = pixy.blocks[h].y; //Regresa la coordenada x del centro del rectangulo (de 0 a 199)
          
        }
  
        else if(signature == 3){
            contador_porteria = 0;
            x_porteria = pixy.blocks[h].x; //Regresa la coordenada x del centro del rectangulo de la porteria amarilla(de 0 a 319)
            y_porteria = pixy.blocks[h].y; //Regresa la coordenada x del centro del rectangulo de la porteria amarilla (de 0 a 199)
        }
      }
    }
  }
  imprimirPixy();
}

