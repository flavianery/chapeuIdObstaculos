//Leitura de distância com o sensor HC-SR04
#include <Ultrasonic.h>
#define trig1 2 
#define echo1 3 
#define motor1 9
const long mindist = 20;
const long trigdist = 150;
const long maxdist = 400;
long dist1;
long v1; //valor para pwm do motor 1
Ultrasonic ultrassom1(trig1,echo1); // define o nome do sensor(ultrassom)

// Esta função "setup" roda uma vez quando a placa e ligada ou resetada
void setup() {
   pinMode(motor1,OUTPUT);
 }

// Função que se repete infinitamente quando a placa é ligada
void loop() {
   dist1 = ultrassom1.distanceRead();// ultrassom.distanceRead() retorna a             // distancia em centímetros 

  //Restringe a distância ao intervalo determinado
   if(dist1 < mindist){dist1 = mindist;}
   if(dist1 > maxdist){dist1 = maxdist;}  

  //Define intensidade de vibração dos motores de acordo com a distância
   if(dist1 <= trigdist){ 
      v1 = map(dist1, mindist, trigdist, 255, 0);
      analogWrite(motor1,v1);
   }

   delay(50);
} 

