#include "Vbutton.h"

Vbutton::Vbutton(uint8_t pin, int debounceDelay,int holdTime)
  : _pin(pin),
    _debounceDelay(debounceDelay),
    _lastPressTime(0),
    _holdTime(holdTime),
    _state(false),
    _lastState(false),
    _enable(true) {
  if (_pin <= 7) {
    DDRD &= ~(1 << _pin);
  } else if (pin >= 8 && _pin <= 13) {
    DDRB &= ~(1 << (_pin - 8));
  } else if (_pin >= 14 && _pin <= 19) {
    DDRC &= ~(1 << (_pin - 14));
  }
}

void Vbutton::getState() {
  if (_enable) {
    if (_pin <= 7) {
      _state = PIND & (1 << _pin);
    } else if (_pin >= 8 && _pin <= 13) {
      _state = PINB & (1 << (_pin - 8));
    } else if (_pin >= 14 && _pin <= 19) {
      _state = PINC & (1 << (_pin - 14));
    }

    if (_state && !_lastState) {
      _lastState = !_lastState;
      _lastPressTime = millis();
    }

    if (millis() - _lastPressTime > _debounceDelay) {
      _click = _state;
    }

    if (millis() - _lastPressTime > _holdTime) {
      _hold = _state;
    }

    if (!_state && _lastState && millis() - _lastPressTime > _debounceDelay) {
      _lastState = !_lastState;
      _release = true;
      _hold = _state;
      _click = _state;
      _releaseStatus = true;
      _holdStatus = true;
      _clickStatus = true;

      _lastPressTime = millis();
    }

    if (!_state && !_lastState && millis() - _lastPressTime > 100) {
      _release = false;
    }
  }
}
bool Vbutton::isClick() {
  if (_click && _clickStatus) {
    _clickStatus = false;
    return true;
  } else {
    return false;
  }
}

bool Vbutton::isRelease() {
  if (_release && _releaseStatus) {
    _releaseStatus = false;
    return true;
  } else {
    return false;
  }
}
bool Vbutton::isHold() {
  if (_hold && _holdStatus) {
    _holdStatus = false;
    return true;
  } else {
    return false;
  }
}
void Vbutton::disable() {
  _enable = false;
}
void Vbutton::enable() {
  _enable = true;
}
void Vbutton::setDebounceTime(int time){
  _debounceDelay = time;
}
  void Vbutton::setHoldTime(int time){
    _holdTime=time;
  }