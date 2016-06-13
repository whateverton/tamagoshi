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

#define ALTURA_BOTAO 	50
#define LARGURA_BOTAO	110

typedef enum{
	 COME
	,BRINCA
	,CAGA
	,BANHO
	,MAX_NECESSIDADES
}necessidades_enum;

typedef struct{
	imagem_type botao_idle;
	imagem_type botao_pressionado;
	imagem_type *botao_atual;
	char *texto;
	float valor;
	float decremento;	
	float incremento;
}necessidades_type;


//necessidades
float brinca = 101.0;
float caga = 101.0;
float banho = 101.0;
float pontuacao = 0.0;

int mouse_dx;
int mouse_dy;

necessidades_type necessidades[MAX_NECESSIDADES];

void initGame(){
	
	for(int i =  COME; i < MAX_NECESSIDADES; ++i){
		necessidades[i].valor = 101.0;
		necessidades[i].decremento = 0.10;
		necessidades[i].incremento = 5.0;
		
		necessidades[i].botao_idle.pos.x = LARGURA_BOTAO * i; // botão da esquerda para direita
		necessidades[i].botao_idle.pos.y = 550;
		necessidades[i].botao_idle.altura = ALTURA_BOTAO; // px
		necessidades[i].botao_idle.largura = LARGURA_BOTAO; // px
		
		necessidades[i].botao_pressionado.pos.x = LARGURA_BOTAO * i; // botão da esquerda para direita
		necessidades[i].botao_pressionado.pos.y = 550;
		necessidades[i].botao_pressionado.altura = ALTURA_BOTAO; // px
		necessidades[i].botao_pressionado.largura = LARGURA_BOTAO; // px
		
<<<<<<< HEAD
		importaImagem(&necessidades[i].botao_idle,"botao_idle.png");
		importaImagem(&necessidades[i].botao_pressionado,"botao_pressionado.png");
=======
		importaImagem(&necessidades[i].botao_idle,"botao_idle.bmp");
		importaImagem(&necessidades[i].botao_pressionado,"botao_pressionado.bmp");
>>>>>>> 14789df313b77a8df980a375690d0973ff0aeb15
		
		necessidades[i].botao_atual = &necessidades[i].botao_idle;
	}
		
}

void incNecessidade (float dT, necessidades_type &n){
	n.valor += n.incremento;
	
	if(n.valor > 101.0){
		n.valor = 101.0;
	}
}

bool decNecessidade (float dT, necessidades_type &n){
	n.valor -= n.decremento;
	
	if(n.valor <= 0.0){
		return false;
	}
	
	return true;
}

bool incrementoPontuacao(float dT){
	pontuacao += (10.0 * dT);
	if (pontuacao >= 100000.0)	
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
	
	for(int i = COME; i < MAX_NECESSIDADES; ++i){
		if(!decNecessidade(dT,necessidades[i]))
			return false;
	}
	
	
	int index;
	if((index = botoes()) > -1){
		incNecessidade(dT,necessidades[index]);
	}
	
	printNum(PONTUACAO_POSX,	PONTUACAO_POSY,	pontuacao);
	printNum(COME_POSX,			STATS_POSY,		necessidades[COME].valor);
	printNum(BRINCA_POSX,		STATS_POSY,		necessidades[BRINCA].valor);
	printNum(CAGA_POSX,			STATS_POSY,		necessidades[CAGA].valor);
	printNum(BANHO_POSX,		STATS_POSY,		necessidades[BANHO].valor);
	
	for(int i = COME; i < MAX_NECESSIDADES; ++i){
		printImg(necessidades[i].botao_atual);
	}
	
	// return encerraJogo(dT);
	return true;
}

bool encerraJogo(float dT){
	
	dT += 1000.0;
	if (dT <= 180000.0)
		return false;
	return true;
}

int botoes(void){
	
	
	if(ismouseclick(WM_LBUTTONDOWN)){
		getmouseclick(WM_LBUTTONDOWN, mouse_dx, mouse_dy);
		
		for(int i = COME; i < MAX_NECESSIDADES; ++i){
						
			if((necessidades[i].botao_atual->pos.x > mouse_dx) || ((necessidades[i].botao_atual->pos.x + necessidades[i].botao_atual->largura) < mouse_dx)) continue;
			if((necessidades[i].botao_atual->pos.y > mouse_dy) || ((necessidades[i].botao_atual->pos.y + necessidades[i].botao_atual->altura) < mouse_dy)) continue;
			
			necessidades[i].botao_atual = &necessidades[i].botao_pressionado;
			
			return i;
		}
	}
	if(ismouseclick(WM_LBUTTONUP)){		
		clearmouseclick(WM_LBUTTONUP);
		for(int i = COME; i < MAX_NECESSIDADES; ++i){						
			if(necessidades[i].botao_atual == &necessidades[i].botao_pressionado){
				necessidades[i].botao_atual = &necessidades[i].botao_idle;
			}
		}
	}
	return -1;
}

