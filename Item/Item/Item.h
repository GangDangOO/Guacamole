#pragma once
#include <iostream>
#include <string>

using namespace std;

class Item {
public:
	string name;
	int price;
	int amount;
	Item();
	Item(string name, int price);
	Item(string name, int price, int amount);
	virtual ~Item();
	virtual void View_Item();
};

class Weapon : public Item {
public:
	int atk;

	Weapon();
	Weapon(string name, int price, int atk);
	Weapon(string name, int price, int atk, int amount);
	~Weapon();
	void View_Item() override;
};

class Armor : public Item {
public:
	int def;

	Armor();
	Armor(string name, int price, int def);
	Armor(string name, int price, int def, int amount);
	~Armor();
	void View_Item() override;
};