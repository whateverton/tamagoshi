#include <graphics.h>

#include "desenha.h"
#include "logica.h"
#include "main_menu.h"
#include "rede.h"

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
	
	initwindow(420, 600, "Tamagoshi");
	cleardevice();
	
	initGame();
	updateLanguage(PT_BR);
	setMultiplayer(false);
	
	while(true)
	{
		switch(g_state)
		{
			case MAIN_MENU:
				g_state = mainMenu();
				break;
				
			case CONNECTION:
				if (kbhit()) tcl = getch();
				if(tcl == ESC)
				{
					g_state = MAIN_MENU;
					break;
				}
				
				g_state = connectUDP();
				if(g_state == IN_GAME)
					setMultiplayer(true);
				break;
			case IN_GAME:
				
				if (kbhit()) tcl = getch();		//Captura teclado
				
				//desenhaTela();
				if(!atualizaLogica(FPS) || (tcl == ESC)) 
					g_state = GAME_OVER;
				
				break;
			case GAME_OVER:
				g_state = EXIT;
				break;
			case SETTINGS:
				g_state = settingsMenu();
				break;
			case CREDITS:
				g_state = creditsMenu();
				break;
			case EXIT:
				goto exit;
		}
		
		delay(int(FPS  * 1000.0));
		atualizaTela();
	}
	
exit:
	closeCon();
	
	cleardevice();
	txt_type game_over;
	char *over =  "GAME OVER";
	
	game_over.pos.x = 0;
	game_over.pos.y = 50;
	game_over.txt = over;
	
	printTxt(&game_over);
	
	atualizaTela();
	
	while(!kbhit());
	closegraph();
	
}

