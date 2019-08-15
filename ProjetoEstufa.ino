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
#define humSolo analogRead(A0) //Sinal do Sensor LM393 ligado no A0

/*=========================================================================
                            Declaração de Objetos                        */

dht DHT;              //Objeto para o Sensor

/*=========================================================================
                             Constantes Globais                          */

#define n 10           //Número de componentes da Média Móvel

/*=========================================================================
                              Variáveis Globais                          */

int temperatura = 0,    //Armazena a Temperatura em Inteiro
    umidadeAr = 0,      //Armazena a Umidade do Ar em Inteiro
    umidadeSolo = 0;    //Armazena a Umidade do Solo em Inteiro
int temperaturas[n],    //Vetor com os valores para a Média Móvel
    umidadesAr[n],      //Vetor com os valores para a Média Móvel
    umidadesSolo[n];    //Vetor com os valores para a Média Móvel


/*=========================================================================
                            Configurações Iniciais                       */
void setup() {
  Serial.begin(9600);   //Serial em Baud Rate de 9600 bpm

}
/*=========================================================================
                                 Loop Infinito                           */
void loop() {
  lerUmidTemp();
  lerUmidSolo();
  movingAverage();
  displaySerial();
  delay(15);
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

void lerUmidSolo(){
  umidadeSolo = map(humSolo, 0, 1023, 0, 100);
}

void displaySerial(){
  Serial.print(temperatura);
  Serial.print(" C \t");
  Serial.print(umidadeAr);
  Serial.print(" % \t");
  Serial.print(umidadeSolo);
  Serial.println(" %");
}

void movingAverage(){
  long accT = 0;
  long accUA = 0;
  long accUS = 0;
  for(int i = n-1; i > 0; i--){
    temperaturas[i] = temperaturas[i - 1];
    umidadesAr[i] = umidadesAr[i - 1];
    umidadesSolo[i] = umidadesSolo[i - 1];
  }
  
  temperaturas[0] = temperatura;
  umidadesAr[0] = umidadeAr;
  umidadesSolo[0] = umidadeSolo;
  
  for(int i = 0; i < n; i++){
    accT += temperaturas[i];
    accUA += umidadesAr[i];
    accUS += umidadesSolo[i];
  }
  
  temperatura = accT/n;
  umidadeAr = accUA/n;
  umidadeSolo = accUS/n;
}
