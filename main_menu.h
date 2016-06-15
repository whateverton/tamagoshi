#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include "text_data.h"

typedef enum{
	 MAIN_MENU
	,CONNECTION
	,IN_GAME
	,GAME_OVER
	,SETTINGS
	,CREDITS
	,EXIT
}game_state_type;

game_state_type mainMenu();
game_state_type settingsMenu();
game_state_type creditsMenu();
game_state_type connectUDP();

#endif
