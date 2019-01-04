
int i = 0;
int letter[16];
int state[4];

void setup() {
  
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);  
}


void loop() {


//_________________________________________TECLEO______________________________________________________
  if (digitalRead(2) != state[0]){
    letter[i]=1;
    //Serial.print("A");
    state[0] = digitalRead(2);
    i++;
  }if (digitalRead(3) != state[1]){
    letter[i]=2;
    //Serial.print("B");
    state[1] = digitalRead(3);
    i++;
  }if (digitalRead(4) != state[2]){
    letter[i]=3;
    //Serial.print("C");
    state[2] = digitalRead(4);
    i++;
  }if (digitalRead(5) != state[3]){
    letter[i]=4;
    //Serial.print("D");
    state[3] = digitalRead(5);
    i++;
  }
  int j;
  //for (int j=0; j < 4; j++){
      //Serial.println(state[j]);
      //delay(10);
   //}


//________________________________________FIN DE LA LETRA__________________________________________
  if ((((state[0] == 0)&&(state[1] == 0))  && ((state[2] == 0)&&(state[3] == 0)))&& (i != 0)){
    //ESCRIBIR LETTER B4
    int j;
    for (j = 0; j < 16; j = j + 1) {
      Serial.print(letter[j]);
      //letter[j] = 0;
    }
    Serial.println();
    

    //ESCRIBIR LETTER DEC
    Serial.println(B42Dec(letter));
    
    
    

    //BORRAR LETTER
    for (j = 0; j < 16; j = j + 1) {
      //Serial.print(letter[j]);
      letter[j] = 0;
    }
    
    //OTROS
    i = 0;
  }
  delay(10);
 
}

//___________________________________________________________________________________________________


float B42Dec(int B4[]){
  int j;
  int h = 0;
  float Dec = 0;
  for(j = 15; j >= 0; j = j - 1) {
      if (B4[j] != 0){
        //Serial.println(j);
        //Serial.println((B4[j]-1)*pow(4, h));
        Dec = Dec + ((B4[j]-1)*pow(4, h));
        h++;
        B4[j] = 0;
      }
    }
    return Dec;
}
