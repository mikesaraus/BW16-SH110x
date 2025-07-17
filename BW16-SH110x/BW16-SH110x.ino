#include "Settings.h"

extern "C" void wifi_enter_critical() {}
extern "C" void wifi_exit_critical() {}

void setup(){
  Serial.begin(115200);
  if(display.begin(0x3C, true)) {
    has_display = true;
    Serial.println(F("SH1107 display initialized"));
    display_init();
  } else {
    Serial.println(F("SH1107 allocation failed"));
    has_display = false;
  }

  web_setup();
  bw16_set_up();
}

void loop(){
  display_update();
}
