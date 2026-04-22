#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define BTN_REMOVE 2
#define BTN_BUDGET 3
#define BTN_FINAL 4

#define LED_ADD 5
#define LED_REMOVE 6
#define LED_FINAL 7

#define BUZZER 8

int totalAmount = 0;
int itemPrice = 50;

void setup() {
  Serial.begin(9600);
  Serial.println("System Start");

  SPI.begin();
  rfid.PCD_Init();

  pinMode(BTN_REMOVE, INPUT);
  pinMode(BTN_BUDGET, INPUT);
  pinMode(BTN_FINAL, INPUT);

  pinMode(LED_ADD, OUTPUT);
  pinMode(LED_REMOVE, OUTPUT);
  pinMode(LED_FINAL, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0,0);
  display.println("Smart Cart Ready");
  display.display();
}

void loop() {

  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    Serial.println("Card Detected");

    totalAmount += itemPrice;

    digitalWrite(LED_ADD, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(300);
    digitalWrite(LED_ADD, LOW);
    digitalWrite(BUZZER, LOW);

    Serial.print("Total = ");
    Serial.println(totalAmount);

    display.clearDisplay();
    display.setCursor(0,0);
    display.println("Item Added");
    display.print("Total: ");
    display.println(totalAmount);
    display.display();

    rfid.PICC_HaltA();
  }

  if (digitalRead(BTN_REMOVE) == HIGH) {
    Serial.println("Remove Pressed");

    totalAmount -= itemPrice;
    if (totalAmount < 0) totalAmount = 0;

    digitalWrite(LED_REMOVE, HIGH);
    delay(300);
    digitalWrite(LED_REMOVE, LOW);

    display.clearDisplay();
    display.setCursor(0,0);
    display.println("Item Removed");
    display.print("Total: ");
    display.println(totalAmount);
    display.display();
  }

  if (digitalRead(BTN_BUDGET) == HIGH) {
    Serial.println("Budget Pressed");

    display.clearDisplay();
    display.setCursor(0,0);
    display.println("Total");
    display.print("Rs: ");
    display.println(totalAmount);
    display.display();

    delay(300);
  }

  if (digitalRead(BTN_FINAL) == HIGH) {
    Serial.println("Final Bill");

    digitalWrite(LED_FINAL, HIGH);

    display.clearDisplay();
    display.setCursor(0,0);
    display.println("Final Bill");
    display.print("Rs: ");
    display.println(totalAmount);
    display.display();

    delay(2000);
    digitalWrite(LED_FINAL, LOW);
  }
}