#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <sstream>


void atualizaTela(){
	static int pg = 1;
	setvisualpage(pg);																//pagina mostrada ao usuário	
	if (pg == 1) pg = 2; else pg = 1;
	setactivepage(pg);																//Pagina ativa
	cleardevice();																	//Limpa tela
	
}

void printNum(int x, int y, int come){
	char aux[20];
	
	std::ostringstream convert;
	convert << (int)come;
	strcpy(aux, convert.str().c_str());

	outtextxy(x, y, aux);
}


void desenhaTela(){

	/*int tamanho = imagesize( 0, 0, 50, 110);
	void *fig;

	readimagefile("barra_superior.png", 0, 0, 50, 110);
	fig = malloc(tamanho);
	putimage(0, 50, fig, 1);*/
	
}
