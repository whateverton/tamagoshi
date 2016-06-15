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
#define LARGURA_BOTAO	105

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

typedef struct{
	imagem_type array[3][2];
	int evol = 0;
	int state = 0;
	const float counter_reload = 0.5;
	float counter;
	
	void update (float dT){
		if((counter -= dT) > 0) return;
		
		counter = counter_reload;
		
		if(state == 0){
			state = 1;
		}else{
			state = 0;
		}
	}
	
	imagem_type *getSprite () {
		return &array[evol][state];
	}
	
	
}sprites;

char *button_idle_img_path[] = {
	 "./images/Button_come.bmp"
	,"./images/Button_Dorme.bmp"
	,"./images/Button_Caga.bmp"
	,"./images/Button_Banho.bmp"
};
char *button_pressed_img_path[] = {
	 "./images/Button_come_Pressed.bmp"
	,"./images/Button_Dorme_Pressed.bmp"
	,"./images/Button_Caga_Pressed.bmp"
	,"./images/Button_Banho_Pressed.bmp"
};
char *button_mask = "./images/Mascaras/Mascara_Zeta_Button.bmp";

char *sprites_img[] = {
	 "./images/Monster_evo1_1.bmp"
	,"./images/Monster_evo1_2.bmp"
	,"./images/Monster_evo2_1.bmp"
	,"./images/Monster_evo2_2.bmp"
	,"./images/Monster_evo3_1.bmp"
	,"./images/Monster_evo3_2.bmp"
};

char *sprites_mask[] = {
	"./images/Mascaras/Mascara_evo1_1.bmp"
	,"./images/Mascaras/Mascara_evo1_2.bmp"
	,"./images/Mascaras/Mascara_evo2_1.bmp"
	,"./images/Mascaras/Mascara_evo2_2.bmp"
	,"./images/Mascaras/Mascara_evo3_1.bmp"
	,"./images/Mascaras/Mascara_evo3_2.bmp"
};

char *background_img = "./images/bckgd_game.bmp";


//necessidades
float brinca = 101.0;
float caga = 101.0;
float banho = 101.0;
float pontuacao = 0.0;

int mouse_dx;
int mouse_dy;

necessidades_type necessidades[MAX_NECESSIDADES];
sprites monster;
imagem_type background;

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
		
		importaImagem(&necessidades[i].botao_idle,button_idle_img_path[i]);
		//importaImagem(&necessidades[i].botao_idle,"./images/botao_idle.bmp");
		importaMascara(&necessidades[i].botao_idle,button_mask);
		importaImagem(&necessidades[i].botao_pressionado,button_pressed_img_path[i]);
		//importaImagem(&necessidades[i].botao_pressionado,"./images/botao_pressionado.bmp");
		importaMascara(&necessidades[i].botao_pressionado,button_mask);
		
		necessidades[i].botao_atual = &necessidades[i].botao_idle;
	}
	
	monster.counter = monster.counter_reload;
	monster.array[0][0].altura = 600;
	monster.array[0][0].largura = 420;
	importaImagem(&monster.array[0][0],sprites_img[0]);
	importaMascara(&monster.array[0][0],sprites_mask[0]);
	monster.array[0][1].altura = 600;
	monster.array[0][1].largura = 420;
	importaImagem(&monster.array[0][1],sprites_img[1]);
	importaMascara(&monster.array[0][1],sprites_mask[1]);
	
	monster.array[1][0].altura = 600;
	monster.array[1][0].largura = 420;
	importaImagem(&monster.array[1][0],sprites_img[2]);
	importaMascara(&monster.array[1][0],sprites_mask[2]);
	monster.array[1][1].altura = 600;
	monster.array[1][1].largura = 420;
	importaImagem(&monster.array[1][1],sprites_img[3]);
	importaMascara(&monster.array[1][1],sprites_mask[3]);
	
	monster.array[2][0].altura = 600;
	monster.array[2][0].largura = 420;
	importaImagem(&monster.array[2][0],sprites_img[4]);
	importaMascara(&monster.array[2][0],sprites_mask[4]);
	monster.array[2][1].altura = 600;
	monster.array[2][1].largura = 420;
	importaImagem(&monster.array[2][1],sprites_img[5]);
	importaMascara(&monster.array[2][1],sprites_mask[5]);
	
	background.altura = 600;
	background.largura = 420;
	importaImagem(&background,background_img);
	
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
	pontuacao += (300.0 * dT);
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
	
	printImg(&background);
	incrementoPontuacao(dT);
	
	if(pontuacao >= 2000.0){
		if(pontuacao >= 6000.0) monster.evol = 2;
		else monster.evol = 1;
	}
	
	monster.update(dT);
	printImg(monster.getSprite());
	
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

