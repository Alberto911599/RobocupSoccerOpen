void kicker(){
//Verificar que hayan pasado los 7 segundos entre golpe y golpe
if(millis() > tiempo_kicker + 7000){

 //Descargar golpe
 digitalWrite(24,LOW);
 delay(70);
 digitalWrite(24,HIGH);

 //Actualizar el ultimo golpe
 tiempo_kicker = millis();
}  
  
}
