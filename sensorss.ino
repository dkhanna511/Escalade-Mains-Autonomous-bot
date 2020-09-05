int color_sensor( int green, int blue, int red)
{
   if((red< blue)&&(red<green))
     return 1;
   
   else if((green<blue)&&(green<blue)) 
     return 2;
     
   else if ((blue>150)&&(green>150)&&(red>150))
     return 4;  
     
   //else if ((red< 40)&&(blue<100) &&( green < 100))
     //return 5;
   
   else return 3;  

}

void ultrasonic_sensor()
{
    digitalWrite(trigPl, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPl, LOW);
    duration_l = pulseIn(echoPm, HIGH);
    distance_l= duration_l*0.034/2; 
    
    digitalWrite(trigPm, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPm, LOW);
    
    duration_m = pulseIn(echoPm, HIGH);
    distance_m= duration_m*0.034/2;  
    
    digitalWrite(trigPr, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPr, LOW);
    
    duration_r = pulseIn(echoPr, HIGH);
    distance_r= duration_r*0.034/2;  
    
    if((distance_l < 7)&&(distance_r > 7))
       Right();
    
    else if((distance_l> 5)&&(distance_r < 7))
      Left();    
    
    else if((distance_l> 5)&&(distance_r > 5))
      Forward();    

}

void wall_avoider()
{
    digitalWrite(trigPl, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPl, LOW);
    
    duration_l = pulseIn(echoPm, HIGH);
    distance_l= duration_l*0.034/2; 
    
    digitalWrite(trigPm, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPm, LOW);
    
    duration_m = pulseIn(echoPm, HIGH);
    distance_m= duration_m*0.034/2;  
    
    digitalWrite(trigPr, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPr, LOW);
    
    duration_r = pulseIn(echoPr, HIGH);
    distance_r= duration_r*0.034/2;  
}

