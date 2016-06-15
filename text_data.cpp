#include "text_data.h"
#include <string.h>

#define CHAR_SIZE	16
#define TXT_CENTER_X(length)	((420-(length*CHAR_SIZE))/2)

const char *single[2] = {"Um jogador","Singleplayer"};
const char *multi[2] = {"Dois Jogadores","Multiplayer"};
const char *settings[2] = {"Configurações","Settings"};
const char *credits[2] = {"Créditos","Credits"};
const char *exit[2] = {"Sair","Exit"};

const char *change_lang[2] = {"Mudar Idioma","Change Language"};
const char *using_lang[2] = {"Idioma atual: Português","Current Language: English"};
const char *back[2] = {"Retorna","Back"};

const char *team[2] = {"Equipe:","Team:"};
const char *members[4][3] = {
	 {"Artista","Celina Carvalho de Araújo","1680961523041"}
	,{"Programador","Kleber Carlos Francisco","1680961523014"}
	,{"Artista","Samuel Adonai Guilherme","1680961523037"}
	,{"Programador","Willian Rodrigues Sampaio Lima","1680961523019"}
};

const char *multi_connection[2] = {"Conectando...","Connecting..."};
const char *multi_wait[2] = {"Aguarde...", "Wait..."};
const char *multi_your_score[2] = {"Seus Pontos: ", "Your Points: "};
const char *multi_other_score[2] = {"Pontos do Outro: ", "Other Points: "};

txt_type menu_options[5];
txt_type settings_options[3];
txt_type credits_display[13];
txt_type connect_display;
txt_type wait_display;
txt_type my_score_display;
txt_type other_score_display;

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
	
	menu_options[0].pos.x = TXT_CENTER_X(strlen(single[lang]));
	menu_options[0].pos.y = 0;
	menu_options[0].txt = single[lang];
	
	menu_options[1].pos.x = TXT_CENTER_X(strlen(multi[lang]));
	menu_options[1].pos.y = 120;
	menu_options[1].txt = multi[lang];
	
	menu_options[2].pos.x = TXT_CENTER_X(strlen(settings[lang]));
	menu_options[2].pos.y = 240;
	menu_options[2].txt = settings[lang];
	
	menu_options[3].pos.x = TXT_CENTER_X(strlen(credits[lang]));
	menu_options[3].pos.y = 360;
	menu_options[3].txt = credits[lang];

	menu_options[4].pos.x = TXT_CENTER_X(strlen(exit[lang]));
	menu_options[4].pos.y = 480;
	menu_options[4].txt = exit[lang];
	
	settings_options[0].pos.x = TXT_CENTER_X(strlen(change_lang[lang]));
	settings_options[0].pos.y = 0;
	settings_options[0].txt = change_lang[lang];
	
	settings_options[1].pos.x = TXT_CENTER_X(strlen(using_lang[lang]));
	settings_options[1].pos.y = 150;
	settings_options[1].txt = using_lang[lang];
	
	settings_options[2].pos.x = TXT_CENTER_X(strlen(back[lang]));
	settings_options[2].pos.y = 300;
	settings_options[2].txt = back[lang];
	
	credits_display[0].pos.x = TXT_CENTER_X(strlen(team[lang]));
	credits_display[0].pos.y = 50;
	credits_display[0].txt = team[lang];
	
	for(int i = 0, extra_space = 0; i < 4; ++i)
	{		
		for(int j = 0; j < 3; ++j)
		{
			if(!j) extra_space += 40;
			
			credits_display[(i*3)+j+1].pos.x = 0;
			credits_display[(i*3)+j+1].pos.y = 100+(((i*3)+j)*CHAR_SIZE)+extra_space;
			credits_display[(i*3)+j+1].txt = members[i][j];
		}
	}
	
	connect_display.pos.x = TXT_CENTER_X(strlen(multi_connection[lang]));
	connect_display.pos.y = 50;
	connect_display.txt = multi_connection[lang];
	
	wait_display.pos.x = TXT_CENTER_X(strlen(multi_wait[lang]));
	wait_display.pos.y = 50;
	wait_display.txt = multi_wait[lang];
	
	my_score_display.pos.x = TXT_CENTER_X(strlen(multi_your_score[lang]));
	my_score_display.pos.y = 50;
	my_score_display.txt = multi_your_score[lang];
	
	other_score_display.pos.x = TXT_CENTER_X(strlen(multi_other_score[lang]));
	other_score_display.pos.y = 80;
	other_score_display.txt = multi_other_score[lang];
	
}
