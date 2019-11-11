#include <Arduino.h>
void lcdml_menu_clear();
void lcdml_menu_display();



void mFunc_information(uint8_t param);
void mFunc_screensaver(uint8_t param);
void mFunc_timer_info(uint8_t param);
void mFunc_p2(uint8_t param);
void mFunc_back(uint8_t param);
void mFunc_goToRootMenu(uint8_t param);
void mFunc_jumpTo_timer_info(uint8_t param);

void lcdml_menu_control(void);

void timerIsr();

void mFunc_set_data(uint8_t param);


