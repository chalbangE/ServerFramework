#pragma once
#include "stdafx.h"
#include "OVER_PLUS.h"

class SESSION
{
	OVER_PLUS _recv_over;

public:
	mutex				_s_lock;
	SESSION_STATE		_state;
	int					_id;
	SOCKET				_socket;
	int					_prev_remain;

	float				_x, _y, _z;
	float				_cx, _cz; 
		// 카메라가 보고있는 방향만 알면 되기 때문에 y는 필요 없음

	SESSION();
	~SESSION();

	void do_recv();

	void do_send(void* packet);
	void send_login_info_packet();
	void send_add_player_packet(SESSION* client);
	void send_chat_packet(int c_id, const char* mess);
	void send_move_packet(SESSION* client);
};