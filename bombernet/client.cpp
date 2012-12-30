#include "stdafx.h"
#include "client.h"

namespace Client
{
	SOCKET sock;
    SOCKADDR_IN sin;

	int Init()
	{
		WSADATA WSAData;
        int error = WSAStartup(MAKEWORD(2,2), &WSAData);

		if(error)
		{
			printf("[client] error in WSAstartup\n");
			return error;
		}
		return 0;
	}

	int Connect()
	{

		sock = socket(AF_INET, SOCK_STREAM, 0);
 
        /* Configuration de la connexion */
        sin.sin_addr.s_addr = inet_addr("127.0.0.1");
        sin.sin_family = AF_INET;
        sin.sin_port = htons(PORT);
 
        /* Si le client arrive à se connecter */
        if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
            printf("Connexion à %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));
        else
            printf("Impossible de se connecter\n");
 
        /* On ferme la socket précédemment ouverte */
        closesocket(sock);
		return 0;
	}
}