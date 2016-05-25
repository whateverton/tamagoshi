#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <sstream>

#include "desenha.h"
#include "logica.h"

using namespace std;

#define ESC		27
#define LEFT   	75
#define RIGHT  	77
#define UP     	72
#define DOWN   	80
#define FPS		1.0/60.0

//necessidades

float brinca = 100.0;
float caga = 100.0;
float banho = 100.0;

int n;
int pos_x = 50;
int pos_y = 30;


int main (){
	initwindow(430, 600, "hw_test");
	cleardevice();
	
	char tcl;							 	//provisorio enquanto nao ha um final de jogo definido
	
	while (tcl != ESC){
		if (kbhit()) tcl = getch();
		desenhaTela();
		botoes(tcl);
		if (!decremento(0))	break;
		atualizaLogica(FPS);
		delay(int(FPS  * 1000.0));
		atualizaTela();
	}

	while(!kbhit());
	return 0;	
}

