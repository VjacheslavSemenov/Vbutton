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
```C++
bool isClick()
```
```C++
bool isHold()
```
```C++
bool isRelease()
```
```C++
void disable()
```
```C++
void enable()
```
```C++
void setDebounceTime(int time)
```
```C++
void setHoldTime(int time)
```
