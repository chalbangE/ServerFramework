#pragma once

enum COMP_TYPE { OP_ACCEPT, OP_RECV, OP_SEND };
enum SESSION_STATE { ST_FREE, ST_ALLOC, ST_INGAME };
enum GAME_STATE { GS_LOGIN, GS_INGAME, GS_DEATH, GS_STOP };

enum KEY_FLAG : uint8_t {
	KEY_D = 0x01,
	KEY_S = 0x02,
	KEY_A = 0x04,
	KEY_W = 0x08,
	KEY_SHIFT = 0x10,
	KEY_CTRL = 0x20
};

enum S_OBJECT_TYPE : UINT8
{
    S_PLAYER,
    S_ENEMY,
    S_ITEM,
    S_PLAYER_PROJECTILE,
    S_ENEMY_PROJECTILE,
    S_OBSTACLE,
	S_TRIGGER,

	S_end
};