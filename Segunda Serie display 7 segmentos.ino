//Define las variables
int segmentos[7] = {4, 5, 6, 7, 8, 9, 10};
int comun[2] = {11, 12};
int digits[16][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}, // 9
  {1, 1, 1, 0, 1, 1, 1}, // 10 - A
  {0, 0, 1, 1, 1, 1, 1}, // 11 - b
  {1, 0, 0, 1, 1, 1, 0}, // 12  - c
  {0, 1, 1, 1, 1, 0, 1}, // 13 - d
  {1, 0, 0, 1, 1, 1, 1}, // 14 - E
  {1, 0, 0, 0, 1, 1, 1}  // 15 - F
};

void setup() {
  //Segmentos
  for (int i = 0; i < 7; i++) {
    pinMode(segmentos[i], OUTPUT);
  }
  //Catodo Comun 
  for (int i = 0; i < 2; i++) {
    pinMode(comun[i], OUTPUT);
  }
  Serial.begin(9600);
}

void showNumber(int num) {
  //Mostrar los numeros Hexadecimales
  if (num >= 0 && num <= 15) {
    digitalWrite(comun[0], LOW);
    digitalWrite(comun[1], HIGH);
    for (int i = 0; i < 7; i++) {
      digitalWrite(segmentos[i], digits[num][i]);
    }
  } else {
    // MUESTRA EL 8
    for (int j = 0; j < 5; j++) { // INSTRUCCION PARA PARPADEAR 5 VECES
      digitalWrite(comun[0], LOW);
      digitalWrite(comun[1], HIGH);
      for (int i = 0; i < 7; i++) {
        digitalWrite(segmentos[i], digits[8][i]);
      }
      delay(500);
      digitalWrite(comun[0], LOW);
      digitalWrite(comun[1], LOW);
      for (int i = 0; i < 7; i++) {
        digitalWrite(segmentos[i], LOW);
      }
      delay(500);
    }
  }
}

void loop() {
  //Monitor Serial
  if (Serial.available() > 0) {
    int num = Serial.parseInt();
    showNumber(num);
    delay(4000);
  }
}