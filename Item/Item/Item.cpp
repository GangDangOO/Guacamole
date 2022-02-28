#include "Item.h"

Item::Item() {
	// cout << "생성자" << endl;
}

Item::Item(string Name, int Price) :name(Name), price(Price) {
	// cout << "아이템 생성됨" << endl;
}

Weapon::Weapon() {
	atk = 0;
}

Weapon::Weapon(string Name, int Price, int Atk) : Item(Name, Price), atk(Atk) {
	// cout << "무기 생성됨" << endl;
}

Armor::Armor() {
	def = 0;
}

Armor::Armor(string Name, int Price, int Def) : Item(Name, Price), def(Def) {
	// cout << "방어구 생성됨" << endl;
}
Item::~Item() {
	// cout << name << " 소멸됨" << endl;
}

Weapon::~Weapon() {
	// cout << name << " 소멸됨" << endl;
}

Armor::~Armor() {
	// cout << name << " 소멸됨" << endl;
}

void Item::View_Item() {
	cout << "종류 : 기타\t이름 : " << name << "\t가격 : " << price << endl;
}

void Weapon::View_Item() {
	cout << "종류 : 무기\t이름 : " << name << "\t가격 : " << price << "\t공격력 : " << atk << endl;
}

void Armor::View_Item() {
	cout << "종류 : 방어구\t이름 : " << name << "\t가격 : " << price << "\t방어력 : " << def << endl;
}