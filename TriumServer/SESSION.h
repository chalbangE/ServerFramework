#pragma once
#include "stdafx.h"
#include "OVER_PLUS.h"

class SESSION
{
	OVER_PLUS _recv_over;

public:
	mutex								_s_lock;
	SESSION_STATE						_state;
	int									_id;
	SOCKET								_socket;
	int									_prev_remain;

	SESSION();
	~SESSION();

	void do_recv();

	void do_send(void* packet);
	void send_login_info_packet();
	void send_add_player_packet(SESSION* client);
	void send_chat_packet(int c_id, const char* mess);
	void send_break_rock_packet(int c_id);
};


