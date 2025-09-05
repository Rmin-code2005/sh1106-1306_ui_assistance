#include "oled_graphic_assistance.h"
Menu m1(0), m2(1);  //0: one icon_menu 1: two icon_menu
#define run_screen display.display()
#define clear_screen display.clearDisplay()
void setup() {
  init_graphic_assistance();
  m1.test(1000);  //timer set on : 1s
  m2.test(5000);  //timer set on: 5s

  m1.set_menu();
  m1.print(0, "menu1");  //icon index , icon's name
  run_screen;
  delay(500);
  m1.selector(0);  //select index 0 named 'menu1'
  run_screen;
  delay(100);

  clear_screen;
  m2.set_menu();
  m2.print(0, "menu1");  //icon index , icon's name
  m2.print(1, "menu2");  //icon index , icon's name
  run_screen;
  delay(500);
  m2.selector(0);  //select index 0 named 'menu1'
  delay(500);
  m2.selector(1);  //select index 1 named 'menu2'
  run_screen;
  delay(100);
  clear_screen;


  print_item(0, 352, "data");
  run_screen;
  delay(1000);
  clear_screen;
  run_screen;
}

void loop() {
}
