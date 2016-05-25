#include <graphics.h>
#include "logica.h"
#include "desenha.h"

#define COME_POSX 30
#define COME_POSY 50

using namespace std;

float come = 100.0;

bool decremento(float dT){
	come -= (1.0 * dT);
	if ( come <= 0.0)	
		return false;
	return true;
}

bool atualizaLogica(const float dT){
	decremento(dT);
	
	printNum(COME_POSX, COME_POSY, come);
}

void botoes(char tecla){
	if (kbhit()){
    tecla = getch();
	 
	if(GetKeyState(VK_LEFT)&0x80)	come += 20;
	}
}

