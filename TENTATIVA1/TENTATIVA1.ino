#include <Adafruit_NeoPixel.h>

#define LED_MATRIX_PIN 7  
#define LED_BRIGHTNESS 30  
#define MATRIX_SIZE 25      

#define BUZZER_PIN 10     
#define BUTTON_A 6        
#define BUTTON_B 5        
#define JOYSTICK_X A0     
#define JOYSTICK_Y A1     

Adafruit_NeoPixel matrix = Adafruit_NeoPixel(MATRIX_SIZE, LED_MATRIX_PIN, NEO_GRB + NEO_KHZ800);

bool gameRunning = true;
bool gameWon = false;
int score = 0;
int snakeX = 2, snakeY = 2;
int foodX, foodY;

const uint8_t heart[5][5] = {
  { 0, 1, 0, 1, 0 },
  { 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1 },
  { 0, 1, 1, 1, 0 },
  { 0, 0, 1, 0, 0 }
};

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);

  matrix.begin();
  matrix.setBrightness(LED_BRIGHTNESS);
  matrix.show(); 

  spawnFood();
}

void loop() {
  if (gameWon) {
    victoryAnimation();
    delay(2000);
    resetGame();
  } else {
    updateGame();
  }
}

void updateGame() {
  int joyX = analogRead(JOYSTICK_X);
  int joyY = analogRead(JOYSTICK_Y);
  int btnA = digitalRead(BUTTON_A);
  int btnB = digitalRead(BUTTON_B);

  if (joyX < 400 && snakeX > 0) snakeX--;
  if (joyX > 600 && snakeX < 4) snakeX++;
  if (joyY < 400 && snakeY > 0) snakeY--;
  if (joyY > 600 && snakeY < 4) snakeY++;

  matrix.clear();

  int foodIndex = foodY * 5 + foodX;
  matrix.setPixelColor(foodIndex, matrix.Color(255, 255, 255));

  int snakeIndex = snakeY * 5 + snakeX;
  matrix.setPixelColor(snakeIndex, matrix.Color(0, 255, 0));

  matrix.show();

  if (snakeX == foodX && snakeY == foodY && (btnA == LOW || btnB == LOW)) {
    score++;
    tone(BUZZER_PIN, 1000, 200);
    Serial.print("🍏 Comida pega! Score: ");
    Serial.println(score);
    spawnFood(); 

    if (score >= 5) {
      gameWon = true;
    }
  }

  delay(200);
}

void spawnFood() {
  foodX = random(0, 5);
  foodY = random(0, 5);
}

void victoryAnimation() {
  matrix.clear();

  for (int y = 0; y < 5; y++) {
    for (int x = 0; x < 5; x++) {
      int index = y * 5 + x;
      if (heart[y][x]) {
        matrix.setPixelColor(index, matrix.Color(255, 0, 0));
      }
    }
  }
  matrix.show();
  delay(1000);

  for (int i = 0; i < 3; i++) {
    matrix.clear();
    matrix.show();
    delay(300);

    for (int j = 0; j < MATRIX_SIZE; j++) {
      matrix.setPixelColor(j, matrix.Color(0, 0, 255));
    }
    matrix.show();
    delay(300);
  }

  victorySound();
}

void victorySound() {
  int melody[] = {1200, 1400, 1600, 1800, 2000};

  for (int i = 0; i < 5; i++) {
    tone(BUZZER_PIN, melody[i], 150);
    delay(200);
  }
}

void resetGame() {
  gameWon = false;
  score = 0;
  snakeX = 2;
  snakeY = 2;
  spawnFood();
  Serial.println("🔄 Jogo reiniciado!");
}
