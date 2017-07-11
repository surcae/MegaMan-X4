#pragma once
enum DIRECTION
{
	D_LEFT = 0,
	D_RIGHT,
	D_UP,
	D_DOWN,
};

enum FIELD
{
	STAGE_LOGO = 0,
	STAGE_ONE = 1,
	STAGE_TWO = 2,
};

enum OBJ_NUM
{
	OBJ_NUM_BG,
	OBJ_NUM_BG2,
	OBJ_NUM_PLAYER,
	OBJ_NUM_MONSTER,
	OBJ_NUM_UI,
};

enum SOUND_INDEX
{
	E_SOUND_THEME = 0,
	E_SOUND_BUTTON,
	E_SOUND_READY,
	E_SOUND_HOLDING,
	E_SOUND_CHARGING,
	E_SOUND_FIRESOUND,
	E_SOUND_DESTROY,
	E_SOUND_DAMAGED,
};

enum TEX_TYPE
{
	TEXTYPE_SINGLE = 0,
	TEXTYPE_MULTI = 1,
};