#include "BlackJack.h"

int Bj_Random_num() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 19);

	return (dis(gen));
}

void Play_blackjack() {
	int input, player_max;
	_CARD cards[MAX_CARD];
	_PLAYER dealer;
	dealer.name = "[Dealer]";
	cout << "플레이어 인원수 : ";
	cin >> player_max;
	_PLAYER* player = new _PLAYER[player_max];
	for (int i = 0; i < player_max; i++) {
		player[i].name = "[Player ";
		player[i].name.append(to_string(i + 1));
		player[i].name.append("]");
	}
	Init_card(cards, MAX_CARD);
	while (true) {
		Shuffle_card(cards);
		int i = 0;
		for (int j = 0; j < player_max; j++) {
			Draw_card_and_print(cards[i], player[j]);
			i++;
			for (; i < MAX_CARD; i++) {
				Draw_card_and_print(cards[i], player[j]);
				if (player[j].point > 21) {
					cout << player[j].name << "버스트" << endl;
					player[j].point = 0;
					break;
				}
				cout << "카드뽑기 1.예 2.아니오" << endl << "입력 : ";
				cin >> input;
				if (input == 2) {
					i++; // 다음카드로
					break;
				}
			}
		}
		// 딜러 카드뽑기
		Draw_card_and_print(cards[i], dealer);
		i++;
		for (; i < MAX_CARD; i++) {
			if (dealer.point <= 17) {
				Draw_card_and_print(cards[i], dealer);
				if (dealer.point > 21) {
					cout << dealer.name << "버스트" << endl;
					dealer.point = 0;
					break;
				}
			}
		}
		Calc_point_and_money(player, dealer, player_max, 1000);
		Clear_player_and_dealer(player, dealer, player_max);
	}
	delete[] player;
}

void Clear_player_and_dealer(_PLAYER* players, _PLAYER& dealer, int player_max) {
	for (int i = 0; i < player_max; i++) players[i].deck.clear();
	dealer.deck.clear();
}

void Calc_point_and_money(_PLAYER* players, _PLAYER& dealer, int player_max, int money) {
	int winner_count = 0;
	for (int i = 0; i < player_max; i++) {
		players[i].money -= money;
		if (players[i].point > dealer.point)
			winner_count++;
	}
	for (int i = 0; i < player_max; i++) {
		if (players[i].point > dealer.point) {
			players[i].money += (money * player_max) / winner_count;
			cout << players[i].name << "승리 소지금 : " << players[i].money << endl;
		}
		else {
			cout << players[i].name << "패배 소지금 : " << players[i].money << endl;
		}
	}
}

void Draw_card_and_print(_CARD card, _PLAYER& player) {
	player.point = 0;
	player.deck.push_back(card);
	cout << player.name << ' ';
	for (int i = 0; i < player.deck.size(); i++) {
		player.deck[i].Print();
		cout << '\t';
		if (player.deck[i].num == 1) {
			if (11 + player.point <= 21)
				player.point += 11;
			else
				player.point += 1;
		}
		else {
			if (player.deck[i].num > 10) player.point += 10;
			else player.point += player.deck[i].num;
		}
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
		int rd1 = Bj_Random_num();
		int rd2 = Bj_Random_num();
		temp = cards[rd1];
		cards[rd1] = cards[rd2];
		cards[rd2] = temp;
	}
}