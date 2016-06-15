#include "rede.h"

using namespace std;

int rede_socket = 0;
sockaddr_in local_addr;
sockaddr_in remote_addr;

int server_port;
char server_ip[16];

void configServer(char *ip, int port)
{
	server_port = port;
	strcpy(server_ip,ip);
}

bool iniRede()
{
	WSADATA wsaData;
	DWORD nonBlocking = 1;

	if(rede_socket) return true;

	if(WSAStartup(MAKEWORD(2,2),&wsaData) != NO_ERROR) return false;
	
	if(!(rede_socket = socket(AF_INET,SOCK_DGRAM,0))) return false;
	
	// Inicializa o endere?o da m?quina
	local_addr.sin_family = AF_INET;
	local_addr.sin_addr.s_addr = INADDR_ANY;
	local_addr.sin_port = htons(server_port);
	
	// Inicializa o endere?o da outra
	remote_addr.sin_family = AF_INET;
	remote_addr.sin_addr.s_addr = inet_addr(server_ip);
	remote_addr.sin_port = htons(server_port);
	
	if(bind(rede_socket,(struct sockaddr *)&local_addr , sizeof(local_addr)) == SOCKET_ERROR)
		return false;
	
	if(ioctlsocket(rede_socket, FIONBIO, &nonBlocking ) != 0)
		return false;
	
	return true;
}

bool connectToServer()
{
	data_type p;
	
	if(getData(p)){
		if(!(strcmp(p.buff,"CONNECT OK")))
		{
			cout << "Connected\n";

			return true;
		}
	}
	
	strcpy(p.buff,"REQ CONECT");
	p.buff_size = strlen("REQ CONECT") +1; // Tamanho da string + terminador 0
	p.operation = CONNECTION_REQ;
	sendData(p);
	
	cout<<"Trying..\n";
	
	return false;
}

bool waitClient (void)
{
	int num_b;
	data_type pack;

	if(num_b = getData(pack))
	{
		if(!strcmp(pack.buff,"REQ CONECT"))
		{
			strcpy(pack.buff,"CONNECT OK");
			pack.buff_size = strlen(pack.buff) + 1;
			pack.operation = CONNECTION_REQ;
			sendData(pack);
			
			
			cout<<"Connected\n";
			
			return true;
		}
		
	}
	
	cout<<"Waiting..\n";
	
	return false;
}

bool getData (data_type &pack)
{
	int sz = sizeof(remote_addr);
	//recvfrom (socket, buffer, lenght, flags, adrress, adress_lenght)
	int ret =  recvfrom(rede_socket,(char *)&pack,(sizeof(data_type)),0,(struct sockaddr *)&remote_addr,&sz );
	
	if ((ret < 0) && (WSAGetLastError() == WSAEWOULDBLOCK)) return 0;
	
	return ret;
}

bool sendData(data_type &p)
{
	//sendto (socket, message, length, flags, dest_address, dest_lenght)
	return sendto(rede_socket,(char *)&p,sizeof(unsigned int)*2 + p.buff_size,0,(LPSOCKADDR)&remote_addr,sizeof(sockaddr));
}


void closeCon (){
	 closesocket(rede_socket);
}
