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
	item.amount = 1;
	Exchange_Money(-item.price);
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i].name == item.name) {
			inventory[i].amount++;
			return;
		}
	}
	inventory.push_back(item);

	cout << " 구매 완료" << endl;
}

void Player::Add_Inventory(Item item, int amount) {
	Exchange_Money(-item.price * amount);
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i].name == item.name) {
			inventory[i].amount += amount;
			return;
		}
	}
	item.amount = amount;
	inventory.push_back(item);
	cout << " 구매 완료" << endl;
}

void Player::Del_Inventory(int input) {
	Exchange_Money((int)(inventory[input - 1].price * 0.3f));
	inventory[input - 1].amount--;
	if (inventory[input - 1].amount <= 0)
		inventory.erase(inventory.begin() + input - 1);
	cout << "판매 완료" << endl;
}

void Player::Del_Inventory(int input, int amount) {
	Exchange_Money((int)((inventory[input - 1].price * 0.3f) * amount));
	inventory[input - 1].amount -= amount;
	if (inventory[input - 1].amount <= 0)
		inventory.erase(inventory.begin() + input - 1);
	cout << "판매 완료" << endl;
}