#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pulsanti collegati ai pin digitali 2–10
const int buttonPins[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
bool buttonStates[9] = {false};
int lightPercent = 75;   // esempio percentuale luce
int hour = 14;           // ora
int minute = 5;          // minuti

// Etichette per i tasti (max 4 lettere)
const char* buttonLabels[9] = {
  "OBS", "CAM", "MIC",
  "SPOT", "CLIP", "CHAT",
  "MUTE", "REC", "EXIT"
};

const char* modeTitle = "D-DESK";

// Potenziometri su A0 e A1
#define POT_X A0
#define POT_Y A1

void setup() {
  for (int i = 0; i < 9; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP); // attivi LOW
  }

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

void loop() {
  // Leggi stato tasti
  for (int i = 0; i < 9; i++) {
    buttonStates[i] = digitalRead(buttonPins[i]) == LOW;
  }

  int potX = analogRead(POT_X);  // 0–1023
  int potY = analogRead(POT_Y);

  drawInterface(potX, potY);
  delay(50);
}

void drawInterface(int potX, int potY) {
  display.clearDisplay();

// === HEADER ===
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);

// Nome modalità a sinistra
display.setCursor(0, 0);
display.print(modeTitle);

// Percentuale luce (dopo nome modalità, con un gap fisso)


// Orario a destra (formattato HH:MM)
char timeStr[6]; // "HH:MM\0"
sprintf(timeStr, "%02d:%02d", hour, minute);
int timeStrLen = strlen(timeStr);
int posTimeX = SCREEN_WIDTH - (timeStrLen * 6); // 6 px per carattere
display.setCursor(posTimeX, 0);
display.print(timeStr);

  

  // === TASTI 3x3 ===
  int btnW = 32, btnH = 16;
  int spacingX = 2, spacingY = 2;
  int startX = 0, startY = 12;

  for (int i = 0; i < 9; i++) {
    int row = i / 3;
    int col = i % 3;
    int x = startX + col * (btnW + spacingX);
    int y = startY + row * (btnH + spacingY);

    if (buttonStates[i]) {
      // Invertito (riempito)
      display.fillRoundRect(x, y, btnW, btnH, 4, SSD1306_WHITE);
      display.setTextColor(SSD1306_BLACK); // testo nero su sfondo bianco
    } else {
      display.drawRoundRect(x, y, btnW, btnH, 4, SSD1306_WHITE);
      display.setTextColor(SSD1306_WHITE);
    }

    display.setCursor(x + 5, y + 4);
    display.setTextSize(1);
    display.print(buttonLabels[i]);
  }

  // === BARRE POTENZIOMETRI ===
drawRoundedBar(106, 10, 8, 54, potX, "");
drawRoundedBar(120, 10, 8, 54, potY, "");

  display.display();
}

void drawRoundedBar(int x, int y, int w, int h, int analogVal, const char* label) {
  // Bordo esterno
  display.drawRoundRect(x, y, w, h, 3, SSD1306_WHITE);

  // Riempimento proporzionale
  int barHeight = map(analogVal, 0, 1023, 0, h);
  display.fillRoundRect(x + 1, y + h - barHeight + 1, w - 2, barHeight - 2, 2, SSD1306_WHITE);

  // Etichetta (sotto)
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(x + 2, y + h + 1);
  display.print(label);
}
