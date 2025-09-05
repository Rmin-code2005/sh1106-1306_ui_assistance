#include "oled_graphic_assistance.h"
graphic graphic_assistance(-1, 2, 3);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  graphic_assistance.init();
  //write an if here , to selection_setup :
  menues main_menues;
  main_menues.hash_names = "1- vls menue#2-apds #3- led_on#4- led_off#5- motor_test";
  main_menues.menues_packager();
  Serial.println(main_menues.len);
  int sub_menu;
  do {
    sub_menu = graphic_assistance.display_menues(main_menues);
    if (sub_menu == 0) {
      int sensor_valls[] = { 10, 20, 30 };
      String names[] = { "right", "left", "front" };
      for (int i = 0; i < 10; i++) {
        sensor_valls[0] += i;
        sensor_valls[1] += i;
        sensor_valls[2] += i;
        graphic_assistance.live_frame(sensor_valls, names);
        delay(100);
      }
    } else if (sub_menu == 1) {
      char sensor_valls[] = { 'r', 'g', 'b' };
      String names[] = { "APDS" };
      graphic_assistance.live_frame(sensor_valls, names, 1);
      delay(100);
      sensor_valls[0] = 'g';
      sensor_valls[1] = 'g';
      sensor_valls[2] = 'g';
      graphic_assistance.live_frame(sensor_valls, names, 1);
      delay(100);
    } else if (sub_menu == 2) {  //3
      digitalWrite(LED_BUILTIN, 1);
    } else if (sub_menu == 3) {
      digitalWrite(LED_BUILTIN, 0);
    } else if (sub_menu == 4) {
      for(int i=-200 ; i <200 ; i=i+20){
        Serial.print("motors speed: ");
        Serial.println(i);
        delay(100);
      }
    }
  } while (sub_menu != 5);
  // int valls[] = {10,20,30,40};
  // String names[]={"sens1"};
  // for (int i=0 ; i<10 ; i++){
  //   valls[0]+=i;
  //   valls[1]+=i;
  //   ga.live_frame(valls, names , 1);
  //   delay(100);
  // }
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
