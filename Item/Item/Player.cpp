#include "Player.h"

void Player::View_Inventory() {
	cout << name << " �������� ��ǰ" << endl;
	cout << "==========================================" << endl;
	for (int i = 0; i < inventory.size(); i++) {
		cout << i + 1 << ".\t";
		inventory[i].View_Item();
	}
	cout << "==========================================" << endl;
	cout << "���� ������ : " << money << endl;
}

void Player::Exchange_Money(int input) {
	money += input;
}

void Player::Add_Inventory(Item item) {
	Exchange_Money(-item.price);
	inventory.push_back(item);
	cout << " ���� �Ϸ�" << endl;
}

void Player::Del_Inventory(int input) {
	Exchange_Money((int)(inventory[input - 1].price * 0.3f));
	inventory.erase(inventory.begin() + input - 1);
	cout << "�Ǹ� �Ϸ�" << endl;
}