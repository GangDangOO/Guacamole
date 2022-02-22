#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

enum HAND {
	MUK,
	CHI,
	BA
};

class Player {
public:
	string	name;
	bool	b_attacker = false;
	int		hand; // MUK = 0, CHI = 1, BA = 2
	bool	b_alive = true;

	void	Print();
	void	Init_Hand();
	void	Init_Hand(int hand);
};

void play_Muk_Chi_Ba();