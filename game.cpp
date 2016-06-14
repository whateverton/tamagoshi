#include <graphics.h>

#include "desenha.h"
#include "logica.h"
#include "main_menu.h"

using namespace std;

#define ESC		27
#define LEFT   	75
#define RIGHT  	77
#define UP     	72
#define DOWN   	80
#define FPS		1.0/60.0

game_state_type g_state = MAIN_MENU;

int n;										//Numero que sera convertido para char, para printar o numero
int pos_x = 50;								//Posicao inicial do ponto X
int pos_y = 30;								//Posicao inicial do ponto Y


int main (){
	char tcl;							 	//Provisorio enquanto nao ha um final de jogo definido
	
	initwindow(430, 600, "Tamagoshi");
	cleardevice();
	
	initGame();
	updateLanguage(PT_BR);
	
	while(true)
	{
		switch(g_state)
		{
			case MAIN_MENU:
				g_state = mainMenu();
				break;
			case IN_GAME:
				
				if (kbhit()) tcl = getch();		//Captura teclado
				
				desenhaTela();
				if(!atualizaLogica(FPS) || (tcl == ESC)) g_state = GAME_OVER;
				
				break;
			case GAME_OVER:
				while(!kbhit());
				g_state = EXIT;
				break;
			case SETTINGS:
				g_state = settingsMenu();
				break;
			case CREDITS:
				if(kbhit()) g_state = MAIN_MENU;
				break;
			case EXIT:
				return 0;
		}
		
		delay(int(FPS  * 1000.0));
		atualizaTela();
	}
}

