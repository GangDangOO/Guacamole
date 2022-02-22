#include "Muk_Chi_Ba.h"

void play_Muk_Chi_Ba() {
	int player_size = 1;
	//cout << "플레이어 수 : ";
	//cin >> player_size;
	player_size++;
	Player* players = new Player[player_size + 1];
	for (int i = 0; i < player_size; i++) {
		if (i == 0) players[i].name = "플레이어 ";
		else players[i].name = "CPU " + to_string(i + 1) + "\t";
	}
	int input;
	int attack = -1;
	while (true) {
		players[attack].b_attacker = false;
		attack++;
		while (true) {
			if (players[attack].b_alive == false) attack++;
			else break;
		}
		if (attack >= player_size) attack = 0;
		players[attack].b_attacker = true;
		cout << "무엇을 내시겠습니까 (0.묵 1.찌 2.빠) : ";
		cin >> input;
		for (int i = 0; i < player_size; i++) {
			if (i == 0) players[i].Init_Hand(input);
			else players[i].Init_Hand();
		}
		for (int i = 0; i < player_size; i++) {
			players[i].Print();
		}
		for (int i = 0; i < player_size; i++) {
			if (players[i].b_attacker == false &&
				players[i].hand == players[attack].hand &&
				players[i].b_alive == true) {
				cout << players[i].name << "패배" << endl;
				players[i].b_alive = false;
			}
		}
		if (players[0].b_alive == false) {
			cout << "게임 끝 (1.다시하기 2.종료)";
			cin >> input;
			if (input == 1) play_Muk_Chi_Ba();
			else exit(0);
		}
		int count = 0;
		for (int i = 0; i < player_size; i++) {
			if (players[i].b_alive == true) count++;
		}
		if (count == 1) {
			for (int i = 0; i < player_size; i++) {
				if (players[i].b_alive == true) {
					cout << players[i].name << "승리하셨습니다." << endl;
					cout << "게임 끝 (1.다시하기 2.종료)";
					cin >> input;
					if (input == 1) play_Muk_Chi_Ba();
					else exit(0);
				}
			}
		}
	}
}

void Player::Print() {
	if (b_alive == true) {
		cout << name << '\t';
		switch (hand)
		{
		case MUK:
			cout << "묵" << '\t';
			break;
		case CHI:
			cout << "찌" << '\t';
			break;
		case BA:
			cout << "빠" << '\t';
			break;
		default:
			cout << "???" << '\t';
			break;
		}
		if (b_attacker == true) cout << "공격자" << '\t';
		cout << endl;
	}
}

void Player::Init_Hand() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(MUK, BA); // 0 ~ 2;

	hand = dis(gen);
}

void Player::Init_Hand(int type) {
	hand = type;
}