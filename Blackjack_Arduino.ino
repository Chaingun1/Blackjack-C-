#include<Adafruit_CircuitPlayground.h>
volatile bool leftbuttonflag;
volatile bool rightbuttonflag;
int rightbuttonpin = 4;
int leftbuttonpin = 5;
volatile int playerCount = 0;
volatile int dealerCount = 0;
volatile int score = 5;

int cardlist[] = {1,2,3,4,5,6,7,8,9,10,11};


void setup() {
  pinMode(rightbuttonpin, INPUT_PULLDOWN);
  pinMode(leftbuttonpin, INPUT_PULLDOWN);
  Serial.begin(9600);
  while(!Serial);
  CircuitPlayground.begin();
  attachInterrupt(digitalPinToInterrupt(rightbuttonpin), hit, RISING);
  attachInterrupt(digitalPinToInterrupt(leftbuttonpin), stand, RISING);
  randomSeed(analogRead(0));

}

void loop() {
  for (int i = 0; i < score; i++)
  {
    CircuitPlayground.setPixelColor(i,255,0,255);
  }
  Serial.println ("game start");
  int rand = random(sizeof(cardlist)/sizeof(int));
  dealerCount = (dealerCount + cardlist[rand]);
  playerCount = (playerCount + cardlist[rand]);

  delay (5000);
  while (playerCount <21){
    Serial.print("dealer's count is:");
    Serial.println(dealerCount);
    Serial.print("player count is:");
    Serial.println(playerCount);
    Serial.println("would you like to hit(R) or stand(L)?");
    delay(5000);
    if(rightbuttonflag){ 
      playerCount = (playerCount + cardlist[rand]);
      rightbuttonflag = 0;
    }
    if(leftbuttonflag){
      leftbuttonflag = 0;
      break;
    }
  }
    
    Serial.println("time to compare scores!");
    delay(2000);
    if (playerCount > 21){
      score = score - 1;
      Serial.println("player busted!");
    }
    else if(playerCount < dealerCount){
      score = score - 1;
      Serial.println("player lost");
    }
    else if(playerCount > dealerCount){
      score++;
      Serial.println("player won this round");
    }
    while(score == 10){
      Serial.println("Player won the game!");
      rainbowpattern(100,10);
    }
    while(score == 0){
      Serial.println("player lost the game!");
      starlight();

    }
    playerCount = 0;
    dealerCount= 0;
}
void hit(){
  rightbuttonflag = 1;
}
void stand(){
  leftbuttonflag = 1;
}



void rainbowpattern (int currentSpeed, int stripLen){
  uint32_t offset = millis() / currentSpeed;
  for(int i=0;i<10; ++i){
    CircuitPlayground.setPixelColor(i, CircuitPlayground.colorWheel(((i * 256/stripLen)+offset )&255));
  }
}



void starlight(){
  for (int i=0; i<9; ++i){
  int pix = random(0,10);
  CircuitPlayground.setPixelColor(pix,255,0,0);
  delay(100);
  }
}