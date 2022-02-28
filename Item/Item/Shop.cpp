#include "Shop.h"

void Shop::Open_Shop() {
	Player player;
	Item* items[11];
	items[0] = new Item("����1", 500);
	items[1] = new Item("����2", 1000);
	items[2] = new Item("����3", 1500);
	items[3] = new Item("����4", 2000);
	items[4] = new Weapon("��1", 10000, 1);
	items[5] = new Weapon("��2", 15000, 2);
	items[6] = new Weapon("��3", 20000, 3);
	items[7] = new Armor("��1", 10000, 1);
	items[8] = new Armor("��2", 15000, 2);
	items[9] = new Armor("��3", 20000, 3);
	items[10] = new Item("��Ѱ�", 5000000);

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
			for (int i = 0; i < 11; i++) {
				delete items[i];
			}
			return;
		default:
			break;
		}
	}
}

void Shop::Buy_Item(Item** items, Player &player) {
	int input, temp;
	cout << "������ ��ǰ�� �����Ͽ��ּ���." << endl;
	cout << "==========================================" << endl;
	for (int i = 0; i < 11; i++) {
		cout << i + 1 << ".\t";
		items[i]->View_Item();
	}
	cout << "==========================================" << endl;
	cout << "���� ������ : " << player.money << endl;
	cout << "������ ���� ��ȣ : ";
	cin >> input;
	if (input > 11) {
		cout << "�߸��� �����Դϴ�." << endl;
		return;
	}
	if (items[input - 1]->price > player.money)
		cout << "�������� �����մϴ�." << endl;
	else
		player.Add_Inventory(*items[input - 1]);
}

void Shop::Sell_Item(Player &player) {
	int input, temp;
	cout << "�Ǹ��� ��ǰ�� �����Ͽ��ּ���." << endl;
	cout << "�ǸŰ��� ���Ű��� 30%�� �Ǹŵ˴ϴ�." << endl;
	cout << "------------------------------------------" << endl;
	player.View_Inventory();
	cout << "�Ǹ��� ���� ��ȣ : ";
	cin >> input;
	if (player.inventory.size() < input)
		cout << "�߸��� �����Դϴ�." << endl;
	else
		player.Del_Inventory(input);
}