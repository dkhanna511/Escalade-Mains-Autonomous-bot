#include <SpacebrewYun.h>

/* A few assumptions
   Obstacle 1: trisection, count=0
        left if red (value returned = 1)
        forward is green   (value returned = 2)
        Right if blue   (value returned = 3)
        black   (value returned = 4)
        yellow  (value returned = 5)
   Obstacle 2 : checkpoint 1
        color=green, count2=1
   obstacle 3: wall avoider
        use of ultrasonic sensor
   Obstacle 4: hexagon 1
        left if red
        right if blue
   Obstacle 5 : wall follower
        use of ultrasnic sensor
   Obstacle 6:  hexagon 2
        left if blue
        right if red
        
   Obstacle 7: See Saw
       checkpoint: color=green 
        
 */

//Logic applied

int count1=0, count2=0, count3=0, count4=0, count5=0, count6=0;
 
//initialisations for IR sensors
#define LS A2
#define MS A1
#define RS A0
int ls=0, ms=0, rs=0; 
int thresh=400;


//initialisations for color sensor 
#define S0 22
#define S1 23
#define S2 24
#define S3 25
#define sensorData 26
int frequency=0;
int datar=0, datab=0, datag=0;

//initialisations for ultrasonic sensor
const int trigPl = 28;
const int echoPl = 29;
const int trigPm = 30;
const int echoPm = 31;
const int trigPr = 32;
const int echoPr = 33;

long duration_l;
int distance_l;
long duration_m;
int distance_m;
long duration_r;
int distance_r;


//pin declarations for motors
#define LM1  34
#define LM2  35
#define RM1  37
#define RM2  36

//initialisations for sharp sensor
#define SS 26
volatile float sharp_distance=0;

int dist;
int clr;

void setup() {
  // put your setup code here, to run once:
  pinMode(LS, INPUT);
  pinMode(MS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  
  pinMode(trigPl, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPl, INPUT); // Sets the echoPin as an Input
  pinMode(trigPm, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPm, INPUT); // Sets the echoPin as an Input
  pinMode(trigPr, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPr, INPUT); // Sets the echoPin as an Input
  
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorData , INPUT);
  //Setting frequency scaling to 20%
  Serial.begin(9600);
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

void loop() {
   // put your main code here, to run repeatedly:
   
  Line_Follow_Forward();
  clr=color_calibrate();
  if((count1==0) and (count2==0) and (count3==0))
     Trisection();
  
  if((clr==2) and (count1>0) and (count2==0) and (count3==0))
     checkpoint();
     
  if((count1==0) and (count2> 0) and (count3 < 0) and (count4<0) and (count5< 7))
     hexagon1();
 
  if((count1>0) and (count2>0) and (count3>0) and (count4<0) and (count6< 7))
     hexagon2();
  
  } 
//  ultrasonic_sensor();+++++++++++++++++++++
    



int color_calibrate()
{ int color;
     //set S2 and S3 to low in order to sense the RED color
 digitalWrite(S2, LOW);
 digitalWrite(S3, LOW);
 //store data in global variable
 datar=pulseIn(sensorData, LOW);
 
//For GREEN COLOR data
 digitalWrite(S2, HIGH);
 digitalWrite(S3, HIGH);
 datag=pulseIn(sensorData, LOW);
 delay(20);
//For BLUE COLOR data
 digitalWrite(S2, LOW);
 digitalWrite(S3, HIGH);
 datab=pulseIn(sensorData, LOW);
 delay(20);
 //delay(2000);
 color=color_sensor(datag, datab, datar);
 return color;
}

  void Line_Follow_Forward()
  {
  ls = analogRead(LS);
  ms = color_calibrate();
  rs = analogRead(RS);
  if((ls<thresh)&&(ms==4)&&(rs<thresh))                     //000
    Stop();                                         
  else if ((ls>thresh) && (ms ==4 or ms==3) && (rs <thresh))         //001
    Left();
  //else if ((ls>thresh) && (ms!=4) && (rs >thresh))       //010
  //  Left();
  else if ((ls >thresh) && (ms !=4) && (rs <thresh))        //011
    Left();    
  else if ((ls <thresh) && (ms ==4 or ms ==3) && (rs >thresh))        //100
    Right();
  else if ((ls<thresh) && (ms==4 or ms==3) && (rs<thresh))           //101
    Forward();
  
  else if ((ls<thresh) && (ms !=4) && (rs >thresh))         //110
    Right();
  else if ((ls<thresh) && (ms !=4) && (rs <thresh))         //111
  {
    Forward();  
    ultrasonic_sensor();
  }
  else Forward();

    Serial.print(ls );
    Serial.print("\t");
    Serial.print( clr);
    Serial.print("\t");
    Serial.print(rs);
    Serial.print("\n");
}
        

