#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

/*
 * socket
 * bind
 * listen
 * accept
 * send/recv
 */

#define SERVER_PORT 8888
#define BACKLOG	    10

int main(int argc, char **argv)
{
	int iSocketServer;
	int iRet;
	int iAddrLen;
	int iRecvLen;
	int iSocketClient;
	struct sockaddr_in tSocketServerAddr;
	struct sockaddr_in tSocketClientAddr;
	
	unsigned char ucRecvBuf[1000];
	
	int iClientNum = -1;

	signal(SIGCHLD, SIG_IGN);	//destory child process defunct

	//IPv4	TCP
	iSocketServer = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == iSocketServer)
	{
		printf("socket error!\n");
		return -1;
	}
	tSocketServerAddr.sin_family = AF_INET;
	tSocketServerAddr.sin_port   = htons(SERVER_PORT);	//host to net, short
	tSocketServerAddr.sin_addr.s_addr = INADDR_ANY;	//all of the host ip
	memset(tSocketServerAddr.sin_zero, 0, 8);

	iRet = bind(iSocketServer, (const struct sockaddr *) &tSocketServerAddr, sizeof(struct sockaddr));

	if(-1 == iRet)
	{
		printf("bind error!\n");
		return -1;
	}

	iRet = listen(iSocketServer, BACKLOG);
	if(-1 == iRet)
	{
		printf("listen error!\n");
		return -1;
	}

	while(1)
	{
		iAddrLen = sizeof(struct sockaddr);
		iSocketClient =	accept(iSocketServer, (struct sockaddr *)&tSocketClientAddr,  &iAddrLen);
		if( -1 !=  iSocketClient)
		{
			iClientNum++;
			printf("Get connect from %d : %s\n", iClientNum, inet_ntoa(tSocketClientAddr.sin_addr));
			if(!fork())
			{
				/* child process code  */
				while(1)
				{
					/* receive data from client and show */
					iRecvLen = recv(iSocketClient, ucRecvBuf, 999, 0);
					if(iRecvLen <= 0)
					{
						close(iSocketClient);
						return -1;
					}
					else
					{
						ucRecvBuf[iRecvLen] = '\0';
						printf("Get Msg From Client %d : %s\n", iClientNum, ucRecvBuf);
					}
				}
			}
		}
	}
	close(iSocketServer);
	return 0;	
}

