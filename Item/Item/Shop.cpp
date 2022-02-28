#include "Shop.h"

void Shop::Open_Shop() {
	Player player;
	vector<Item> items;
	items.push_back(Item("����1", 500, 5));
	items.push_back(Item("����2", 1000, 5));
	items.push_back(Item("����3", 1500, 5));
	items.push_back(Item("����4", 2000, 5));
	items.push_back(Weapon("��1", 10000, 1, 1));
	items.push_back(Weapon("��2", 15000, 2, 1));
	items.push_back(Weapon("��3", 20000, 3, 1));
	items.push_back(Armor("��1", 10000, 1, 1));
	items.push_back(Armor("��2", 15000, 2, 1));
	items.push_back(Armor("��3", 20000, 3, 1));
	items.push_back(Item("��Ѱ�", 5000000, 1));

	int input;
	while (true) {
		cout << "����" << endl;
		cout << "1.���� 2.�Ǹ� 3.�κ��丮 Ȯ�� 4.����" << endl << "�Է� : ";
		cin >> input;
		switch (input)
		{
		case 1:
			Buy_Item(items, player);
			break;
		case 2:
			Sell_Item(player);
			break;
		case 3: // i
			player.View_Inventory();
			break;
		case 4:
			items.clear();
			return;
		default:
			break;
		}
	}
}

void Shop::Buy_Item(vector<Item> &items, Player &player) {
	int input_index, input_amount;
	cout << "������ ��ǰ�� �����Ͽ��ּ���." << endl;
	cout << "==========================================" << endl;
	for (int i = 0; i < items.size(); i++) {
		cout << i + 1 << ".\t";
		items[i].View_Item();
	}
	cout << "==========================================" << endl;
	cout << "���� ������ : " << player.money << endl;
	cout << "������ ���� ��ȣ : ";
	cin >> input_index;
	if (input_index > items.size()) {
		cout << "�߸��� �����Դϴ�." << endl;
		return;
	}
	if (items[input_index - 1].price > player.money)
		cout << "�������� �����մϴ�." << endl;
	else {
		if (items[input_index - 1].amount > 1) {
			cout << "���� ���� : ";
			cin >> input_amount;
			if (input_amount > items[input_index - 1].amount) {
				cout << "�߸��� �����Դϴ�." << endl;
				return;
			}
			else {
				player.Add_Inventory(items[input_index - 1], input_amount);
				items[input_index - 1].amount -= input_amount;
				if (items[input_index - 1].amount <= 0)
					items.erase(items.begin() + input_index - 1);
			}
		}
		else {
			player.Add_Inventory(items[input_index - 1]);
			items.erase(items.begin() + input_index - 1);
		}
	}
}

void Shop::Sell_Item(Player &player) {
	int input_index, input_amount;
	cout << "�Ǹ��� ��ǰ�� �����Ͽ��ּ���." << endl;
	cout << "�ǸŰ��� ���Ű��� 30%�� �Ǹŵ˴ϴ�." << endl;
	cout << "------------------------------------------" << endl;
	player.View_Inventory();
	cout << "�Ǹ��� ���� ��ȣ : ";
	cin >> input_index;
	if (player.inventory.size() < input_index)
		cout << "�߸��� �����Դϴ�." << endl;
	else {
		if (player.inventory[input_index - 1].amount > 1) {
			cout << "�Ǹ� ���� : ";
			cin >> input_amount;
			if (input_amount > player.inventory[input_index - 1].amount) {
				cout << "�߸��� �����Դϴ�." << endl;
				return;
			}
			else
				player.Del_Inventory(input_index, input_amount);
		}
		else
			player.Del_Inventory(input_index);
	}
}