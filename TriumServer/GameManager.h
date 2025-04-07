#pragma once
#include "stdafx.h"
#include "SESSION.h"
	//#include "OVER_PLUS.h"

class GameManager
{
public:
	SOCKET server_socket, client_socket;
	HANDLE h_iocp;
	OVER_PLUS accept_over;
	array<SESSION, MAX_USER> clients;

	GameManager();
	~GameManager();
	void S_Bind_Listen();
	void S_Accept();
	void Make_threads();
	void Worker_thread();
	void Disconnect(int cl_id);
	void Process_packet(int c_id, char* packet);
	int Get_new_Client_id();
};
