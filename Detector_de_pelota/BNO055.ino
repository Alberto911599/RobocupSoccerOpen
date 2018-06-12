
int CalAng(){
  int rotacion = 0;
  sensors_event_t event; 
  bno.getEvent(&event);
  rotacion = event.orientation.x;
  imprimirAng(rotacion);
  return rotacion;
}
  
