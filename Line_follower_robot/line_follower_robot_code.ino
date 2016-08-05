/*------ Program of line follower ROBOT (c) Helmi haddad----- */
/*-------definning speed-------*/
#define Fs 70
#define Rs -70
/*-------definning Inputs------*/
#define LS 8    // left sensor
#define RS 9      // right sensor
#define RCS 10     // right center sensor
#define LCS 11     // left center sensor
/*-------definning Outputs------*/
/*-------Left Motor-------------*/
#define LME A1      // left motor enabel
#define LM1 3       // left motor
#define LM2 4       // left motor
/*-------Right Motor -------*/
#define RME A2      // right motor enabel
#define RM1 5       // right motor
#define RM2 6       // right motor

/*-----defining function ------*/

void Left_Forward() 
{
  analogWrite(LME , Fs);
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
}

void Left_Reverse() 
{
  analogWrite(LME , Rs);
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
}

void Right_Forward()
{
  analogWrite(RME , Fs);
  digitalWrite(RM2, LOW);
  digitalWrite(RM2, HIGH);
}

void Right_Reverse()
{
  analogWrite(RME , Rs);
  digitalWrite(RM2, HIGH);
  digitalWrite(RM2, LOW);
}

void Go(int s)
{
  digitalWrite(LME, s);
  digitalWrite(RME, s);
}

void Forward()
{
  Left_Forward();
  Right_Forward();
}

void Reverse() 
{
  Left_Reverse();
  Right_Reverse();
}

void Turn_Left() 
{
  Right_Forward();
  Left_Reverse();
}

void Turn_Right() 
{
  Right_Reverse();
  Left_Forward();
}

void Stop() 
{
  digitalWrite(LME,0);
  digitalWrite(RME,0);
}

void LineFollower()
{
  int TRS,TLS,TRCS,TLCS;
  TRS = digitalRead(LS);
  TLS = digitalRead(RS);
  TRCS = digitalRead(RCS);
  TLCS = digitalRead(RS);

  
  if((!TRS&&!TLCS&&!TLCS&!TRS)||(!TLS&&TLCS&&TRCS&&!TRS)||(TLS&&!TLCS&&!TRCS&&TRS)||(TLS&&TLCS&&TRCS&&TRS))    // Move Forward
  {
    Forward();
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS))     // Turn right
  {
    Turn_Right();
  }
  
  if(digitalRead(LS) && !(digitalRead(RS)))     // turn left
  {
    Turn_Left();
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
  {
    Forward();
  }
}  

/*------- Program -----------*/


void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(LME, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(RME, OUTPUT);
}
void loop()
{
  LineFollower();
}
