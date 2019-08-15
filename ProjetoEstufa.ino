/*=========================================================================

                        PROJETO ESTUFA CONTROLADA
                        Autor: Leandro Pradal Lopes
                        Engenharia de Controle e Automação
                        Data: Agosto de 2019

                        Lista de Sensores:
                        DHT

=========================================================================*/

/*=========================================================================
                           Bibliotecas Adicionais                        */

#include <dht.h>       //Lib. Sensor de Umidade e Temperatura DHT11

/*=========================================================================
                            Mapeamento de Hardware                       */

#define dht_pin 5      //Pino do Sinal do DHT11 ligado no digital 5

/*=========================================================================
                            Declaração de Objetos                        */

dht DHT;              //Objeto para o Sensor

/*=========================================================================
                             Constantes Globais                          */

#define n 10           //Número de componentes da Média Móvel

/*=========================================================================
                              Variáveis Globais                          */

int temperatura = 0, //Armazena a Temperatura em Inteiro
    umidadeAr = 0;   //Armazena a Umidade do Ar em Inteiro
int numbers[n];      //Vetor com os valores para a Média Móvel


/*=========================================================================
                            Configurações Iniciais                       */
void setup() {
  Serial.begin(9600);   //Serial em Baud Rate de 9600 bpm

}
/*=========================================================================
                                 Loop Infinito                           */
void loop() {
  lerUmidTemp();
  temperatura = movingAverage(temperatura);
  umidadeAr = movingAverage(umidadeAr);
  delay(50);
}
/*=========================================================================
                               Métodos Adicionais                        */
                               
void aquecer(){
  //instruções
}

void ventilar(){
  //instruções
}

void irrigar(){
  //instruções
}

void iluminar(){
  //instruções
}

void lerUmidTemp(){
  DHT.read11(dht_pin);
  temperatura = DHT.temperature;
  umidadeAr = DHT.humidity;
}

long movingAverage(int variavelLida){
  for(int i = n-1; i > 0; i--) numbers[i] = numbers[i - 1];
  numbers[0] = variavelLida;
  long acc = 0;
  for(int i = 0; i < n; i++) acc += numbers[i];
  return acc/n;
}
