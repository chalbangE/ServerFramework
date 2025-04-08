#pragma once
#include "stdafx.h"
#include "OVER_PLUS.h"
//#include "../../Direct12Framework/SimpleMath.h"
//
//using namespace DirectX;
//using Vec3 = SimpleMath::Vector3;


class SESSION
{
	OVER_PLUS _recv_over;

public:
	mutex				_s_lock;
	SESSION_STATE		_state;
	int					_id;
	SOCKET				_socket;
	int					_prev_remain;

	Vec3				_pos;	
	Vec3				_look_dir; // 캐릭터가 보고있는 방향

	SESSION();
	~SESSION();

	void do_recv();

	void do_send(void* packet);
	void send_login_info_packet();
	void send_add_player_packet(SESSION* client);
	void send_chat_packet(int c_id, const char* mess);
	void send_move_packet(SESSION* client);
};