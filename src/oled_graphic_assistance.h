#ifndef oled_graphic_assistance_H
#define oled_graphic_assistance_H
#include "Adafruit_GFX.h"
#include "Adafruit_SH1106.h"
#include <Wire.h>
extern Adafruit_SH1106 display;
void init_graphic_assistance();
void print_item(uint8_t line , int data , char* str);
class Menu {
private:
    bool two_icon;
public:

    Menu(bool ti)
      :two_icon(ti){}

  void test(int timer);
  void set_menu();
  void print(uint8_t icon , char* str);
  void selector(uint8_t icon);

};
#endif
