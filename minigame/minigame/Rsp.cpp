#include "Rsp.h"

void Play_Rsp() {
	int input;
	bool r, s, p = false;

	Rsp player;
	vector<Rsp> cpus;

	player.Init_Name("�÷��̾�");
	cout << "Cpu�� ���� �Է��ϼ���. : ";
	cin >> input;
	for (int i = 0; i < input; i++) {
		Rsp temp;
		string str;
		str = "CPU ";
		str.append(to_string(i + 1));
		temp.Init_Name(str + "\t");
		cpus.push_back(temp);
	}

	while (true) {
		cout << "�÷��̾� �޼� �Է�(1.���� 2.���� 3.��) : ";
		cin >> input;
		player.Init_Hand(LEFT, input);
		cout << "�÷��̾� ������ �Է�(1.���� 2.���� 3.��) : ";
		cin >> input;
		player.Init_Hand(RIGHT, input);
		player.player.win = 3;
		player.Show();
		for (int i = 0; i < cpus.size(); i++) {
			cpus[i].Init_Hand();
			cpus[i].player.win = 3;
			cpus[i].Show();
		}

		cout << "���� ���� �Է��ϼ���.(1.�޼� 2.������) : ";
		cin >> input;
		player.Choice_Hand(input);
		for (int i = 0; i < cpus.size(); i++) cpus[i].Choice_Hand();
		r = s = p = false;
		switch (player.player.choice) {
		case SCISSORS:
			s = true;
			break;
		case ROCK:
			r = true;
			break;
		case PAPER:
			p = true;
			break;
		default:
			break;
		}
		for (int i = 0; i < cpus.size(); i++) {
			switch (cpus[i].player.choice) {
			case SCISSORS:
				s = true;
				break;
			case ROCK:
				r = true;
				break;
			case PAPER:
				p = true;
				break;
			default:
				break;
			}
		}
		if ((r == true && s == true) && p == true) {
			player.Show(true);
			for (int i = 0; i < cpus.size(); i++) cpus[i].Show(true);
			cout << "�ºΰ� �������� �ʾҽ��ϴ�." << endl;
			continue;
		}
		else {
			for (int i = 0; i < cpus.size(); i++) {
				if (cpus[i].player.choice == ROCK &&
					player.player.choice == SCISSORS) {
					cpus[i].player.win = 1;
					player.player.win = 2;
				}
				else if (cpus[i].player.choice == SCISSORS &&
					player.player.choice == PAPER) {
					cpus[i].player.win = 1;
					player.player.win = 2;
				}
				else if (cpus[i].player.choice == PAPER &&
					player.player.choice == ROCK) {
					cpus[i].player.win = 1;
					player.player.win = 2;
				}
				else if(cpus[i].player.choice != player.player.choice) {
					cpus[i].player.win = 2;
					player.player.win = 1;
				}
			}
			for (int i = 0; i < cpus.size(); i++) {
				if (cpus[i].player.choice == player.player.choice)
					cpus[i].player.win = player.player.win;
			}
			player.Show(true);
			for (int i = 0; i < cpus.size(); i++) cpus[i].Show(true);
			if (player.player.win == 2) {
				cout << "�й��ϼ̽��ϴ�." << endl;
				cpus.clear();
				break;
			}
			for (int i = 0; i < cpus.size(); i++) {
				if (cpus[i].player.win == 2) {
					cpus.erase(cpus.begin() + i);
					i = -1;
				}
			}
			if (cpus.size() == 0) {
				cout << "�¸��ϼ̽��ϴ�." << endl;
				break;
			}
		}	
	}
}

void Rsp::Init_Name(string name) {
	player.name = name;
}

void Rsp::Init_Hand() {
	if (player.b_alive == true) {
		int temp;

		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<int> dis(SCISSORS, PAPER);

		player.left_hand = dis(gen);
		while (true) {
			temp = dis(gen);
			if (temp != player.left_hand) {
				player.right_hand = temp;
				break;
			}
			else
				temp = dis(gen);
		}
	}
}

void Rsp::Init_Hand(int hand, int input) {
	if (hand == LEFT)
		player.left_hand = input;
	else
		player.right_hand = input;
}

void Rsp::Choice_Hand() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(LEFT, RIGHT);

	if (dis(gen) == LEFT)
		player.choice = player.left_hand;
	else
		player.choice = player.right_hand;
}

void Rsp::Choice_Hand(int hand) {
	if (hand == LEFT)
		player.choice = player.left_hand;
	else
		player.choice = player.right_hand;
}

void Rsp::Show(bool second) {
	if (player.b_alive == true) {
		if (second == false) {
			cout << player.name << '\t';
			switch (player.left_hand)
			{
			case 1:
				cout << "����\t";
				break;
			case 2:
				cout << "����\t";
				break;
			case 3:
				cout << "��\t";
				break;
			default:
				break;
			}
			switch (player.right_hand)
			{
			case 1:
				cout << "����\t";
				break;
			case 2:
				cout << "����\t";
				break;
			case 3:
				cout << "��\t";
				break;
			default:
				break;
			}
			cout << endl;
		}
		else {
			cout << player.name << '\t';
			switch (player.choice)
			{
			case 1:
				cout << "����\t";
				break;
			case 2:
				cout << "����\t";
				break;
			case 3:
				cout << "��\t";
				break;
			default:
				break;
			}
			switch (player.win)
			{
			case 1:
				cout << "�¸�";
				break;
			case 2:
				cout << "�й�";
				break;
			case 3:
				cout << "���º�";
				break;
			default:
				break;
			}
			cout << endl;
		}
	}
}