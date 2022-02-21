#pragma once
#include <iostream>
#include <random>
#include <string>

using namespace	std;

enum ePoint {
	KK,
	MJ = 11,
	DD = 17,
	KD = 27
};

struct _jokbo {
	int month;
	string paint;
};

struct _Player_Sutda {
	string name;
	int point;
	_jokbo card[2];
	int money = 10000;
};

int St_Random_num();
void Print_state(_Player_Sutda* player, int player_size);
void Calc_money(_Player_Sutda* player, int player_size);
void Calc_jokbo(_Player_Sutda* player, int player_size);
void Init_and_shuffle(_jokbo* cards);
void Draw_card(_Player_Sutda* player, _jokbo* cards, int player_size);
void Play_sutda();