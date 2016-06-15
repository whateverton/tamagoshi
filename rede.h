#include <windows.h>
#include <winsock.h>
#include <stdio.h>
#include <iostream>

#ifndef __REDE_H__
#define __REDE_H__

#define SOCK_BUFF_LEN 64

enum{
	 CONNECTION_REQ
	,SENDING_DATA

	,SCORE_UPDATE
};

typedef struct
{
	unsigned int operation;
	unsigned int buff_size;
	char buff[SOCK_BUFF_LEN];
}data_type;

// Prototipos -------------------------------------------------------
void configServer (char *ip, int port);
bool iniRede();
bool connectToServer();
bool waitClient(void);
bool getData(data_type &pack);
bool sendData(data_type &p);
void closeCon ();
// ------------------------------------------------------------------
#endif
