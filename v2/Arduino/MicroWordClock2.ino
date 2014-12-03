// Libraries
#include <Wire.h>
#include "RTClib.h"
#include "pindefs.h"
#include "otherdefs.h"
#include "english.h"

// Customizable options
boolean blink_enable = true;
boolean blinknow = false;
#define FREQ_DISPLAY 1000 // Hz
#define FREQ_TIMEUPDATE 2 // Hz
//unsigned long check_interval = 500; // time update rate
//#define refresh_rate 2560 // display refresh rate in microseconds

volatile int cols[]={ // PC0,PD4,PB6!,PB3,PD5,PB4,PC2,PC3
  MTX_COL1,MTX_COL2,MTX_COL3,MTX_COL4,MTX_COL5,MTX_COL6,MTX_COL7,MTX_COL8}; // ON=LOW
volatile int rows[]={ // PB2,PC1,PD7,PB5,PD2,PD6,PD3,PB7!
  MTX_ROW1,MTX_ROW2,MTX_ROW3,MTX_ROW4,MTX_ROW5,MTX_ROW6,MTX_ROW7,MTX_ROW8}; // ON=HIGH

enum ClockMode {
  NORMAL,
  SET_MIN,
  SET_HRS,
  END,
};
ClockMode clockmode = NORMAL;

volatile char disp[8]={
  0B11111111,
  0B11111111,
  0B11111111,
  0B11111111,
  0B11111111,
  0B11111111,
  0B11111111,
  0B11111111,
};

char testdisp[8]={
  0B11111111,
  0B11111111,
  0B11111111,
  0B11111111,
  0B11111111,
  0B11111111,
  0B11111111,
  0B11111111,
};

// RTC stuff
RTC_DS1307 rtc;
unsigned long disp_sec;
unsigned long disp_min;
unsigned long disp_hrs;

volatile boolean updatenow = false;

boolean buttonState = LOW;
unsigned long buttonMillis = 0;
boolean buttonHandled = true;

void loop() {
  if(updatenow) {
    updateTime();
    prepareDisplay();
    updatenow = false;
  }

  if(digitalRead(PIN_BUTTON) != buttonState) {
    buttonState = digitalRead(PIN_BUTTON);
    if(buttonState == LOW) { // button was pressed  
      buttonMillis = millis();
      buttonHandled = false;
    } 
    else { // button was released
      buttonHandled = true;
      unsigned long buttonDelay = millis() - buttonMillis;
      if(buttonDelay > 100) { // debounce
        if(buttonDelay < 1000) { // simple press
          updatenow = true;
          switch(clockmode) {
          case NORMAL: 
            blink_enable = !blink_enable; 
            blinknow = true;
            TCNT1 = 0;
            break;
          case SET_MIN: 
            rtc.adjust(rtc.now().unixtime() + 1*60);
            blinknow = true;
            TCNT1 = 0;
            break;
          case SET_HRS: 
            rtc.adjust(rtc.now().unixtime() + 1*60*60);
            blinknow = true;
            TCNT1 = 0;
            break;
          }
        }
      }
    }
  } 
  else {
    if(buttonState == LOW && !buttonHandled) { // button is being pressed
      unsigned long buttonDelay = millis() - buttonMillis;
      if(buttonDelay > 2000) {
        blinknow = false;
        TCNT1 = 0;
        clockmode = (ClockMode)((int)clockmode + 1);
        if(clockmode == END)
          clockmode = NORMAL;
        buttonHandled = true;
        updatenow = true;
      }
    }
  }
}

void updateTime() {
  // Adjust 2.5 minutes = 150 seconds forward
  // So at 12:03 it already reads "five past 12"
  DateTime now = rtc.now().unixtime() + 150;

  disp_sec = now.second();
  disp_min = now.minute();
  disp_hrs = now.hour();

  disp_min /= 5;

  if(disp_min >= min_offset) 
    ++disp_hrs %= 12;
  else
    disp_hrs   %= 12;
}

void prepareDisplay() {
  blinknow = !blinknow;
  FOR_ALLROWS {
    disp[r]=B00000000;
    FOR_ALLCOLS {
      if((clockmode != SET_MIN || !blinknow))
        disp[r] |= minutes[disp_min][r] & (B10000000 >> c);
      if((clockmode != SET_HRS || !blinknow))
        disp[r] |= hours  [disp_hrs][r] & (B10000000 >> c);
      if(clockmode == NORMAL && blink_enable && !blinknow)
        disp[r] |= blinky[r];
    }
  }
}


