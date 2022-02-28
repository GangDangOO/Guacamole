#pragma once
#include "Item.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
public:
	string name = "플레이어";
	int money = 1000000;
	vector<Item> inventory;

	void View_Inventory();
	void Exchange_Money(int input);
	void Add_Inventory(Item item);
	void Add_Inventory(Item item, int amount);
	void Del_Inventory(int input);
	void Del_Inventory(int input, int amount);
};

