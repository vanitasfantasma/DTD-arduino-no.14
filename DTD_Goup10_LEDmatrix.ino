#define ROW1 9
#define ROW2 8
#define ROW3 4
#define ROW4 A2
#define ROW5 3
#define ROW6 A0
#define ROW7 10
#define ROW8 6

#define COL1 A1
#define COL2 11
#define COL3 A3
#define COL4 12
#define COL5 5
#define COL6 A4
#define COL7 7
#define COL8 2

#define BUTTON 13
//shifty[16];
//const int row[] = {shifty[8], shifty[9], shifty[13], shifty[2], shifty[14], shifty[4], shifty[5], shifty[11]};
//const int col[] = {shifty[3], shifty[6], shifty[1], shifty[7], shifty[12], shifty[0], shifty[10], shifty[15]};

const int row[] = {ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8};
const int col[] = {COL1, COL2, COL3, COL4, COL5, COL6, COL7, COL8};

int imgnow = 0;
bool pressing = false;

int circle[8][8] = {{1, 1, 0, 0, 0, 0, 1, 1},
  {1, 0, 1, 1, 1, 1, 0, 1},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {1, 0, 1, 1, 1, 1, 0, 1},
  {1, 1, 0, 0, 0, 0, 1, 1}
};
int s[8][8] = {{1, 0, 0, 0, 0, 0, 0, 1},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 1}
};

void setup() {
  Serial.begin(9600);
  for (int i = 2; i < 13; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  pinMode(A0, OUTPUT);
  digitalWrite(A0, LOW);
  pinMode(A1, OUTPUT);
  digitalWrite(A1, LOW);
  pinMode(A2, OUTPUT);
  digitalWrite(A2, LOW);
  pinMode(A3, OUTPUT);
  digitalWrite(A3, LOW);
  pinMode(A4, OUTPUT);
  digitalWrite(A4, LOW);

  pinMode(13, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(13) == LOW && !pressing) {
    pressing = true;
    imgnow += 1;
    Serial.print(0);
    if (imgnow > 1) {
      imgnow = 0;
    }
  }
  else if (digitalRead(13) == HIGH && pressing) {
      pressing = false;
      Serial.print(1);
      }
  if (imgnow == 0) {
      lightup(circle);
    }
  if (imgnow == 1) {
      lightup(s);
    }

  }

void lightup(int matrix[8][8]) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(col[i], HIGH);
    for (int j = 0; j < 8; j++) {
      digitalWrite(row[j], matrix[j][i]);
    }
    for (int j = 0; j < 8; j++) {
      digitalWrite(row[j], HIGH);
      delay(1);
    }
    digitalWrite(col[i], LOW);


  }
}
