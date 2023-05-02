#include <SoftwareSerial.h>
SoftwareSerial BtSerial(2,3);

char SW1, SW0, SW1_real, SW0_real = 0;
double C[5], Csharp[5], D[5], Dsharp[5], E[5], F[5], Fsharp[5], G[5], Gsharp[5], A[5], Asharp[5], B[5];
char a = 8, b = 9, c = 10, d = 11, e = 12, f = 13, g = A2, dot = A3;

void setup() {
  Serial.begin(9600);
  BtSerial.begin(9600);
  pinMode(A1, OUTPUT); //PIEZO
  pinMode(A2, OUTPUT); // g of the FND
  pinMode(A3, OUTPUT); // sharp
  pinMode(A4, INPUT); //target_freq toggle
  pinMode(A5, INPUT); //tuning toggle
  pinMode(4, OUTPUT);
  for (int f = 8; f <= 13; f++) 
    pinMode(f, OUTPUT);
  
  C[0] = 32.7032, Csharp[0] = 34.6478, D[0] = 36.7081, Dsharp[0] = 38.8909, E[0] = 41.2034, F[0] = 43.6535, 
  Fsharp[0] = 46.2493, G[0] = 48.9994, Gsharp[0] = 51.9130, A[0] = 55, Asharp[0] = 58.2705, B[0] = 61.7354;
  for (int f = 1; f <= 4; f++) {
    C[f] = 2 * C[f - 1]; Csharp[f] = 2 * Csharp[f - 1]; D[f] = 2 * D[f - 1]; Dsharp[f] = 2 * Dsharp[f - 1]; E[f] = 2 * E[f - 1]; F[f] = 2 * F[f - 1];
    Fsharp[f] = 2 * Fsharp[f - 1]; G[f] = 2 * G[f - 1]; Gsharp[f] = 2 * Gsharp[f - 1]; A[f] = 2 * A[f - 1]; Asharp[f] = 2 * Asharp[f - 1]; B[f] = 2 * B[f - 1];
  }
}

void FND_off(){
  for(int k=8; k<=13; k++) digitalWrite(k,HIGH); 
  digitalWrite(g,HIGH); digitalWrite(dot,HIGH); 
  }
void FND_on(){
  for(int k=8; k<=13; k++) digitalWrite(k,LOW); 
  digitalWrite(g,LOW); digitalWrite(dot,LOW); 
  }
void toLOW(char a)
  digitalWrite(a,LOW);

void toHIGH(char a)
  digitalWrite(a, HIGH);

void toC(){
  toLOW(a); toLOW(f); toLOW(e); toLOW(d);
}
void toD(){
  toLOW(b); toLOW(c); toLOW(d); toLOW(e); toLOW(g);
}
void toE(){
  toLOW(a); toLOW(f); toLOW(e); toLOW(d); toLOW(g);
}
void toF(){
  toLOW(a); toLOW(f); toLOW(e); toLOW(g);
}
void toG(){
  toLOW(a); toLOW(f); toLOW(e); toLOW(d); toLOW(c);
}
void toA(){
  toLOW(a); toLOW(b); toLOW(c); toLOW(e); toLOW(f); toLOW(g);
}
void toB(){
  toLOW(f); toLOW(e); toLOW(d); toLOW(c); toLOW(g);
}

