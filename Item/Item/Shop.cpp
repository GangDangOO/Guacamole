#include "Shop.h"

void Shop::Open_Shop() {
	Player player;
	vector<Item> items;
	items.push_back(Item("잡템1", 500, 5));
	items.push_back(Item("잡템2", 1000, 5));
	items.push_back(Item("잡템3", 1500, 5));
	items.push_back(Item("잡템4", 2000, 5));
	items.push_back(Weapon("검1", 10000, 1, 1));
	items.push_back(Weapon("검2", 15000, 2, 1));
	items.push_back(Weapon("검3", 20000, 3, 1));
	items.push_back(Armor("방1", 10000, 1, 1));
	items.push_back(Armor("방2", 15000, 2, 1));
	items.push_back(Armor("방3", 20000, 3, 1));
	items.push_back(Item("비싼것", 5000000, 1));

	int input;
	while (true) {
		cout << "상점" << endl;
		cout << "1.구매 2.판매 3.인벤토리 확인 4.종료" << endl << "입력 : ";
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
	cout << "구매할 물품을 선택하여주세요." << endl;
	cout << "==========================================" << endl;
	for (int i = 0; i < items.size(); i++) {
		cout << i + 1 << ".\t";
		items[i].View_Item();
	}
	cout << "==========================================" << endl;
	cout << "현재 소지금 : " << player.money << endl;
	cout << "구매할 물건 번호 : ";
	cin >> input_index;
	if (input_index > items.size()) {
		cout << "잘못된 범위입니다." << endl;
		return;
	}
	if (items[input_index - 1].price > player.money)
		cout << "소지금이 부족합니다." << endl;
	else {
		if (items[input_index - 1].amount > 1) {
			cout << "구매 개수 : ";
			cin >> input_amount;
			if (input_amount > items[input_index - 1].amount) {
				cout << "잘못된 범위입니다." << endl;
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
	cout << "판매할 물품을 선택하여주세요." << endl;
	cout << "판매가는 구매가의 30%로 판매됩니다." << endl;
	cout << "------------------------------------------" << endl;
	player.View_Inventory();
	cout << "판매할 물건 번호 : ";
	cin >> input_index;
	if (player.inventory.size() < input_index)
		cout << "잘못된 범위입니다." << endl;
	else {
		if (player.inventory[input_index - 1].amount > 1) {
			cout << "판매 개수 : ";
			cin >> input_amount;
			if (input_amount > player.inventory[input_index - 1].amount) {
				cout << "잘못된 범위입니다." << endl;
				return;
			}
			else
				player.Del_Inventory(input_index, input_amount);
		}
		else
			player.Del_Inventory(input_index);
	}
}