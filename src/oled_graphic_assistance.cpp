#include "oled_graphic_assistance.h"
Adafruit_SH1106 display(-1);
void init_graphic_assistance(){

    #if (SH1106_LCDHEIGHT != 64)
    #error("Height incorrect, please fix Adafruit_SH1106.h!");
    #endif
    Wire.begin();
    display.begin(SH1106_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
    display.display();
    delay(50);
    display.clearDisplay();
    display.display();
}
void print_item(uint8_t line , int data , char* str){
    display.setCursor(0, line*9);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print(str);
    display.print(" : ");
    display.print(data);
}
void Menu::test(int timer){
    //display.begin(SH1106_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
    display.clearDisplay();
    display.drawPixel(10, 10, WHITE);
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.setTextSize(1);
    display.println("Produced by : Armin ");
    display.println("             ghajari ");
    display.println("Hello, world!");
    display.println();
    display.println("Founder company: ");
    display.setTextSize(1);
    display.println();
    display.print  ("   Mositto ");
    display.display();
    delay(timer);
    display.clearDisplay();
    display.display();
}
void Menu::set_menu(){
    if(two_icon==0) display.drawRect(1,1,127,63,WHITE);

    else{
        display.drawRect(1,1,63,63,WHITE);
        display.drawRect(65,1,63,63,WHITE);
    }
}
void Menu::print(uint8_t icon, char* str){
    int len=0 , i=0;
    while(str[i]!='\0'){
        len++;
        i++;
    }
    if(two_icon==0){
        display.setCursor(64-((len*5)/2), 32);
        display.setTextColor(WHITE);
        display.print(str);
        }
    else{
        display.setCursor(32+((icon==1)*62)-(len*5)/2 , 32);
        display.setTextColor(WHITE);
        display.print(str);
    }

}
void Menu::selector(uint8_t icon){
    if(two_icon==0){
        display.fillRect(1,1,127,10,WHITE);
    }

    else display.fillRect(1+64*icon,1,63,10,WHITE);
}


