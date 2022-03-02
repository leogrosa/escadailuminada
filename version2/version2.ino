
#include <Ultrasonic.h>
#include "degrau.h"

//Define os pinos para o trigger e echo
#define pin_trigger 4
#define pin_echo 5
#define d1 6
#define d2 9
#define d3 10
#define d4 3
 
Ultrasonic ultrasonic(pin_trigger, pin_echo);
degrau *deg1 = new degrau(), *deg2 = new degrau(), *deg3 = new degrau(), *deg4 = new degrau();
 
void setup()
{
  deg1->setPino(d1);
  deg2->setPino(d2);
  deg3->setPino(d3);
  deg4->setPino(d4);

  deg1->setPos(34,41);
  deg2->setPos(25,34);
  deg3->setPos(17,25);
  deg4->setPos(0,17);

  pinMode(d1,OUTPUT);
  pinMode(d2,OUTPUT);
  pinMode(d3,OUTPUT);
  pinMode(d4,OUTPUT);

  Serial.begin(9600);
  Serial.println("Obtendo leituras");

  //Apaga todos os degraus
  digitalWrite(d1,0);
  digitalWrite(d2,0);
  digitalWrite(d3,0);
  digitalWrite(d4,0);
}

//Cria as variaveis para realizar as leituras e a filtragem
float distCM, leitura_inst, acumulador = 0;

//Variaveis de controle e do tamanho da janela do filtro
int i, tam_janela = 25, iteracao = 0;
//int freq_aquisicao = 100;

void loop()
{
  long microsec = ultrasonic.timing();

  /*
  for(i=0;i<tam_janela;i++)
  {
      leitura_inst = ultrasonic.convert(microsec, Ultrasonic::CM);
      acumulador += leitura_inst;
      delay(freq_aquisicao/tam_janela);
  }
  */
  
  leitura_inst = ultrasonic.convert(microsec, Ultrasonic::CM);
  acumulador += leitura_inst;
  delay(3);
  if(iteracao%tam_janela == 0)
  { 
    distCM = acumulador/tam_janela; //realiza a media
    acumulador = 0;  
  }
 

  Serial.print("\n");
  Serial.print(distCM);

  deg1->update(distCM);
  deg2->update(distCM);
  deg3->update(distCM);
  deg4->update(distCM);

  analogWrite(deg1->getPino(),deg1->getBrilho());
  analogWrite(deg2->getPino(),deg2->getBrilho());
  analogWrite(deg3->getPino(),deg3->getBrilho());
  analogWrite(deg4->getPino(),deg4->getBrilho());
  
  iteracao++;
}
