// A는 1 고정이고 J, Q, K는 10으로 고정됨
// 딜러는 17이상이 될때까지 계속 뽑아야함
#include <iostream>
#include <string>
#include <random>
#include <vector>

using namespace std;

const int MAX_CARD = 52;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(0, MAX_CARD - 1);

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

void Draw_card_and_print(_CARD card, _PLAYER &player);
void Init_card(_CARD* cards, int MAX_CARD);
void Shuffle_card(_CARD* cards);


int main() {
	int input;
	_CARD cards[MAX_CARD];
	_PLAYER player;
	_PLAYER dealer;
	player.name = "Player 1";
	dealer.name = "Dealer";
	Init_card(cards, MAX_CARD);
	while (true) {
		Shuffle_card(cards);
		int i = 0;
		for (; i < MAX_CARD; i++) {
			Draw_card_and_print(cards[i], player);
			if (player.point > 21) {
				cout << "꽝" << endl;
				player.point = 0;
				break;
			}
			cout << "카드뽑기 1.예 2.아니오";
			cin >> input;
			if (input == 2) break;
		}
		for (; i < MAX_CARD; i++) {
			Draw_card_and_print(cards[i], dealer);
			if (player.point > 21) {
				cout << "꽝" << endl;
				dealer.point = 0;
				break;
			}
			if (dealer.point > 17) break;
		}
		player.money -= 1000;
		if (player.point == dealer.point) {
			cout << "무승부" << endl << "현재소지금 : " << player.money << endl;
		} 
		else if (player.point > dealer.point) {
			player.money += 2000;
			cout << "플레이어 승리! 소지금 + 2000" << endl << "현재소지금 : " << player.money << endl;
		}
		else {
			cout << "플레이어 패배 소지금 - 1000 " << endl << " 현재소지금 : " << player.money << endl;
		}
		player.deck.clear();
		dealer.deck.clear();
	}
	return 0;
}

void Draw_card_and_print(_CARD card, _PLAYER &player) {
	player.point = 0;
	player.deck.push_back(card);
	cout << player.name << ' ';
	for (int i = 0; i < player.deck.size(); i++) {
		player.deck[i].Print();
		cout << '\t';
		if (player.deck[i].num > 10) player.point += 10;
		else player.point += player.deck[i].num;
	}
	cout << player.point << endl;
}

void Init_card(_CARD* cards, int MAX_CARD) {
	for (int i = 0; i < MAX_CARD / 4; i++) {
		cards[i].shape = "♠";
		cards[i].num = i + 1;
		cards[i + 13].shape = "♥";
		cards[i + 13].num = i + 1;
		cards[i + 26].shape = "♣";
		cards[i + 26].num = i + 1;
		cards[i + 39].shape = "◈";
		cards[i + 39].num = i + 1;
	}

}

void Shuffle_card(_CARD* cards) {
	for (int i = 0; i < 200; i++) {
		_CARD temp;
		int rd1 = dis(gen);
		int rd2 = dis(gen);
		temp = cards[rd1];
		cards[rd1] = cards[rd2];
		cards[rd2] = temp;
	}
}