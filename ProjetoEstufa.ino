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
                              Variáveis Globais                          */

int temperatura = 0, //Armazena a Temperatura em Inteiro
    umidadeAr = 0;   //Armazena a Umidade do Ar em Inteiro

/*=========================================================================
                            Configurações Iniciais                       */
void setup() {
  Serial.begin(9600);   //Serial em Baud Rate de 9600 bpm

}
/*=========================================================================
                                 Loop Infinito                           */
void loop() {
  
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
