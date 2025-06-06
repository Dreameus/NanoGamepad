#define JOY_X A0
#define JOY_Y A1

#define BUTTON_A 2
#define BUTTON_B 3
#define BUTTON_X 4
#define BUTTON_Y 5

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_X, INPUT_PULLUP);
  pinMode(BUTTON_Y, INPUT_PULLUP);
}

// Maps 0–1023 to 0–32767 for vJoy
int mapToVJoy(int value) {
  return map(value, 0, 1023, 0, 32767);
}

void loop() {
  int x = mapToVJoy(analogRead(JOY_X));
  int y = mapToVJoy(analogRead(JOY_Y));

  int bA = digitalRead(BUTTON_A) == LOW ? 1 : 0;
  int bB = digitalRead(BUTTON_B) == LOW ? 1 : 0;
  int bX = digitalRead(BUTTON_X) == LOW ? 1 : 0;
  int bY = digitalRead(BUTTON_Y) == LOW ? 1 : 0;

  // Send mapped values over Serial
  Serial.print(x); Serial.print(",");
  Serial.print(y); Serial.print(",");
  Serial.print(bA); Serial.print(",");
  Serial.print(bB); Serial.print(",");
  Serial.print(bX); Serial.print(",");
  Serial.println(bY);

  delay(10); // Adjust for performance
}
