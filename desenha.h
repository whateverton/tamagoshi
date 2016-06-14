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

typedef struct{
	vetor2d_type pos;
	const char *txt;
}txt_type;

void desenhaTela();
void importaImagem(imagem_type *imagem,const char* nome);
void importaMascara(imagem_type *imagem, const char* nome);
void atualizaTela();
void printImg(imagem_type *imagem);
void printTxt(txt_type *txt);
void printNum(int , int , int);

#endif
