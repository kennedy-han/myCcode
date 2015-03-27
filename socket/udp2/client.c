#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


/*
 * socket
 * connect
 * send/recv
 */

#define SERVER_PORT 8888

int main(int argc, char **argv)
{
	int iSocketClient;
	int iRet;
	int iSendLen;
	int iAddrLen;
	unsigned char ucSendBuf[1000];
	struct sockaddr_in tSocketServerAddr;

	if(argc != 2)
	{
		printf("Usage:\n");
		printf("%s <server_ip>\n", argv[0]);
		return -1;
	}

	tSocketServerAddr.sin_family = AF_INET;
	tSocketServerAddr.sin_port   = htons(SERVER_PORT);	//host to net, short
	//tSocketServerAddr.sin_addr.s_addr = INADDR_ANY;	//all of the host ip
	if(0 == inet_aton(argv[1], &tSocketServerAddr.sin_addr))
	{
		printf("invalid server_ip\n");
		return -1;
	}
	memset(tSocketServerAddr.sin_zero, 0, 8);

	iSocketClient = socket(AF_INET, SOCK_DGRAM, 0);
#if 0
	iRet = connect(iSocketClient, (const struct sockaddr *)&tSocketServerAddr, sizeof(struct sockaddr));
	
	if( -1 == iRet)
	{
		printf("connect error!\n");
		return -1;
	}
#endif

	while(1)
	{
		if (fgets(ucSendBuf, 999, stdin))
		{
#if 0
			iSendLen = send(iSocketClient, ucSendBuf, strlen(ucSendBuf), 0);
#else
			iAddrLen = sizeof(struct sockaddr);
			iSendLen = sendto(iSocketClient, ucSendBuf, strlen(ucSendBuf), 0,(const struct sockaddr *)&tSocketServerAddr, iAddrLen);

#endif
			if(iSendLen <= 0)
			{
				close(iSocketClient);
				return -1;
			}
		}
	}
	return 0;
}
