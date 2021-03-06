#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <sstream>
#include "desenha.h"

#include "desenha.h"
#include "logica.h"

void atualizaTela(){
	static int pg = 1;
	setvisualpage(pg);									//Pagina mostrada ao usu�rio	
	if (pg == 1) pg = 2; else pg = 1;					//Logica para trocar de pagina
	setactivepage(pg);									//Pagina ativa
	cleardevice();										//Limpa tela
}

void printNum(int x, int y, int num){
	char aux[20];										//char auxiliar que ira receber um numero convertido de inteiro para char		
	
	std::ostringstream convert;							//Funcao para converter um variavel em string
	convert << (int)num;								//Convertendo  apenas a parte inteira da variavel come  para char
	strcpy(aux, convert.str().c_str());					//Copiando uma string para um char para passar como par�metro no outtextxy

	outtextxy(x, y, aux);								//Imprimir valor na tela
}

void printTxt(txt_type *txt){
	outtextxy(txt->pos.x, txt->pos.y, (char*)txt->txt);								//Imprimir valor na tela
}

void printImg(imagem_type *imagem){
	int mode = COPY_PUT;
	
	if(imagem->mask){
	 	putimage(imagem->pos.x, imagem->pos.y, imagem->mask, AND_PUT);
	 	mode = OR_PUT;
	 }
	
	putimage(imagem->pos.x, imagem->pos.y, imagem->img, mode);	
}


void importaImagem(imagem_type *imagem, const char* nome){
	int tamanho = 0;
	readimagefile(nome, 0, 0,imagem->largura, imagem->altura);
	tamanho = imagesize(0, 0,imagem->largura, imagem->altura);
	imagem->img =  malloc(tamanho);
	getimage(0, 0, imagem->largura,imagem->altura,imagem->img);
	
	imagem->mask  = NULL;

}

void importaMascara(imagem_type *imagem, const char* nome){
	int tamanho = 0;
	readimagefile(nome, 0, 0,imagem->largura, imagem->altura);
	tamanho = imagesize(0, 0,imagem->largura, imagem->altura);
	imagem->mask=  malloc(tamanho);
	getimage(0, 0, imagem->largura,imagem->altura,imagem->mask);
}

