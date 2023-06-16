//4-WAY JUCTION TRAFFIC CONTROL SIMULATION USING PROTEUS
//Declare the variables and assign pins
int r1 = 2; int y1 = 3; int g1 = 4;
int r2 = 5; int y2 = 6; int g2 = 7;
int r3 = 9; int y3 = 10; int g3 = 11;
int r4 = 12; int y4 = 13; int g4 = A5;
int pIN = 8;
int pwalk = A4; int pwait = A3;
 
void setup() {
  // put your setup code here, to run once:
//Define the pinMode
pinMode (r1, OUTPUT); pinMode (y1, OUTPUT); pinMode (g1, OUTPUT);
pinMode (r2, OUTPUT); pinMode (y2, OUTPUT); pinMode (g2, OUTPUT);
pinMode (r3, OUTPUT); pinMode (y3, OUTPUT); pinMode (g3, OUTPUT);
pinMode (r4, OUTPUT); pinMode (y4, OUTPUT); pinMode (g4, OUTPUT);
pinMode (pIN, OUTPUT);
pinMode (pwalk, OUTPUT); pinMode (pwait, OUTPUT);
//Set all red to HIGH
digitalWrite(r1,HIGH); digitalWrite(r2,HIGH); digitalWrite(r3,HIGH); digitalWrite(r4,HIGH); digitalWrite(pwait,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
//Condition: check if pedestrian button is on.
//Begin the motorist cycle at lane 1
int pbutton = digitalRead(pIN);
if (pbutton == HIGH){
      pedestrianCycle();  
}
else
{
//Set green HIGH r1 LOW and other red HIGH
digitalWrite (g1, HIGH); digitalWrite (r1, LOW); 

digitalWrite (r2, HIGH); digitalWrite (r3, HIGH); digitalWrite (r4, HIGH);
delay (1000); //I sec delay
}
/////....................................//////////
//Get ready to stop Lane 1
int pbutton2 = digitalRead(pIN);
if (pbutton2 == HIGH){
      pedestrianCycle();  
}
else
{
digitalWrite (g1, LOW); digitalWrite (r1, LOW);

digitalWrite (y1, HIGH);
digitalWrite (r2, HIGH); digitalWrite (r3, HIGH); digitalWrite (r4, HIGH); 
delay (1000); //I sec delay
}
////..................................///////////
//Go Lane 2
int pbutton3 = digitalRead(pIN);
if (pbutton3 == HIGH){
      pedestrianCycle();  
}
else
{
digitalWrite (y1, LOW);  

digitalWrite (g2, HIGH); digitalWrite (r2, LOW);
digitalWrite (r1, HIGH); digitalWrite (r3, HIGH); digitalWrite (r4, HIGH); 
delay (1000); //I sec delay
}
////...........................////
//Get ready lane 2 to stop
int pbutton4 = digitalRead(pIN);
if (pbutton4 == HIGH)
{
  pedestrianCycle();
}
else {
digitalWrite (g2, LOW); digitalWrite (r2, LOW);

digitalWrite (y2, HIGH); 
digitalWrite (r1, HIGH); digitalWrite (r3, HIGH); digitalWrite (r4, HIGH); 
delay (1000);
}
////....................////
//Lane 3 Go
int pbutton5 = digitalRead(pIN);
if (pbutton5 == HIGH)
{
  pedestrianCycle();
}
else {
digitalWrite (y2, LOW); 
 
digitalWrite (g3, HIGH); digitalWrite (r3, LOW);
digitalWrite (r1, HIGH); digitalWrite (r2, HIGH); digitalWrite (r4, HIGH); 
delay (1000);
}
////.................///////
//Get ready to stop Lane 3
int pbutton6 = digitalRead(pIN);
if (pbutton6 == HIGH)
{
  pedestrianCycle();
}
else {
digitalWrite (g3, LOW); digitalWrite (r3, LOW);
 
digitalWrite (y3, HIGH);
digitalWrite (r1, HIGH); digitalWrite (r2, HIGH); digitalWrite (r4, HIGH); 
delay (1000);
}
////.................................////
//Lane 4 Go
int pbutton7 = digitalRead(pIN);
if (pbutton7 == HIGH)
{
  pedestrianCycle();
}
else {
digitalWrite (y3, LOW); 

digitalWrite (g4, HIGH); digitalWrite (r4, LOW);
digitalWrite (r1, HIGH); digitalWrite (r2, HIGH);  digitalWrite (r3, HIGH);
delay (1000);
}
////....................................////
//Get ready to stop Lane 4
int pbutton8 = digitalRead(pIN);
if (pbutton8 == HIGH)
{
  pedestrianCycle();
}
else {
digitalWrite (g4, LOW); digitalWrite (r4, LOW);
 
digitalWrite (y4, HIGH);
digitalWrite (r1, HIGH); digitalWrite (r2, HIGH); digitalWrite (r3, HIGH); 
delay (1000);
}

digitalWrite (y4, LOW); digitalWrite (r4, HIGH); 
}


//pedestrianCycle function
void pedestrianCycle(){
//  Put ON/OFF the pedestrian lights simultaneously
//All motorists red are set HIGH and green and yellow to LOW.
//Pedestrian green is set HIGH and red to LOW
digitalWrite(r1, HIGH); digitalWrite(r2, HIGH); digitalWrite(r3, HIGH); digitalWrite(r4, HIGH); digitalWrite(pwalk, HIGH);
digitalWrite(y1, LOW); digitalWrite(y2, LOW); digitalWrite(y3, LOW); digitalWrite(y4, LOW); digitalWrite(pwait, LOW);
digitalWrite(g1, LOW); digitalWrite(g2, LOW); digitalWrite(g3, LOW); digitalWrite(g4, LOW);

digitalWrite (pwalk, HIGH); digitalWrite (pwait, LOW);
delay (1000);
digitalWrite (pIN, LOW);
digitalWrite (pwalk, LOW); digitalWrite (pwait, HIGH);
}
