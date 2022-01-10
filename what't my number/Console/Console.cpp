#include <iostream>
using namespace std;

int main() {
	int nomber = 333;
	int life = 5;
	int answer;

	cout << "0~999 사이의 숫자를 입력하여 임의의 값과 동일한 값을 넣어보세요.\n";
	cout << "총 5번의 시도횟수가 주어집니다.\n남은시도횟수 : " << life << endl;
	while (life != 0) {
		cin >> answer;
		if (answer == nomber) {
			cout << "정답입니다.\n";
			cin >> answer;
			break;
		}
		else if (answer > nomber) cout << "입력하신 값보다 작습니다.\n";
		else if (answer < nomber) cout << "입력하신 값보다 큽니다.\n";
		life--;
		cout << "남은시도횟수 : " << life << endl;
	}

	return 0;
}