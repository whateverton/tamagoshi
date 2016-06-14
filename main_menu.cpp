#include <graphics.h>
#include "main_menu.h"
#include "desenha.h"

game_state_type mainMenu()
{
	int mouse_dx, mouse_dy;
	
	for(int i = 0; i < 4; ++i)
		printTxt(&menu_options[i]);
	
	if(ismouseclick(WM_LBUTTONDOWN)){
		getmouseclick(WM_LBUTTONDOWN, mouse_dx, mouse_dy);
		
		if(mouse_dy < 150)
			return IN_GAME;

		if((mouse_dy > 150) && (mouse_dy < 300))
			return SETTINGS;
			
		if((mouse_dy > 300) && (mouse_dy < 450))
			return CREDITS;
			
		if(mouse_dy > 450)
			return EXIT;
	}
	
	return MAIN_MENU;
}

game_state_type settingsMenu()
{
	int mouse_dx, mouse_dy;
	
	for(int i = 0; i < 3; ++i)
		printTxt(&settings_options[i]);
	
	if(ismouseclick(WM_LBUTTONDOWN)){
		getmouseclick(WM_LBUTTONDOWN, mouse_dx, mouse_dy);
		
		if(mouse_dy < 300)		
			toggleLanguage();
			
		if((mouse_dy > 300) && (mouse_dy < 450))
			return MAIN_MENU;
	}
	
	return SETTINGS;
}
