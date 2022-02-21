#pragma once
#include <iostream>
#include <string>
#include <random>
#include <vector>

using namespace std;

const int MAX_CARD = 52;

struct _CARD {
	string	shape;
	int		num;

	void Print() {
		cout << shape;
		switch (num)
		{
		case 1:
			cout << 'A';
			break;
		case 11:
			cout << 'J';
			break;
		case 12:
			cout << 'Q';
			break;
		case 13:
			cout << 'K';
			break;
		default:
			cout << num;
			break;
		}
	}
};

struct _PLAYER
{
	string name;
	vector<_CARD> deck;
	int point = 0;
	int money = 10000;
};

int Bj_Random_num();
void Draw_card_and_print(_CARD card, _PLAYER& player); // 카드뽑고 출력
void Init_card(_CARD* cards, int MAX_CARD); // 카드초기화
void Shuffle_card(_CARD* cards); // 카드섞기
void Calc_point_and_money(_PLAYER* players, _PLAYER& dealer, int player_max, int money); // 점수 계산 후 돈분배
void Clear_player_and_dealer(_PLAYER* players, _PLAYER& dealer, int player_max); // 플레이어, 딜러 카드초기화
void Play_blackjack();