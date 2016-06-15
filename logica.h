#ifndef __LOGICA_H__
#define __LOGICA_H__

bool decrementoCome(float dT);
bool decrementoBrinca(float dT);
bool decrementoCaga(float dT);
bool decrementoBanho(float dT);
bool incrementoPontuacao(float dT);


void initGame();
int botoes(void);
bool encerraJogo(float dT);
bool atualizaLogica(const float dT);
void setMultiplayer(bool m);

#endif
