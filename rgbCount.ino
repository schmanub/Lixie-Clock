#include <FastLED.h>

const uint8_t DIGITS = 1;
const uint8_t PIN = 7;
const uint8_t LED_COUNT = DIGITS * 20;

uint8_t gHue = 0;      // Start hue value
uint8_t gHueDelta = 1; // Increment for hue change

CRGB leds[LED_COUNT];  // Array to store the LED colors

void OutDigit(uint8_t digit, uint8_t value, CRGB color) {
  leds[(digit * 20) + (value * 2)] = color;       // 1st LED
  leds[(digit * 20) + (value * 2) + 1] = color;   // 2nd LED
}

void setup() {
  LEDS.addLeds<WS2812B,7, GRB>(leds, LED_COUNT);
}

void loop() {
  gHue += gHueDelta;
  FastLED.clear();  // Clear all LEDs

  CRGB color = CHSV(gHue, 255, 255);
  OutDigit(0, round(millis()/1000)%10, color);
  FastLED.show();
  
  delay(10);  // Wait for a short delay before updating again
}
