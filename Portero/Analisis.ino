void analisis_de_datos(){
  colores();

  if(on_color[2] == 1){
    avanzar(1, true);
  }
  else{
  
    centro(adentroIzq, adentroDer);
    
    if(!adentroIzq || !adentroDer){
      cubrePorteria();
    }

    if(actIzq <= 10 || actDer <= 10)
<<<<<<< HEAD
      avanzar(1, true);  
=======
      avanzar(1);  
>>>>>>> refs/remotes/origin/master
  
    //Fuera del area
    abajo = true;
    if((adentroIzq && adentroDer && (actIzq > limiteDistancia || actDer > limiteDistancia))){
      abajo = false;
      avanzar(0, true);
    }
    
    scanPixy();
    if(viendo_Pelota){
      direccion = recorrido(x_pelota, y_pelota);
      if(esp == direccion)
        avanzar(-1, true);
      else{
        esp = -1;
        avanzar(direccion, true);
      }
    }
    else{    
      if(esp == -1){
        if(x_pelota > 160)
          avanzar(3, false);
        else
          avanzar(2, false);
      }
      else if(esp == 2)
        avanzar(3, false);
      else
        avanzar(2, false);
    }
  }
}
    
