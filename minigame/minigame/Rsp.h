#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

enum HAND_DIRECT {
	LEFT,
	RIGHT
};

enum RSP {
	SCISSORS = 1,
	ROCK,
	PAPER
};

struct _Player {
	string	name;
	int		left_hand;
	int		right_hand;
	int		choice;
	int		win = 3;
	bool	b_alive = true;
};

class Rsp {
public:
	_Player player;
	
	void Init_Name(string name);
	void Init_Hand();
	void Init_Hand(int hand, int input);
	void Choice_Hand();
	void Choice_Hand(int hand);
	void Show(bool second = false);
};

void Play_Rsp();
