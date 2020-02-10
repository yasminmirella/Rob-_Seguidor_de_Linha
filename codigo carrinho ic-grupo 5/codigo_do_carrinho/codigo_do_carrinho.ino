/**********************************************************
* UNIVERSIDADE FEDERAL DE PERNAMBUCO - UFPE
* CENTRO DE INFORMARICA - CIN
* INTRODUCAO A PROGRAMACAO COM GALILEO - IF668 EC
* GRUPO 5: BRUNA CABRAL PEDROSA DE LIMA
           LUIZ FERNANDO RAMOS DE TOLEDO
           LUCAS VINICIUS ARAUJO DA SILVA SANTOS
           YASMIN MIRELLA SILVA CRIOLO
           MORGANA BEATRIZ FEIJO GALAMBA
           MAURO JORGE SANTOS DE SANTANA
CODIGO DO CARRINHO SEGUIDOR DE LINHA
********************************************************/

#include "Ultrasonic.h"
#define echoPin 10 //Pino 10 recebe o pulso do echo
#define trigPin 9 //Pino 9 envia o pulso para gerar o echo
 
//iniciando a função e passando os pinos
Ultrasonic ultrasonic(9,10);
 
// 
int Motor_E1 = 8;
int Motor_E2 = 7;
int Motor_EV = 6;
int Motor_DV = 5;
int Motor_D2 = 4;
int Motor_D1 = 3;
int distancia;
 
int inPin = 2; //pino de entrada no sensor
int valor = 0; //Inteiro que armazena o valor lido no sensor
 
 
 
void setup()
{
 pinMode(echoPin, INPUT); // define o pino 10 como entrada (recebe)
 pinMode(trigPin, OUTPUT); // define o pino 9 como saida (envia)
 
 Serial.begin(9600); //inicializando a porta serial
 pinMode(inPin, INPUT); //colocando a porta 2 como entrada do sensor
 
 pinMode(Motor_E1, OUTPUT);
 pinMode(Motor_E2, OUTPUT);
 pinMode(Motor_EV, OUTPUT);
 pinMode(Motor_DV, OUTPUT);
 pinMode(Motor_D2, OUTPUT);
 pinMode(Motor_D1, OUTPUT);
 
 
}
 
void loop()
{
 
 
 
 //incicializando as potencias do motor  
 analogWrite(Motor_DV,51); 
 analogWrite(Motor_EV,51); 


valor = digitalRead(inPin);//realizando a leitura no sensor optico e armazenando na variavel valor
Serial.println(valor);//printando no serial se esta lendo preto ou branco
               
               //entra no if se o sensor estiver lendo branco
               if(valor == HIGH)
               {
 
                //o carro trava uma das rodas e vira pra esquerda
               
                digitalWrite(Motor_E1, HIGH);
                digitalWrite(Motor_E2, HIGH);
                digitalWrite(Motor_D1, LOW);
                digitalWrite(Motor_D2, HIGH); 
             
               
 
 
               //como ele nao entrou no if,o sensor esta lendo preto e ele entra no else
               }else{
         
 
                //o carro trava uma das rodas e vira pra direita
                digitalWrite(Motor_E1, LOW);
                digitalWrite(Motor_E2, HIGH);
                digitalWrite(Motor_D1, HIGH); 
                digitalWrite(Motor_D2, HIGH); 
 
               }
         
     
   
     
}
