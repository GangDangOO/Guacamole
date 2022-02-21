#include "Sutda.h"


int St_Random_num() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 19);

	return (dis(gen));
}

void Play_sutda() {
	int player_size, input = 0;
	_jokbo cards[20];
	cout << "ÇÃ·¹ÀÌ¾î ¼ö : ";
	cin >> player_size;
	_Player_Sutda* players = new _Player_Sutda[player_size];
	for (int i = 0; i < player_size; i++) {
		players[i].name = "ÇÃ·¹ÀÌ¾î";
		players[i].name.append(to_string(i + 1));
	}
	while (input != 2) {
		Init_and_shuffle(cards);
		Draw_card(players, cards, player_size);
		Calc_jokbo(players, player_size);
		Calc_money(players, player_size);
		Print_state(players, player_size);
		cout << "°ÔÀÓ¼ÓÇà 1.¿¹ 2.¾Æ´Ï¿À" << endl << "ÀÔ·Â : ";
		cin >> input;
	}
	delete[] players;
}

void Print_state(_Player_Sutda* player, int player_size) {
	for (int i = 0; i < player_size; i++) {
		cout << player[i].name << '\t'
			<< player[i].card[0].month << player[i].card[0].paint << '\t'
			<< player[i].card[1].month << player[i].card[1].paint << '\t'
			<< player[i].money << '\t' << "Á¡¼ö : " << player[i].point << '\t';
		switch (player[i].point)
		{
		case KK:
			cout << "¸ÁÅë" << endl;
			break;
		case KK + 1:
		case KK + 2:
		case KK + 3:
		case KK + 4:
		case KK + 5:
		case KK + 6:
		case KK + 7:
		case KK + 8:
			cout << player[i].point << "²ý" << endl;
			break;
		case KK + 9:
			cout << "°©¿À" << endl;
			break;
		case MJ:
			cout << "¼¼·ú" << endl;
			break;
		case MJ + 1:
			cout << "Àå»ç" << endl;
			break;
		case MJ + 2:
			cout << "Àå»æ" << endl;
			break;
		case MJ + 3:
			cout << "±¸»æ" << endl;
			break;
		case MJ + 4:
			cout << "µ¶»ç" << endl;
			break;
		case MJ + 5:
			cout << "¾Ë¸®" << endl;
			break;
		case DD:
		case DD + 1:
		case DD + 2:
		case DD + 3:
		case DD + 4:
		case DD + 5:
		case DD + 6:
		case DD + 7:
		case DD + 8:
			cout << player[i].point - 16 << "¶¯" << endl;
			break;
		case DD + 9:
			cout << "Àå¶¯" << endl;
			break;
		case KD:
			cout << "ÀÏ»ï±¤¶¯" << endl;
			break;
		case KD + 1:
			cout << "ÀÏÆÈ±¤¶¯" << endl;
			break;
		case KD + 2:
			cout << "»ïÆÈ±¤¶¯" << endl;
			break;
		default:
			break;
		}
	}
}

void Calc_money(_Player_Sutda* player, int player_size) {
	int max = 0;
	int count = 0;
	for (int i = 0; i < player_size; i++) {
		player[i].money -= 500;
		if (player[i].point > player[max].point) max = i;
	}
	for (int i = 0; i < player_size; i++) {
		if (player[i].point == player[max].point) count++;
	}
	for (int i = 0; i < player_size; i++) {
		if (player[i].point == player[max].point) player[i].money += (500 * player_size) / count;
	}
}

void Calc_jokbo(_Player_Sutda* player, int player_size) {
	for (int i = 0; i < player_size; i++) {
		if ((player[i].card[0].month == 3 && player[i].card[0].paint == "±¤") &&
			(player[i].card[1].month == 8 && player[i].card[1].paint == "±¤") ||
			(player[i].card[0].month == 8 && player[i].card[0].paint == "±¤") &&
			(player[i].card[1].month == 3 && player[i].card[1].paint == "±¤"))
			player[i].point = KD + 2;
		else if ((player[i].card[0].month == 1 && player[i].card[0].paint == "±¤") &&
			(player[i].card[1].month == 8 && player[i].card[1].paint == "±¤") ||
			(player[i].card[0].month == 8 && player[i].card[0].paint == "±¤") &&
			(player[i].card[1].month == 1 && player[i].card[1].paint == "±¤"))
			player[i].point = KD + 1;
		else if ((player[i].card[0].month == 1 && player[i].card[0].paint == "±¤") &&
			(player[i].card[1].month == 3 && player[i].card[1].paint == "±¤") ||
			(player[i].card[0].month == 3 && player[i].card[0].paint == "±¤") &&
			(player[i].card[1].month == 1 && player[i].card[1].paint == "±¤"))
			player[i].point = KD;
		else if (player[i].card[0].month == player[i].card[1].month)
			player[i].point = DD + player[i].card[0].month - 1;
		else if (player[i].card[0].month == 2 && player[i].card[1].month == 1 ||
			player[i].card[0].month == 1 && player[i].card[1].month == 2)
			player[i].point = MJ + 5;
		else if (player[i].card[0].month == 4 && player[i].card[1].month == 1 ||
			player[i].card[0].month == 1 && player[i].card[1].month == 4)
			player[i].point = MJ + 4;
		else if (player[i].card[0].month == 9 && player[i].card[1].month == 1 ||
			player[i].card[0].month == 1 && player[i].card[1].month == 9)
			player[i].point = MJ + 3;
		else if (player[i].card[0].month == 10 && player[i].card[1].month == 1 ||
			player[i].card[0].month == 1 && player[i].card[1].month == 10)
			player[i].point = MJ + 2;
		else if (player[i].card[0].month == 10 && player[i].card[1].month == 4 ||
			player[i].card[0].month == 4 && player[i].card[1].month == 10)
			player[i].point = MJ + 1;
		else if (player[i].card[0].month == 6 && player[i].card[1].month == 4 ||
			player[i].card[0].month == 4 && player[i].card[1].month == 6)
			player[i].point = MJ;
		else
		{
			player[i].point = (player[i].card[0].month + player[i].card[1].month) % 10;
		}
	}
}

void Init_and_shuffle(_jokbo* cards) {
	for (int i = 0; i < 20; i++) {
		cards[i].month = i + 1;
		if (i == 1 || i == 3 || i == 8) {
			cards[i].paint = "±¤";
		}
		else {
			cards[i].paint = "ÇÇ";
		}
		if (i > 9) {
			cards[i].month -= 10;
		}
	}
	for (int i = 0; i < 200; i++) {
		_jokbo temp;
		int num, num2;
		num = St_Random_num();
		num2 = St_Random_num();
		temp = cards[num2];
		cards[num2] = cards[num];
		cards[num] = temp;
	}
}

void Draw_card(_Player_Sutda* player, _jokbo* cards, int player_size) {
	for (int i = 0; i < player_size; i++) {
		player[i].card[0] = cards[i];
		player[i].card[1] = cards[i + 10];
	}
}