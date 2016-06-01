#include <graphics.h>

#include "desenha.h"
#include "logica.h"

using namespace std;

#define ESC		27
#define LEFT   	75
#define RIGHT  	77
#define UP     	72
#define DOWN   	80
#define FPS		1.0/60.0

int n;										//Numero que sera convertido para char, para printar o numero
int pos_x = 50;								//Posicao inicial do ponto X
int pos_y = 30;								//Posicao inicial do ponto Y


int main (){
	initwindow(430, 600, "hw_test");
	cleardevice();
	
	char tcl;							 	//Provisorio enquanto nao ha um final de jogo definido
	
	while (tcl != ESC){						//Loop do jogo
		if (kbhit()) tcl = getch();			//Captura teclado
		desenhaTela();
		botoes(tcl);						//Captura botõe provisóriamente
		if (!decrementoCome(0) || !decrementoBrinca(0) || !decrementoCaga(0) || !decrementoBanho(0))	break;	//Um dos possiveis finais de jogo
		atualizaLogica(FPS);
		delay(int(FPS  * 1000.0));
		atualizaTela();
	}

	while(!kbhit());
	return 0;	
}

