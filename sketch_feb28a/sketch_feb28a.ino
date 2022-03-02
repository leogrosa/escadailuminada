
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pin_trigger 4
#define pin_echo 5
#define d1 6
#define d2 9
#define d3 10
#define d4 3
 
Ultrasonic ultrasonic(pin_trigger, pin_echo);
 
void setup()
{
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


int andar_atual, andar_anterior;



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
  delay(10);
  if(iteracao%tam_janela == 0)
  { 
    distCM = acumulador/tam_janela; //realiza a media
    acumulador = 0;  
  }
 

  Serial.print("\n");
  Serial.print(leitura_inst);

  andar_anterior = andar_atual;
  
  //Discrimina o andar em que o objeto/pessoa está
  if(distCM > 34 && distCM <= 41)
  {
    andar_atual = d1;
  }
  else if(distCM > 25 && distCM <= 34)
  {
    andar_atual = d2;
  }else if(distCM > 17 && distCM <= 25)
  {
    andar_atual = d3;
  }
  else if(distCM >= 0 && distCM <= 17)
  {
    andar_atual = d4;
  }
  else
  {
    andar_atual = 0;
  }
  
  if(andar_anterior != andar_atual)
  {
   for(i=0;i<=255;i++)
   {
    analogWrite(andar_atual,i);
    analogWrite(andar_anterior,-i+255);
    delay(3);
   } 
  }
  iteracao++;
}
