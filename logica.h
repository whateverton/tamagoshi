#ifndef __LOGICA_H__
#define __LOGICA_H__

bool decrementoCome(float dT);
bool decrementoBrinca(float dT);
bool decrementoCaga(float dT);
bool decrementoBanho(float dT);
bool incrementoPontuacao(float dT);


void initGame();
void botoes(char tecla);
bool encerraJogo(float dT);
bool atualizaLogica(const float dT);

#endif
