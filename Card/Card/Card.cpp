#include <iostream>
#include <random>

using namespace std;

struct card {
	int character;
	int number;
};

void show_card(card card) {
	if (card.character == 0) cout << "♠ ";
	else if (card.character == 1) cout << "◆ ";
	else if (card.character == 2) cout << "♣ ";
	else if (card.character == 3) cout << "♥ ";

	if (card.number == 11) cout << 'J' << endl;
	else if (card.number == 12) cout << 'Q' << endl;
	else if (card.number == 13) cout << 'K' << endl;
	else cout << card.number << endl;
}

int main() {
	int card[4][13] = { 0, };
	int rCard_1, rCard_2, cCard = 0;
	int money = 10000;
	int i, Ainput, Binput;
	struct card card_1;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis1(0, 3);
	uniform_int_distribution<int> dis2(0, 12);
	cout << "****************로하이세븐****************\n";
	while (cCard != 7) {
		i = 0;

		cout << "-------------------------------------------\n" << "현재 소지금 : " << money << endl;
		while (i != 6) {
			rCard_1 = dis1(gen);
			rCard_2 = dis2(gen);
			if (card[rCard_1][rCard_2] == 1) continue;
			else {
				card[rCard_1][rCard_2] = 1;
				card_1.character = rCard_1;
				card_1.number = rCard_2;
				rCard_2++;
				if (i != 5) {
					show_card(card_1);
				}
				else cout << '?' << " ";
			}
			i++;
		}
		cout << "\n[하이] = 1, [로우] = 2, [세븐] = 3 | 입력 : ";
		cin >> Ainput;
		if (Ainput > 3) {
			cout << "잘못된 입력입니다.\n";
			cCard++;
			continue;
		}
		cout << "소지금 : " << money << " (최소금액 : 500) 배당금 입력 : ";
		cin >> Binput;
		if (Binput < 500 || Binput > money) {
			cout << "잘못된 입력입니다.\n";
			cCard++;
			continue;
		}
		if (rCard_2 == 7) {
			if (Ainput == 3) {
				money += Binput * 5;
				cout << "맞췄습니다. +" << Binput * 5 << "  [히든카드] : "; show_card(card_1);
			}
			else {
				money -= Binput;
				cout << "틀렸습니다. -" << Binput << "  [히든카드] : "; show_card(card_1);
			}
		}
		else if (rCard_2 > 7) {
			if (Ainput == 1) {
				money += Binput;
				cout << "맞췄습니다. +" << Binput << "  [히든카드] : "; show_card(card_1);
			}
			else {
				money -= Binput;
				cout << "틀렸습니다. -" << Binput << "  [히든카드] : "; show_card(card_1);
			}
		}
		else if (rCard_2 < 7) {
			if (Ainput == 2) {
				money += Binput;
				cout << "맞췄습니다. +" << Binput << "  [히든카드] : "; show_card(card_1);
			}
			else {
				money -= Binput;
				cout << "틀렸습니다. -" << Binput << "  [히든카드] : "; show_card(card_1);
			}
		}
		if (money <= 0) {
			cout << "모든 소지금이 사라지셨습니다.\n";
			break;
		}
		cout << "-------------------------------------------\n";
		cCard++;
	}
	cout << "다시하기.1     끝내기.2\n";
	cin >> Ainput;
	if (Ainput == 1) main();
	else return 0;
}