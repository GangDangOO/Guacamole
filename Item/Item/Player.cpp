#include "Player.h"

void Player::View_Inventory() {
	cout << name << " 소유중인 물품" << endl;
	cout << "==========================================" << endl;
	for (int i = 0; i < inventory.size(); i++) {
		cout << i + 1 << ".\t";
		inventory[i].View_Item();
	}
	cout << "==========================================" << endl;
	cout << "현재 소지금 : " << money << endl;
}

void Player::Exchange_Money(int input) {
	money += input;
}

void Player::Add_Inventory(Item item) {
	Exchange_Money(-item.price);
	inventory.push_back(item);
	cout << " 구매 완료" << endl;
}

void Player::Del_Inventory(int input) {
	Exchange_Money((int)(inventory[input - 1].price * 0.3f));
	inventory.erase(inventory.begin() + input - 1);
	cout << "판매 완료" << endl;
}