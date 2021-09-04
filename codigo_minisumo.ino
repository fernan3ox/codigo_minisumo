//Motor A
int PWMA = 6; //Control de velocidad 
int AIN2 = 7; //Direccion
int AIN1 = 8; //Direccion
//Motor B
int PWMB = 11; //Control de velocidad
int BIN2 = 10; //Direccion
int BIN1 = 9; //Direccion 

int Led = 5; //13
int pulsador=12; 
int estado=0;
int activado=0;




int dip1=2;
int dip2=3;
int dip3=4;
int dip4=5;




void setup() 
{                
 
  //MOTOR A
   pinMode(PWMA, OUTPUT);
   pinMode(AIN1, OUTPUT);
   pinMode(AIN2, OUTPUT);
  //MOTOR B
   pinMode(PWMB, OUTPUT);
   pinMode(BIN1, OUTPUT);
   pinMode(BIN2, OUTPUT);
   
   pinMode(pulsador,INPUT); 
   pinMode(Led, OUTPUT); 

    while(true) 
   if (digitalRead(pulsador)==HIGH) //delay de 5s
  {
    for(int i=0;i<5; i++)
    {
      
      digitalWrite(Led,HIGH);
   delay(5000);
   digitalWrite(Led,LOW);
   delay(5000);
   estado=activado;
       }
 digitalWrite(Led,HIGH);
   break;
  }
}


void loop()  {
 if (estado == activado)
{
//*********************************************************************
if(digitalRead(dip1)==HIGH)
{
 adelante(100);
 delay(200);
 atras(100);
 delay(200);
 parar();
 delay(2000);
 
}

//*********************************************************+***********
if (digitalRead(dip2)==HIGH)
{
  giroderecha();
  delay(200);
  giroizquierda();
  delay(200);
  
  
 }
//*********************************************************************

if (digitalRead(dip3)==HIGH)
{
  
giroizquierdaatras();
delay (200);
giroderechaatras();
delay (200);
 
 
 }

//*******************************************************************

 if(digitalRead(dip4)==HIGH)
 {
  
  
  adelante(100);
 delay(200);
  giroizquierdaatras();
delay (200);
  
  
  }



//*****************************************************************


}
}




void adelante(int val) {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, val);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, val);
}
void atras(int val) {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, val);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, val);
}
void parar() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 0);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 0);
}

void derecha(int val) {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, val);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, val);
}

void izquierda(int val)
{
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, val);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, val);
}

void giroizquierda() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, 80);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, 250);
}

void giroderecha() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, 250);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, 250);
}

void giroizquierdaatras() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 250);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 80);
}

void giroderechaatras() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 250);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 80);
}
