#include "stdafx.h"
#include "server.h"
#pragma comment(lib, "wsock32.lib")



namespace Server
{
	bool started;
	SOCKADDR_IN sin;
    SOCKET sock;
    socklen_t recsize = sizeof(sin);
	int sock_err;

	 /* Socket et contexte d'adressage du client */
    SOCKADDR_IN csin;
    SOCKET csock;
    socklen_t crecsize = sizeof(csin);

	int Init()
	{
		WSADATA WSAData;
        int error = WSAStartup(MAKEWORD(2,2), &WSAData);
		if(error)
		{
			printf("WSA startup failed: %d\n",error);
			return error;
		}
		return 0;
	}

	void Accept()
	{
	}

	int Start()
	{
		sock = socket(AF_INET, SOCK_STREAM, 0);
		if(sock == INVALID_SOCKET)
        {
			printf("[server] invalid socket\n");
			return 1;
		}

		sin.sin_addr.s_addr = htonl(INADDR_ANY);  /* Adresse IP automatique */
        sin.sin_family = AF_INET;                 /* Protocole familial (IP) */
        sin.sin_port = htons(PORT);               /* Listage du port */
        sock_err = bind(sock, (SOCKADDR*)&sin, recsize);

		if(sock_err == SOCKET_ERROR)
		{
			printf("[server] socket error on bind\n");
			return 1;
		}
        
		sock_err = listen(sock, 5);
		printf("[server] listening on port %d\n",PORT);
		if(sock_err == SOCKET_ERROR)
		{
			printf("[server] socket error on listen\n");
			return 1;
		}
		started = true;

		printf("[server] waiting for client\n");
		csock = accept(sock, (SOCKADDR*)&csin, &crecsize);
		printf("[server] client connected on %d of %s:%d\n", csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port));
		
		return 0;
	}

	int Stop()
	{
		return 0;
	}

	bool Started()
	{
		return started;
	}
}