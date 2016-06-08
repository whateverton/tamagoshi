#ifndef __DESENHA_H__
#define __DESENHA_H__


typedef struct{
	int x,y;
}vetor2d_type;

typedef struct{
	vetor2d_type pos;
	int altura;
	int largura;
	void * img;
	void *mask;
}imagem_type;

void desenhaTela();
void importaImagem(imagem_type *imagem,const char* nome);
void atualizaTela();
void printImg(imagem_type *imagem);
void printNum(int , int , int);

#endif
