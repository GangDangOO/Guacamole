#include <iostream>
#include <random>
#include <string>

using namespace std;

struct Card {
	string hanja;
	int month;
};

void shuffle_card(Card arr_card[]) {
	int i, n1, n2;
	Card temp;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 26);

	i = 0;
	while (i != 100) {
		n1 = dis(gen);
		n2 = dis(gen);
		temp = arr_card[n1];
		arr_card[n1] = arr_card[n2];
		arr_card[n2] = temp;
		i++;
	}
}

void init_card(Card arr_card[]) {
	int i, j;

	i = 0;
	while (i != 11) {

		arr_card[i].hanja = "피";
		arr_card[i].month = i + 1;
		i++;
	}
	j = 0;
	while (i != 22) {

		arr_card[i].hanja = "피";
		arr_card[i].month = j + 1;
		j++;
		i++;
	}
	while (i != 27) {
		arr_card[i].hanja = "광";
		switch (i)
		{
		case 22:
			arr_card[i].month = 1;
			break;
		case 23:
			arr_card[i].month = 3;
			break;
		case 24:
			arr_card[i].month = 8;
			break;
		case 25:
			arr_card[i].month = 11;
			break;
		case 26:
			arr_card[i].month = 12;
			break;
		default:
			break;
		}
		i++;
	}
}

int main() {
	int i, money_Input, type_input, money;
	Card unknown;
	Card arr_card[27];

	money = 10000;
	cout << "****************화투*****************" << endl;
	init_card(arr_card);
	shuffle_card(arr_card);

	i = 0;
	while (i != 25) {
		if (money <= 0) {
			cout << "소지금을 전부 잃으셨습니다.";
			break;
		}
		if (i != 0 && i % 5 == 0) {
			unknown = arr_card[i];
			cout << "?" << " 히든카드 : " << unknown.hanja << unknown.month << endl;
			cout << "하이 : 1, 로우 : 2, 세븐 : 3 값을 입력해주세요. : ";
			cin >> type_input;
			cout << "현재 소지금 : " << money << endl;
			cout << "배팅금을 입력해주세요. (최소 : 1000) : ";
			cin >> money_Input;
			if (money_Input < 1000 || money_Input > money) {
				cout << "잘못입력하셨습니다." << endl;
				continue;
			}
			if (unknown.month == 7) {
				if (type_input == 3) {
					cout << "맞췄습니다. +" << money_Input * 3 << " 히든카드 : " << unknown.hanja << unknown.month << endl;
					money += money_Input * 3;
				}
				else {
					cout << "틀렸습니다. -" << money_Input << " 히든카드 : " << unknown.hanja << unknown.month << endl;
					money -= money_Input;
				}
			}
			else if (unknown.month > 7) {
				if (type_input == 1) {
					cout << "맞췄습니다. +" << money_Input << " 히든카드 : " << unknown.hanja << unknown.month << endl;
					money += money_Input;
				}
				else {
					cout << "틀렸습니다. -" << money_Input << " 히든카드 : " << unknown.hanja << unknown.month << endl;
					money -= money_Input;
				}
			}
			else if (unknown.month < 7) {
				if (type_input == 2) {
					cout << "맞췄습니다. +" << money_Input << " 히든카드 : " << unknown.hanja << unknown.month << endl;
					money += money_Input;
				}
				else {
					cout << "틀렸습니다. -" << money_Input << " 히든카드 : " << unknown.hanja << unknown.month << endl;
					money -= money_Input;
				}
			}
			cout << "------------------------------------------\n";
		}
		else cout << arr_card[i].hanja << arr_card[i].month << " ";
		i++;
	}
	cout << "다시하시겠습니까? 예.1 아니요.0 : ";
	cin >> i;
	if (i == 0) return 0;
	else main();
	return 0;
}