//Leitura de distância com o sensor HC-SR04
#include <Ultrasonic.h>
#define trig1 2
#define echo1 3
#define trig2 4
#define echo2 5
#define trig3 6
#define echo3 7
#define motor1 9
#define motor2 10
#define motor3 11
const long mindist = 20;
const long trigdist = 150;
const long maxdist = 400;
long dist1;  //esquerda
long dist2;  //frente
long dist3;  //direita
long v1; //valor para pwm do motor 1
long v2; //valor para pwm do motor 2
long v3; //valor para pwm do motor 3

Ultrasonic ultrassom1(trig1,echo1); // define o nome do sensor(ultrassom)
Ultrasonic ultrassom2(trig2,echo2);
Ultrasonic ultrassom3(trig3,echo3);
 
// Esta função "setup" roda uma vez quando a placa e ligada ou resetada
 void setup() {
  Serial.begin(9600); //Habilita Comunicação Serial a uma taxa de 9600 bauds.
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
 }
 
// Função que se repete infinitamente quando a placa é ligada
 void loop()
 {
   dist1 = ultrassom1.distanceRead();// ultrassom.distanceRead() retorna a distancia em centímetros
   dist2 = ultrassom2.distanceRead();
   dist3 = ultrassom3.distanceRead();

   //Restringe as distâncias ao intervalo determinado
   if(dist1 < mindist){dist1 = mindist;}
   if(dist1 > maxdist){dist1 = maxdist;}
   if(dist2 < mindist){dist2 = mindist;}
   if(dist2 > maxdist){dist2 = maxdist;}
   if(dist3 < mindist){dist3 = mindist;}
   if(dist3 > maxdist){dist3 = maxdist;}

   //Definie intensidade de vibração dos motores de acordo com a leitura dos sensores
   if(dist1 <= trigdist){
      v1 = map(dist1, mindist, trigdist, 255, 0); 
      analogWrite(motor1,v1);
   }
   if(dist2 <= trigdist){
      v2 = map(dist2, mindist, trigdist, 255, 0);
      analogWrite(motor2,v2);
   }
   if(dist3 <= trigdist){
      v3 = map(dist3, mindist, trigdist, 255, 0);
      analogWrite(motor3,v3);
   }
   
   delay(50);
 }
