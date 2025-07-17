struct Button {
  uint8_t pin;
  unsigned long lastDebounceTime = 0;
  int state = HIGH;
  int lastState = HIGH;
  Button(uint8_t p)
    : pin(p), lastDebounceTime(0), state(HIGH), lastState(HIGH) {}
};

Button* btnDown = nullptr;
Button* btnUp = nullptr;
Button* btnOk = nullptr;
Button* btnBack = nullptr;

void setupButtons() {
  btnDown = new Button(BTN_DOWN);
  btnUp   = new Button(BTN_UP);
  btnOk   = new Button(BTN_OK);
  btnBack = new Button(BTN_BACK);

  pinMode(btnDown->pin, INPUT_PULLUP);
  pinMode(btnUp->pin, INPUT_PULLUP);
  pinMode(btnOk->pin, INPUT_PULLUP);
  pinMode(btnBack->pin, INPUT_PULLUP);
}

bool ButtonPress(Button* btn, unsigned long debounceDelay = 25) {
  if (!btn) return false;
  int reading = digitalRead(btn->pin);
  if (reading != btn->lastState) {
    btn->lastDebounceTime = millis();
  }

  if ((millis() - btn->lastDebounceTime) > debounceDelay) {
    if (reading != btn->state) {
      btn->state = reading;
      if (btn->state == LOW) {
        btn->lastState = reading;
        return true;
      }
    }
  }

  btn->lastState = reading;
  return false;
}
