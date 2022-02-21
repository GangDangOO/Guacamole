#include "Sutda.h"
#include "BlackJack.h"
#include "RSP.h"
#include "Student_Mng.h"

int main() {
	int input;

	while (true) {
		cout << "1.블랙잭 2.섯다 3.가위바위보 4.학생관리" << endl << "입력 : ";
		cin >> input;
		switch (input)
		{
		case 1:
			Play_blackjack();
			break;
		case 2:
			Play_sutda();
			break;
		case 3:
			Play_Rsp();
			break;
		case 4:
			Start_Mng();
			break;
		default:
			cout << "다시 입력해주세요.";
			break;
		}
	}

	return 0;
}