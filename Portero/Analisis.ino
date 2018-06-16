void analisis_de_datos(){

  //SI TE GIRARON TE ALINEAS 
  int ang = CalAng();
  if(ang > anguloPermitido && ang < 360 - anguloPermitido){
    esp = -1;
    alineacionP(ang);
  }

  else{
    //FOTO TRASERA
    colores();
    if(on_color[2] == 1){
      avanzar(1, false);
    }
    
    else{

      //FOTORRESISTENCIAS
      if(on_color[0] == 1 || on_color[1] == 1){
        avanzar(all_meco(), false);
      }

      //ACTUALIZAR VALORES DE ULTRASONICOS
      centro(adentroIzq, adentroDer);

      //DEMASIADO CERCA DE LA PROPIA PORTERIA
      if(actIzq <= 6 || actDer <= 6){
        avanzar(1, false);  
      }

      //ACTUALIZAR VALORES DE LA PIXY
      scanPixy();
      
      //FUERA DE LA PORTERIA
      if(!adentroIzq || !adentroDer ){
        //SALISTE HACIA EL FRENTE
        if(actIzq > limiteDistancia+20 || actDer > limiteDistancia+20){
          avanzar(0, false);
          delay(70);
        }
        avanzar(cubrePorteria(), false);
      }
      
      //DENTRO
      else{
        caso = 0;

        if(actIzq > limiteDistancia || actDer > limiteDistancia){
          avanzar(0, false);
          delay(70);
        }

        //SEGUIMIENTOS DE PELOTA
        if(viendo_Pelota){
          direccion = recorrido(x_pelota, y_pelota);
          if(esp == direccion){
            avanzar(-1, false);
            contadorDespeje++; 
          }
          else{
            esp = -1;
            contadorDespeje = 0;
            avanzar(direccion, true);
          }
          if(contadorDespeje >= 50 && y_pelota > 85){
            despeje();
          }
          
          //VERIFICAR SI LA PELOTA ESTA EN Y Y EN X CERCA PARA GOLPEAR
          kicker();
          
        }
        //BUSCAR PELOTA
        else{
          contadorDespeje = 0;    
          if(x_pelota > 160)
            avanzar(3, false);
          else
            avanzar(2, false);
        }      
      }
    }
  }
}
    
