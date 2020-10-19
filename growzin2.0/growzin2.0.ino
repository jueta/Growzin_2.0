
    const unsigned long SECOND = 1000;
    const unsigned long HOUR = 3600*SECOND;

  //contadores para marcar a semana no display
  byte contador = 0; 

  //VARIAVEIS
  int rele = A5;
  int buzzer = 10;
  int led_veg = 12; // --> Led VERDE == vegetacao
  int led_flo = 9;  // --> Led VERMELHO == floracao
  int fase = A0;
  int segA = 2;
  int segB = 3;
  int segC = 6;
  int segD = 7;
  int segE = 8;
  int segF = 1;
  int segG = 0;

//SETUP
void setup(){
    
    pinMode(segA, OUTPUT); //IO 2 -> SEGMENTO A  
    pinMode(segB, OUTPUT); //IO 3 -> SEGMENTO B
    pinMode(segC, OUTPUT); //IO 6 -> SEGMENTO C
    pinMode(segD, OUTPUT); //IO 7 -> SEGMENTO D
    pinMode(segE, OUTPUT); //IO 8 -> SEGMENTO E
    pinMode(segF, OUTPUT); //IO 1 -> SEGMENTO F
    pinMode(segG, OUTPUT); //IO 0 -> SEGMENTO G
    pinMode(5, OUTPUT); //PINO 5 -> SEGMENTO pt
    
    pinMode(fase, INPUT);
    pinMode(rele, OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(led_veg, OUTPUT);
    pinMode(led_flo, OUTPUT);
}



 //FUNÇÃO QUE ACIONA O DISPLAY
void ligaSegmentosDisplay(byte digit){
    switch (digit) {
      case 0:
        digitalWrite(segA, LOW);
        digitalWrite(segB, LOW);
        digitalWrite(segC, LOW);
        digitalWrite(segD, LOW);
        digitalWrite(segE, LOW);
        digitalWrite(segF, LOW);
        digitalWrite(segG, HIGH);
        break;
      case 1:
        digitalWrite(segA, HIGH);
        digitalWrite(segB, LOW);
        digitalWrite(segC, LOW);
        digitalWrite(segD, HIGH);
        digitalWrite(segE, HIGH);
        digitalWrite(segF, HIGH);
        digitalWrite(segG, HIGH);
        break;
      case 2:
        digitalWrite(segA, LOW);
        digitalWrite(segB, LOW);
        digitalWrite(segC, HIGH);
        digitalWrite(segD, LOW);
        digitalWrite(segE, LOW);
        digitalWrite(segF, HIGH);
        digitalWrite(segG, LOW);
        break;
      case 3:
        digitalWrite(segA, LOW);
        digitalWrite(segB, LOW);
        digitalWrite(segC, LOW);
        digitalWrite(segD, LOW);
        digitalWrite(segE, HIGH);
        digitalWrite(segF, HIGH);
        digitalWrite(segG, LOW);
        break;
      case 4:
        digitalWrite(segA, HIGH);
        digitalWrite(segB, LOW);
        digitalWrite(segC, LOW);
        digitalWrite(segD, HIGH);
        digitalWrite(segE, HIGH);
        digitalWrite(segF, LOW);
        digitalWrite(segG, LOW);
        break;
      case 5:
        digitalWrite(segA, LOW);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, LOW);
        digitalWrite(segD, LOW);
        digitalWrite(segE, HIGH);
        digitalWrite(segF, LOW);
        digitalWrite(segG, LOW);
        break;
      case 6:
        digitalWrite(segA, LOW);
        digitalWrite(segB, HIGH);
        digitalWrite(segC, LOW);
        digitalWrite(segD, LOW);
        digitalWrite(segE, LOW);
        digitalWrite(segF, LOW);
        digitalWrite(segG, LOW);
        break;
      case 7:
        digitalWrite(segA, LOW);
        digitalWrite(segB, LOW);
        digitalWrite(segC, LOW);
        digitalWrite(segD, HIGH);
        digitalWrite(segE, HIGH);
        digitalWrite(segF, HIGH);
        digitalWrite(segG, HIGH);
        break;
      case 8:
        digitalWrite(segA, LOW);
        digitalWrite(segB, LOW);
        digitalWrite(segC, LOW);
        digitalWrite(segD, LOW);
        digitalWrite(segE, LOW);
        digitalWrite(segF, LOW);
        digitalWrite(segG, LOW);
        break;
      case 9:
        digitalWrite(segA, LOW);
        digitalWrite(segB, LOW);
        digitalWrite(segC, LOW);
        digitalWrite(segD, HIGH);
        digitalWrite(segE, HIGH);
        digitalWrite(segF, LOW);
        digitalWrite(segG, LOW);
        break;
        
      delay(100);
  }
}


void vegetacao(){
    digitalWrite(rele, HIGH);
    delay(18*HOUR);
    digitalWrite(rele, LOW);
    delay(6*HOUR);
}

void floracao(){
    digitalWrite(rele, HIGH);
    delay(12*HOUR);
    digitalWrite(rele, LOW);
    delay(12*HOUR);
}


//Logica para calcular as semanas
void contagem(){
      contador++;  
    if(contador == 10){contador =1;}
    ligaSegmentosDisplay(contador);
}

  
void loop() {

    //fase da vegetacao
    if(digitalRead(fase) == HIGH){
      contagem();
      digitalWrite(led_veg, HIGH);
      digitalWrite(led_flo, LOW);
      vegetacao();
    }

    //fase da floracao
    if(digitalRead(fase) == LOW){
      contagem();
      digitalWrite(led_flo, HIGH);
      digitalWrite(led_veg, LOW);
      floracao();
    }


}