double target_freq = 0;//For saving the frequency
String freq_name="";
void loop() {
  //---피에조에서 나는 소리와 7segments설정
  short VR = map(analogRead(A0),0,1023,33,555); //VR value to freqency range
  for (int k = 0; k <= 4; k++) { // Changing the harmonic to its base frequency with VR -= 65.4064 * (VR/65.406) will make this for loop unnecessary
    if (VR >= C[k] && VR < Csharp[k]) {
      target_freq = C[k]; 
      freq_name="C";
    }
    else if (VR >= Csharp[k] && VR < D[k]) {
      target_freq = Csharp[k]; 
      freq_name="Csharp";
    }
    else if (VR >= D[k] && VR < Dsharp[k]) {
      target_freq = D[k]; 
      freq_name="D";
    }
    else if (VR >= Dsharp[k] && VR < E[k]) {
      target_freq = Dsharp[k]; 
      freq_name="Dsharp";
    }
    else if (VR >= E[k] && VR < F[k]) {
      target_freq = E[k]; 
      freq_name="E";
    }
    else if (VR >= F[k] && VR < Fsharp[k]) {
      target_freq = F[k]; 
      freq_name="F";
    }
    else if (VR >= Fsharp[k] && VR < G[k]) {
      target_freq = Fsharp[k]; 
      freq_name="Fsharp";
    }
    else if (VR >= G[k] && VR < Gsharp[k]) {
      target_freq = G[k]; 
      freq_name="G";
    }
    else if (VR >= Gsharp[k] && VR < A[k]) {
      target_freq = Gsharp[k]; 
      freq_name="Gsharp";
    }
    else if (VR >= A[k] && VR < Asharp[k]) {
      target_freq = A[k]; 
      freq_name="A";
    }
    else if (VR >= Asharp[k] && VR < B[k]) {
      target_freq = Asharp[k]; 
      freq_name="Asharp";
    }
    else if (VR >= B[k]) {
      target_freq = B[k]; 
      freq_name="B";
    }
  }
  //---7segments on
  FND_off();
  if(freq_name=="C") toC();
  else if(freq_name=="Dsharp") {
    toD(); 
    toLOW(dot);
  }
  else if(freq_name=="D") 
    toD(); 
  else if(freq_name=="E") 
    toE();
  else if(freq_name=="Fsharp") {
    toF(); 
    toLOW(dot);
  }
  else if(freq_name=="F") 
    toF();
  else if(freq_name=="Gsharp") {
    toG(); toLOW(dot);
  }
  else if(freq_name=="G") 
    toG(); 
  else if(freq_name=="Asharp") {
    toA(); toLOW(dot);
  }
  else if(freq_name=="A") 
    toA(); 
  else if(freq_name=="Csharp") {
    toC(); toLOW(dot);
  } 
  else if(freq_name=="B") 
    toB();
//---Check the state of the switches
  if (SW1_real == 0 && digitalRead(A4) == HIGH) {
    SW1 = !SW1;
    SW1_real = 1;
  }
  if (SW1_real == 1 && digitalRead(A4) == LOW) 
    SW1_real = 0;
  
  if (SW0_real == 0 && digitalRead(A5) == HIGH) {
  SW0 = !SW0;
  SW0_real = 1;
  }
  if (SW0_real == 1 && digitalRead(A5) == LOW) 
    SW0_real = 0;
//---Control of the piezo buzzer with the switch
  if (SW1 == 1) 
    tone(A1, target_freq);
  else 
    noTone(A1);
//---Read the frequency through bluetooth communication
  short freq=0;
  char freq1[5];
  for(int i=0; i<=4; i++) freq1[i]=0;
  short k=0;
  while(BtSerial.available()) {
    freq1[k]=BtSerial.read();
    delay(5);
    k++;
    }
  freq=atoi(freq1);
    
  double gap = target_freq - freq;
  //if (gap>255) gap = 255;
  //else if(gap<255) gap = -255;
  
//---Adjusting the LED according to the measured frequency
  if (SW0 == 1&&SW1 == 0) { //The piezo and tuning mode can't work simultaneously
    digitalWrite(4, HIGH);
    if (freq > 9) {
      if (gap < -1) { // 측정된 주파수가 기준 주파수보다 크면 오른쪽 LED
        analogWrite(6, 0);
        analogWrite(5, 255);
      }
      else if (gap > 1) { // 측정된 주파수가 기준 주파수보다 작으면 왼쪽 LED
        analogWrite(5, 0);
        analogWrite(6, 255);
      }
      else { // 주파수가 맞으면 LED 둘다
        analogWrite(5, 255);
        analogWrite(6, 255);
      }
    }
  }
  else {
    analogWrite(5, 0);
    analogWrite(6, 0);
    digitalWrite(4, LOW);
  }
   Serial.print(target_freq); Serial.print(" "); Serial.print(freq); Serial.print(" "); Serial.println(gap);
  //Serial.println(freq);
  //Serial.println(target_freq); 
  //Serial.println(gap);
}
