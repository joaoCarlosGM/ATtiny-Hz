/******************************************************************************
  Programa para converter um sinal de frequencia para um sinal de Duty clycle 
                              usando ATtiny45/85

                            Por João Carlos G. Moraes

                            Belém-Pa, Fevereiro de 2024

                         https://www.sinopeoficial.com.br


                         value =  cont;
    value = map(value,0,100,0,255);
    analogWrite(OUT,value);

    
    // escrever na saida analogica : analogWrite(OUT,value);
******************************************************************************/


volatile unsigned long cont = 0;
unsigned long tempo = 0;

int value; // value varia de 0-255

#define OUT 3


void setup() {
  Serial.begin(9600);
  pinMode(0, INPUT);
  attachInterrupt(0, interrupcao, RISING);
}

void loop() {

  if( (millis() - tempo) > 999){
    tempo = millis();
    Serial.println(cont);
    cont = 0;
  }
}

void interrupcao(){
  cont++;
}
