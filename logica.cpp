#include <graphics.h>
#include "logica.h"
#include "desenha.h"

float come = 100.0;

bool decremento(float dT){
	
	come -= (1.0 * dT);
	if ( come <= 0.0)	
		return false;
	return true;
}

void atualizaLogica(const float dT){
	int pos_x;
	int pos_y;
	int n;
	
	decremento(dT);
	printNum(pos_x, pos_y, n);
}

void botoes(char tecla){
	if (kbhit()){
    tecla = getch();
	 
	if(GetKeyState(VK_LEFT)&0x80)	come += 20;
	}
}

