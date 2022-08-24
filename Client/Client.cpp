#include <iostream>
#include "pch.h"

#include <Windows.h>
#include <WinSock2.h>
#include <MSWSock.h>
#include <WS2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
	HelloWorld();

	WSADATA swaData;
	WORD wVerstionRequested = MAKEWORD(2, 2);

	//윈속 초기화
	if (WSAStartup(MAKEWORD(2, 2), &swaData) != 0)
	{
		printf("WSAStartup failed with error\n");
		return -1;
	}

	//소켓 생성
	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);

	if (clientSocket == INVALID_SOCKET)
	{
		int32 errCode = WSAGetLastError();
		printf("ClientSocket Error %d", errCode);
		return 0;
	}

	//todo
	//IPv4
	SOCKADDR_IN serverAddr;
	memset(&serverAddr, 0, sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
	serverAddr.sin_port = htond(27015);

	if (connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		int32 errCode = WSAGetLastError();
		printf("Connect Error : %d", errCode);
		return -1;
	}

	printf("Connect Successed");

	while (true)
	{
		//Todo
		Sleep(1000);
	}

	//소켓 연결 끊기
	closesocket(clientSocket);

	//윈속 해제
	WSACleanup();

	return 0;
}
