#ifndef __TEXT_DATA_H__
#define __TEXT_DATA_H__

#include "desenha.h"

typedef enum{
	 PT_BR
	,ENG
	,TOTAL_LANG
}lang_type;

extern txt_type menu_options[5];
extern txt_type settings_options[3];
extern txt_type credits_display[13];
extern txt_type connect_display;

void updateLanguage(lang_type lang);
void toggleLanguage();

#endif
