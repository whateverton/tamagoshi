#include "text_data.h"

const char *play[2] = {"Jogar","Play"};
const char *settings[2] = {"Configurações","Settings"};
const char *credits[2] = {"Créditos","Credits"};
const char *exit[2] = {"Sair","Exit"};

const char *change_lang[2] = {"Mudar Idioma","Change Language"};
const char *using_lang[2] = {"Idioma atual: Português","Current Language: English"};
const char *back[2] = {"Retorna","Back"};

txt_type menu_options[4];
txt_type settings_options[3];

lang_type current_lang;

void toggleLanguage()
{
	lang_type update_lang = (lang_type)(current_lang + 1);
	
	if(update_lang >= TOTAL_LANG)
		update_lang = PT_BR;
	
	updateLanguage(update_lang);
}

void updateLanguage(lang_type lang)
{
	if(lang >= TOTAL_LANG) return;
	
	current_lang = lang;
	
	menu_options[0].pos.x = 0;
	menu_options[0].pos.y = 0;
	menu_options[0].txt = play[lang];
	
	menu_options[1].pos.x = 0;
	menu_options[1].pos.y = 150;
	menu_options[1].txt = settings[lang];
	
	menu_options[2].pos.x = 0;
	menu_options[2].pos.y = 300;
	menu_options[2].txt = credits[lang];

	menu_options[3].pos.x = 0;
	menu_options[3].pos.y = 450;
	menu_options[3].txt = exit[lang];
	
	settings_options[0].pos.x = 0;
	settings_options[0].pos.y = 0;
	settings_options[0].txt = change_lang[lang];
	
	settings_options[1].pos.x = 0;
	settings_options[1].pos.y = 150;
	settings_options[1].txt = using_lang[lang];
	
	settings_options[2].pos.x = 0;
	settings_options[2].pos.y = 300;
	settings_options[2].txt = back[lang];
}
