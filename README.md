# oled_graphic_assistance

A lightweight Arduino library for building and managing graphic menus on OLED displays. Designed to simplify the creation of icon-based interfaces, this library supports single and dual-icon menus, timed transitions, and dynamic data rendering.

## ✨ Features

- Single-icon and dual-icon menu modes
- Icon selection using index-based navigation
- Timed menu testing for UI responsiveness
- Custom text and data rendering on OLED
- Compatible with `Adafruit_SSD1306` and similar OLED libraries

## 📦 Installation

You can install this library manually by downloading it from GitHub and placing it in your Arduino `libraries` folder. Once published to the Arduino Library Manager, it will be available for direct installation.

## 🚀 Quick Start

```cpp
#include "oled_graphic_assistance.h"

Menu m1(0), m2(1);  // 0: single-icon menu, 1: dual-icon menu

#define run_screen display.display()
#define clear_screen display.clearDisplay()

void setup() {
  init_graphic_assistance();

  m1.test(1000);  // 1-second timer
  m2.test(5000);  // 5-second timer

  m1.set_menu();
  m1.print(0, "menu1");
  run_screen;
  delay(500);
  m1.selector(0);
  run_screen;
  delay(100);

  clear_screen;
  m2.set_menu();
  m2.print(0, "menu1");
  m2.print(1, "menu2");
  run_screen;
  delay(500);
  m2.selector(0);
  delay(500);
  m2.selector(1);
  run_screen;
  delay(100);
  clear_screen;

  print_item(0, 352, "data");
  run_screen;
  delay(1000);
  clear_screen;
  run_screen;
}

void loop() {}
