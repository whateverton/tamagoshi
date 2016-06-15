#include <graphics.h>
#include "main_menu.h"
#include "desenha.h"
#include "rede.h"

game_state_type mainMenu()
{
	int mouse_dx, mouse_dy;
	
	for(int i = 0; i < 5; ++i)
		printTxt(&menu_options[i]);
	
	if(ismouseclick(WM_LBUTTONDOWN)){
		getmouseclick(WM_LBUTTONDOWN, mouse_dx, mouse_dy);
		
		if(mouse_dy < 120)
			return IN_GAME;

		if((mouse_dy > 120) && (mouse_dy < 240))
			return CONNECTION;
			
		if((mouse_dy > 240) && (mouse_dy < 360))
			return SETTINGS;
			
		if((mouse_dy > 360) && (mouse_dy < 480))
			return CREDITS;
			
		if(mouse_dy > 480)
			return EXIT;
	}
	
	return MAIN_MENU;
}


game_state_type connectUDP()
{
	static int timeout_trying = 100;
	static int attempt = 0;

	printTxt(&connect_display);
		
	if(--timeout_trying) return CONNECTION;
	else timeout_trying = 100;
	
	iniRede();
		
	if(attempt++ < 3)
	{
		if(!connectToServer()) return CONNECTION;
		else
		{
			attempt = 0;
			return IN_GAME;
		}
	}
	else
	{
		if(!waitClient()) return CONNECTION;
		else
		{
			attempt = 0;
			return IN_GAME;
		}
	}
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


game_state_type creditsMenu()
{	
	for(int i = 0; i < 13; ++i)
		printTxt(&credits_display[i]);
	
	if(ismouseclick(WM_LBUTTONDOWN))
		return MAIN_MENU;
	
	return CREDITS;
}
