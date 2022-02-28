#include "Shop.h"

void Shop::Open_Shop() {
	Player player;
	Item* items[11];
	items[0] = new Item("잡템1", 500);
	items[1] = new Item("잡템2", 1000);
	items[2] = new Item("잡템3", 1500);
	items[3] = new Item("잡템4", 2000);
	items[4] = new Weapon("검1", 10000, 1);
	items[5] = new Weapon("검2", 15000, 2);
	items[6] = new Weapon("검3", 20000, 3);
	items[7] = new Armor("방1", 10000, 1);
	items[8] = new Armor("방2", 15000, 2);
	items[9] = new Armor("방3", 20000, 3);
	items[10] = new Item("비싼것", 5000000);

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
	cout << "구매할 물품을 선택하여주세요." << endl;
	cout << "==========================================" << endl;
	for (int i = 0; i < 11; i++) {
		cout << i + 1 << ".\t";
		items[i]->View_Item();
	}
	cout << "==========================================" << endl;
	cout << "현재 소지금 : " << player.money << endl;
	cout << "구매할 물건 번호 : ";
	cin >> input;
	if (input > 11) {
		cout << "잘못된 범위입니다." << endl;
		return;
	}
	if (items[input - 1]->price > player.money)
		cout << "소지금이 부족합니다." << endl;
	else
		player.Add_Inventory(*items[input - 1]);
}

void Shop::Sell_Item(Player &player) {
	int input, temp;
	cout << "판매할 물품을 선택하여주세요." << endl;
	cout << "판매가는 구매가의 30%로 판매됩니다." << endl;
	cout << "------------------------------------------" << endl;
	player.View_Inventory();
	cout << "판매할 물건 번호 : ";
	cin >> input;
	if (player.inventory.size() < input)
		cout << "잘못된 범위입니다." << endl;
	else
		player.Del_Inventory(input);
}