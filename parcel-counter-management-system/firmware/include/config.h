#ifndef CONFIG_H
#define CONFIG_H

#define N_LOCKERS 3
#define ACCESS_TIME_MS 300000UL   // 5 minutes

// --- Serial ports ---
#define NODEMCU_RX_PIN 4   // Arduino RX (to NodeMCU TX)
#define NODEMCU_TX_PIN 6   // Arduino TX (to NodeMCU RX)

// --- Relay pins controlling 3 solenoid locks ---
const int RELAY_PINS[N_LOCKERS] = {8, 9, 10};

// --- LED indicators and buzzer ---
#define LED_GREEN_PIN 44
#define LED_AMBER_PIN 43
#define LED_RED_PIN   45
#define BUZZER_PIN    42

// --- LCD 1602 wiring ---
#define LCD_RS 41
#define LCD_EN 40
#define LCD_D4 39
#define LCD_D5 38
#define LCD_D6 49
#define LCD_D7 48

// --- Keypad wiring ---
#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4
const byte KEYPAD_ROW_PINS[KEYPAD_ROWS] = {37, 36, 35, 34};
const byte KEYPAD_COL_PINS[KEYPAD_COLS] = {33, 32, 31, 28};

// --- Baud rates ---
#define SERIAL_BAUD 115200

