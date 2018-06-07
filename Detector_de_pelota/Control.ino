//void P(int dir){
//    int ang = CalAng();
//    int diferencia = ang > 180 ? 360 - ang : ang;
//    
//    if(diferencia > 40)
//      Ap = 3;
//    else if(diferencia > 30)
//      Ap = 4;
//    else
//      Ap = 5;
//
//      
//    diferencia *= Ap;
//    p1 = 180;
//    p2 = 200;
//    
//    analogWrite(enable[0], p1);
//    analogWrite(enable[1], p2);
//    analogWrite(enable[2], p1);
//    analogWrite(enable[3], p2);
//    
//    p1 += diferencia;
//    p2 += diferencia;
//    
//    if(p1 > 255)
//      p1 = 255;
//    if(p2 > 255)
//      p2 = 255;
//    
//    if(ang > 180){
//
//        if(dir == 1){
//          analogWrite(enable[0], p1);
//          analogWrite(enable[1], p2);
//        }
//        else if(dir == 0){
//          analogWrite(enable[2], p1);
//          analogWrite(enable[3], p2);
//        }
//        else if(dir == 3){
//          analogWrite(enable[0], p1);
//          analogWrite(enable[3], p2);
//        }
//        else if(dir == 2){
//          analogWrite(enable[1], p2);
//          analogWrite(enable[2], p1);
//        }
//        else if(dir == 4){
//          analogWrite(enable[3], p2);
//        }
//        else if(dir == 5){
//          analogWrite(enable[1], p2);
//        }
//        else if(dir == 6){
//          analogWrite(enable[0], p1);
//        }
//        else if(dir == 7){
//          analogWrite(enable[2], p1);
//        }
//    }
//    else{
//       if(dir == 0){
//          analogWrite(enable[0], p1);
//          analogWrite(enable[1], p2);
//        }
//        else if(dir == 1){
//          analogWrite(enable[2], p1);
//          analogWrite(enable[3], p2);
//        }
//        else if(dir == 2){
//          analogWrite(enable[0], p1);
//          analogWrite(enable[3], p2);
//        }
//        else if(dir == 3){
//          analogWrite(enable[1], p2);
//          analogWrite(enable[2], p1);
//        }
//        else if(dir == 4){
//          analogWrite(enable[1], p2);
//        }
//        else if(dir == 5){
//          analogWrite(enable[3], p2);
//        }
//        else if(dir == 6){
//          analogWrite(enable[2], p1);
//        }
//        else if(dir == 7){
//          analogWrite(enable[0], p1);
//        }
//    }
//}
