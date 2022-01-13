#include <iostream>
#include <random>
using namespace std;

int main() {
	int input, count, ball, strike;
	int Arr[3];

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(2, 9);

	Arr[0] = dis(gen);
	Arr[1] = dis(gen);
	while(Arr[0] == Arr[1]) Arr[1] = dis(gen);
	Arr[2] = dis(gen);
	while(Arr[2] == Arr[0] || Arr[2] == Arr[1]) Arr[2] = dis(gen);
	cout << "---숫자야구게임---\n\n";
	cout << "정답 : " << Arr[0] << Arr[1] << Arr[2] << endl;
	count = 0;
	while (true) {
		int i = ball = strike = 0;
		while (i != 3) {
			cin >> input;
			if (i == 0) {
				if (Arr[0] == input) strike++;
				if (Arr[1] == input) ball++;
				if (Arr[2] == input) ball++;
			}
			if (i == 1) {
				if (Arr[0] == input) ball++;
				if (Arr[1] == input) strike++;
				if (Arr[2] == input) ball++;
			}
			if (i == 2) {
				if (Arr[0] == input) ball++;
				if (Arr[1] == input) ball++;
				if (Arr[2] == input) strike++;
			}
			i++;
		}

		cout << strike << "S" << ball << "B\n--------------------------------\n";
		count++;
		if (strike == 3) {
			cout << "정답입니다! 총 " << count << "번 시도하였습니다.\n";
			break;
		}
	}
	return 0;
}