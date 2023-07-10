/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/Rich/CTD2023/Lab15/src/Lab15.ino"
#include "WatchDog_WCL.h"
#include "oled-wing-adafruit.h"
void setup();
void loop();
void resetDisplay();
#line 3 "c:/Users/Rich/CTD2023/Lab15/src/Lab15.ino"
#define READINGPIN D5

OledWingAdafruit display;

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

void setup()
{
  display.setup();
  if (System.resetReason() == RESET_REASON_WATCHDOG)
  {
    resetDisplay();
    display.println("Reset 4 Watchdog");
    display.display();
  }
  else
  {
    resetDisplay();
    display.println("Reset 4 other reason");
    display.display();
  }
  delay(2000);
  pinMode(READINGPIN, INPUT_PULLUP);
  Watchdog.init(WatchdogConfiguration().timeout(5s));
  Watchdog.start();
  Watchdog.refresh();
}
void loop()
{
  display.loop();
  if (digitalRead(READINGPIN))
  {
    resetDisplay();
    display.println("Petting");
    display.display();
    Watchdog.refresh();
  }
  else
  {
    resetDisplay();
    display.println("Not Petting");
    display.display();
  }
}
void resetDisplay()
{
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(WHITE);
}