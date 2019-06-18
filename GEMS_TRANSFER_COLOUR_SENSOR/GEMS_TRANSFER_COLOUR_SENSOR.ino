#include<Servo.h>
Servo s1;
Servo s2;

#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

#define s1pin 10
#define s2pin 11

// Stores frequency read by the photodiodes
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
int i,j;
char getcolour();

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(s1pin, OUTPUT);
  pinMode(s2pin, OUTPUT);
  pinMode(sensorOut, INPUT);

  s1.attach(s1pin);
  s2.attach(s2pin);
  s1.write(55);//////////////////////////////////////////////////////////////////////////
     
  // Setting frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}



void loop() { 
  delay(1000);
  s2.write (0);
  while(i<=130){
      s1.write(i);
      i++;
      delay(10);}
  i--;
  delay(1000);
//////////////////////DEFINE COLOUR for ROTATING SERVO2//////////////////
  char c = getcolour();
  Serial.println(c);
  switch(c){
     case '1': Serial.println("CASE 1");
          for(j=0;j<=50;j++){
              s2.write(j);
              delay(10);
            }
            break;
     case '2': Serial.println("CASE 2");
          for(j=0;j<=90;j++){
              s2.write(j);
              delay(10);
            }
            break; 
     case '3': Serial.println("CASE 3");
          for(j=0;j<=120;j++){
              s2.write(j);
              delay(10);
            }
            break;
     case '4': Serial.println("CASE 4");
     for(j=0;j<=17;j++){
              s2.write(j);
              delay(10);
            }
               break;
     default :  Serial.println("DEFAULT");
                return ;
      }
  delay(3000);//////////////////////////////////change////////////////////////////
  Serial.print("AFTER BREAK i = ");/////////
  Serial.println(i);
  while(i<=180){
         s1.write(i);
         i++;
         delay(30);
         }
  delay(2000);
  
  /*while(i>=55){
    s1.write(i);
    i--;
    delay(2);
   }
   i++;*/
   i=55;
   s1.write(i);

}

char getcolour(){
  int i=0;
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  int r=redFrequency;
   // Printing the RED (R) value
  Serial.print("R = ");
  Serial.print(redFrequency);
  delay(100);
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  int g=greenFrequency;
  // Printing the GREEN (G) value  
  Serial.print(" G = ");
  Serial.print(greenFrequency);
  delay(100);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH); 
  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  int b=blueFrequency;
  // Printing the BLUE (B) value 
  Serial.print(" B = ");
  Serial.print(blueFrequency);
  delay(100);



  if(r>15 &&r<45 &&g>15 &&g<50 &&b>12 &&b<40 )////////////upper 35,35,26
            {Serial.println("     COLOUR IS : WHITE");  
             }
     else if(r>179 &&r<229 &&g>181 &&g<240 &&b>139 &&b<180 )///////////upper 224,229,175
            Serial.println("     COLOUR IS : BLACK");
    
     else if(r>85 &&r<110 &&g>120 &&g<147 &&b>78 &&b<100 )//////////upper 155,105,51
            {Serial.println("     COLOUR IS : SKY BLUE");
            return '1';
              }
    else if(r>69 &&r<87 &&g>84 &&g<130 &&b>104 &&b<140)//////////upper 155,105,51
            {Serial.println("     COLOUR IS : YELLO");
            return '2';
              }
    else if(r>145 &&r<164 &&g>115 &&g<134 &&b>141 &&b<155)//////////upper 155,105,51
            {Serial.println("     COLOUR IS : GREEN"); 
            return '3';
              }
    else if(r>65 &&r<90 &&g>135 &&g<160 &&b>108 &&b<130)//////////upper 155,105,51
            {Serial.println("     COLOUR IS : ORANGE"); 
            return '4';
              }
    else {
      Serial.println();
      return '0';
    }
    
}
