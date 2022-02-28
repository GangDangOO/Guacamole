#include "Item.h"

Item::Item() {
	
}

Item::Item(string Name, int Price) :name(Name), price(Price), amount(1) {

}

Item::Item(string Name, int Price, int Amount) :name(Name), price(Price), amount(Amount) {
	
}

Weapon::Weapon() {
	atk = 0;
}

Weapon::Weapon(string Name, int Price, int Atk) : Item(Name, Price, 1), atk(Atk) {

}

Weapon::Weapon(string Name, int Price, int Atk, int Amount) : Item(Name, Price, Amount), atk(Atk) {
	
}

Armor::Armor() {
	def = 0;
}

Armor::Armor(string Name, int Price, int Def) : Item(Name, Price, 1), def(Def) {

}

Armor::Armor(string Name, int Price, int Def, int Amount) : Item(Name, Price, Amount), def(Def) {
	
}
Item::~Item() {
	
}

Weapon::~Weapon() {
	
}

Armor::~Armor() {
	
}

void Item::View_Item() {
	cout << "종류 : 기타\t이름 : " << name << "\t가격 : " << price << "\t개수 : " << amount << endl;
}

void Weapon::View_Item() {
	cout << "종류 : 무기\t이름 : " << name << "\t가격 : " << price << "\t공격력 : " << atk << "\t개수 : " << amount << endl;
}

void Armor::View_Item() {
	cout << "종류 : 방어구\t이름 : " << name << "\t가격 : " << price << "\t방어력 : " << def << "\t개수 : " << amount << endl;
}