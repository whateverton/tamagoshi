#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <sstream>


void atualizaTela(){
	static int pg = 1;
	setvisualpage(pg);									//Pagina mostrada ao usuário	
	if (pg == 1) pg = 2; else pg = 1;					//Logica para trocar de pagina
	setactivepage(pg);									//Pagina ativa
	cleardevice();										//Limpa tela
}

void printNum(int x, int y, int num){
	char aux[20];										//char auxiliar que ira receber um numero convertido de inteiro para char		
	
	std::ostringstream convert;							//Funcao para converter um variavel em string
	convert << (int)num;								//Convertendo  apenas a parte inteira da variavel come  para char
	strcpy(aux, convert.str().c_str());					//Copiando uma string para um char para passar como parâmetro no outtextxy

	outtextxy(x, y, aux);								//Imprimir valor na tela
}

void desenhaTela(){
	setfillstyle(9, GREEN); 							//Barra superior-superior
	bar(0, 0, 430, 5);
	setfillstyle(9, GREEN);								//Barra inferior-superior
	bar(0, 45, 430, 50);
	
	//Logica para barras verticais da parte superior
	int bar_left = 0;
	int bar_top = 0;
	int bar_right = 5;
	int bar_bottom = 50;
	
	for(int b = 0; b < 6; b++){
		
	setfillstyle(9, GREEN);
	bar(bar_left, bar_top, bar_right, bar_bottom);
	
	bar_left += 106;
	bar_right += 106;
	}
}

void importaImagem(){
 /*	***readimagefile("desenho.jpg", 0, 0, 199, 149); <~ recebe a imagem + altura e largura do retangulo, e tamanho da imagem
 	***Tamanho = imagesize(0, 0, 199, 149); <~ determina o tamanho da memoria que sera utilzada para armazenar a imagem, 
	**a variave int Tamanho, recebe esse isso
 	>onde fig é um ponteiro do tipo void (void *fig) e recebe o tamanho da imagem.
 	>fig* é do tipo void porque ele deve ser alocado em uma regiao da memoria (malloc) para ser utilizado nas funcoes abaixo 
 	***getimage(0, 0, 199, 149, fig); <~ copia a imagem da tela para a memoria 
 	***putimage(  0, 100, fig, 0); <~ coloca a imagem salva na memoria de volta na tela */  	
}
