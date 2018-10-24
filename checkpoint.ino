void Trisection()
{
    clr=color_calibrate();
   if((count1==0)and (clr==1))    //when red color is encountered at trisection
   {
    Left();
    Line_Follow_Forward();
    count1++;
   }
   if((count1==0)and (clr==2))  //when green color is encountered at trisection
   {
    Forward();
    Line_Follow_Forward();
    count1++;
   }
        
  if ((count1==0) &&(clr==3))   //when blue color is encountered at trisection
  {
       Right();
      Line_Follow_Forward();
      count1++;
  }
}

  
void checkpoint()
{
   //brown for negative
   //black for output
   //red for positive
      float volts;
      volts= analogRead(SS) * 0.0048828125;        // value from sensor * (5/1024)
  
       sharp_distance = 13 * pow(volts, -1);
       while(sharp_distance>10)
       {
        Stop();
        volts=analogRead(SS)*0.0048828125;
        sharp_distance=13*pow(volts, -1);
       }
       delay(6000);

    count2++;       
}

void hexagon1()
{  
   clr=color_calibrate();
   if(clr==1)
   {
     Left();
     Line_Follow_Forward();
     count5++;
   }     
   else if (clr==3)
   {
     Right();
     Line_Follow_Forward();
     count5++;
   }
   count3++;
   
}
void hexagon2()
{
   clr=color_calibrate();
   if(clr==1)
   {
      Right();
      Line_Follow_Forward();
      count6++;
   }  
   else if (clr==3)
   {
      Left();
      Line_Follow_Forward();
      count6++;
   }
}
   



 

