
const int buttonPin = 12;  // the number of the pushbutton pin
const int ledPin = 13;    // the number of the LED pin
int buttonState = 0;  // variable for reading the pushbutton status
int num=0;
byte seq[10][8] = {{0,0,0,0,0,0,1},
                  {1,0,0,1,1,1,1},
                  {0,0,1,0,0,1,0},
                  {0,0,0,0,1,1,0},
                  {1,0,0,1,1,0,0},
                  {0,1,0,0,1,0,0},
                  {0,1,0,0,0,0,0},
                  {0,0,0,1,1,1,1},
                  {0,0,0,0,0,0,0},
                  {0,0,0,1,1,0,0}};
void setup() {
  int i;
  for(i=2;i<=9;i++){
    pinMode(i, OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}
void digitseq(byte digit){
  buttonState = digitalRead(buttonPin);
  byte eva = 0;
  byte i;
  for(i=2; i<=9; i++){
    digitalWrite(i,seq[digit][eva]);
    eva++;
  }
}
void loop() {
  buttonState = digitalRead(buttonPin);
  if(buttonState == LOW){
    num++;
    if(num>9){
      num = 0;
    }
    
  }
  if(buttonState == HIGH){
    num = 0;
  }
  digitseq(num);
  delay(500);
}


