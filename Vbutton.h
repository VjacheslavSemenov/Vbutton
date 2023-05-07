#ifndef Vbutton_h
#define Vbutton_h
#include <Arduino.h>

class Vbutton {
public:
  Vbutton(uint8_t pin, int debounceDelay, int holdTime);
  void getState();
  bool isClick();
  bool isHold();
  bool isRelease();
  void setDebounceTime(int time);
  void setHoldTime(int time);
  void enable();
  void disable();
private:
  bool _clickStatus = true;
  bool _holdStatus = true;
  bool _releaseStatus = true;
  int _pin;
  int _state;
  int _lastState;
  bool _enable;
  bool _click;
  bool _hold;
  bool _release;
  unsigned long _lastPressTime;
  int _debounceDelay;
  int _holdTime;
  unsigned long _pressStartTime;
};
#endif
