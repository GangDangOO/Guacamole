#pragma once
#include "Item.h"
#include "Player.h"

using namespace std;

class Shop
{
public:
	void Open_Shop();
	void Buy_Item(vector<Item> &items, Player &player);
	void Sell_Item(Player &player);
};

