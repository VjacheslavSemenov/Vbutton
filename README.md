# Vbutton Library

Vbutton is an Arduino library for detecting button clicks, releases, and long presses.

## Installation

1. Download the latest release from the [releases page](https://github.com/your_username/Vbutton/releases).
2. Extract the ZIP file and rename the folder to "Vbutton".
3. Move the "Vbutton" folder to your Arduino libraries folder (usually located in `Documents/Arduino/libraries/`).

## Usage

To use the Vbutton library in your Arduino sketch, you need to include the library header file:

```C++
#include <Vbutton.h>
```
## Constructor
```C++
Vbutton(uint8_t pin,int debounceDelay,int holdTime);

```
1. pin: The pin to which the button is connected.
2. debounceDelay: The amount of time to debounce the button (in milliseconds).
3. holdTime: The amount of time to hold the button (in milliseconds).

## Methods
```C++
void getState()
```
Reads the current state of the button and updates the internal state of the library. This method should be called in your main loop.
```C++
bool isClick()
```
Returns true if the button was clicked and has not been clicked since the last time this method was calle
```C++
bool isHold()
```
Returns true if the button is currently being held down.
```C++
bool isRelease()
```
Returns true if the button was released and has not been released since the last time this method was called
```C++
void disable()
```
Disables the button.
```C++
void enable()
```
Enables the button.
```C++
void setDebounceTime(int time)
```
```C++
void setHoldTime(int time)
```

## Example
```C++
#include <Vbutton.h>

Vbutton button(2, 50, 500);

void setup() {
  Serial.begin(9600);
}

void loop() {
  button.getState();
  
  if (button.isClick()) {
    Serial.println("Button clicked!");
  }
  
  if (button.isHold()) {
    Serial.println("Button held down!");
  }
  
  if (button.isRelease()) {
    Serial.println("Button released!");
  }
}
```
