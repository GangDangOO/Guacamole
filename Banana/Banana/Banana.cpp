#include <iostream>
#include <random>

using namespace std;
const int Max_card = 52;
int draw_card[3];

int main() {
	int bet, count, i;
	int card[Max_card] = { 0, };
	int money = 10000;
	bool bTry, bEnd = false;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, Max_card);

	count = 0;
	while (!bEnd) {
		cout << "현재 소지금 : " << money << endl;
		i = 0;
		while (i != 3) {
			draw_card[i] = dis(gen);
			if (card[draw_card[i]] == 1) i--;
			else {
				card[draw_card[i]] = 1;
				if (draw_card[i] > 13 && draw_card[i] < 27) draw_card[i] -= 13;
				else if (draw_card[i] > 26 && draw_card[i] < 40) draw_card[i] -= 26;
				else if (draw_card[i] > 39 && draw_card[i] <= 52) draw_card[i] -= 39;
			}
			i++;
		}
		cout << draw_card[0] << endl;
		cout << draw_card[1] << endl;
		cout << "?" << endl;
		cin >> bet;
		if ((draw_card[0] < draw_card[2] && draw_card[1] > draw_card[2]) || (draw_card[1] < draw_card[2] && draw_card[0] > draw_card[2])) {
			cout << "승리했습니다.\n-----------------------------------\n";
			money += bet;
		}
		else {
			cout << "패배했습니다.\n-----------------------------------\n";
			money -= bet;
		}
		count++;
		
		if (money <= 0 || count == 13) {
			bEnd = true;
		}
	}
	cout << "다시 하시겠습니까? 다시.1 종료.0\n";
	cin >> bTry;
	if (bTry != true) return 0;
	else {
		main();
	}
	return 0;
}