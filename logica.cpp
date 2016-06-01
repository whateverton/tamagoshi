#include <graphics.h>
#include <iostream>

#include "logica.h"
#include "desenha.h"

#define STATS_POSY		18

#define CONTROLE_STATS	101

#define COME_POSX		80
#define COME_INC 		20

#define BRINCA_POSX		185

#define CAGA_POSX		290

#define BANHO_POSX		395

#define PONTUACAO_POSX	205
#define PONTUACAO_POSY	55

//necessidades
float come = 101.0;
float brinca = 101.0;
float caga = 101.0;
float banho = 101.0;
float pontuacao = 0.0;

int mouse_dx;
int mouse_dy;

typedef struct{
	int posX;
	int posY;
	int altura;
	int largura;
	void * img;
}TObj_pos;

TObj_pos imagem[50];

void initGame(){
	imagem[0].posX = 0;
	imagem[1].posY = 550;
	imagem[2].altura = 50;
	imagem[3].largura = 110;
	
}

bool incrementoPontuacao(float dT){
	pontuacao += (10.0 * dT);
	if (pontuacao >= 100000.0)	
		return false;
	return true;
	
}

bool decrementoCome(float dT){
	come -= (1.0 * dT);
	if (come <= 0.0)	
		return false;
	return true;
	
}

bool decrementoBrinca(float dT){
	brinca -= (1.0 * dT);
	if (brinca <= 0.0)	
		return false;
	return true;
}

bool decrementoCaga(float dT){
	caga -= (1.0 * dT);
	if (caga <= 0.0)	
		return false;
	return true;
}

bool decrementoBanho(float dT){
	banho -= (1.0 * dT);
	if (banho <= 0.0)	
		return false;
	return true;
}


bool atualizaLogica(const float dT){
	
	incrementoPontuacao(dT);
	decrementoCome(dT);
	decrementoBrinca(dT);
	decrementoCaga(dT);
	decrementoBanho(dT);
	
	printNum(PONTUACAO_POSX,	PONTUACAO_POSY,	pontuacao);
	printNum(COME_POSX,			STATS_POSY,		come);
	printNum(BRINCA_POSX,		STATS_POSY,		brinca);
	printNum(CAGA_POSX,			STATS_POSY,		caga);
	printNum(BANHO_POSX,		STATS_POSY,		banho);
	
	encerraJogo(dT);
}

bool encerraJogo(float dT){
	
	dT += 1000;
	if (dT <= 180000)
		return false;
	return true;
}

void botoes(char tecla){
	if(ismouseclick(WM_LBUTTONDOWN)){
		getmouseclick(WM_LBUTTONDOWN, mouse_dx, mouse_dy);
		
		if (come < CONTROLE_STATS){
			if ((CONTROLE_STATS - come) >= 5){
				come += 5; 
				pontuacao += 100;
			}else{
				come += (CONTROLE_STATS - come);
				pontuacao += (come/3);
			}
		}
	}
}

