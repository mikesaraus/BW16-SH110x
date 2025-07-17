// Headers Title
#define BW_TITLE "BW16-SH110x"

// Wifi Settings
#define WIFI_SSID "PLDTHOMEFIBR0x3a"
#define WIFI_PASS "abcd@1234";

// Display Settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 128
#define OLED_RESET -1

// Buttons Settings
#define BTN_DOWN PA27
#define BTN_UP PA12
#define BTN_OK PA13
#define BTN_BACK PB3

const char* BW_TITLE_STR = BW_TITLE;

#undef max
#undef min
#include "Display.h"

void logo_animate(){
  for(int i=0; i< Logo_gif_allArray_LEN; i++){
    display.drawBitmap(0,(SCREEN_HEIGHT-logo_height)/2,Logo_gif_allArray[i],SCREEN_HEIGHT,logo_height,SH110X_WHITE);
    display.display();
    delay(45);
  }
}

void bw16_set_up(){
  if (has_display) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SH110X_WHITE, SH110X_BLACK);
    
    logo_animate();
    delay(1500);
    setupButtons();

    main_names = {"Attack", "Scan", "Select","Settings"};
    at_names = {"Deauth", "All Deauth","Beacon","Authentication","Association"};
    Serial.println("Setup with display");
  } else {
    Serial.println("Setup without display");
    draw_menu(main_names, 0);
  }
}
