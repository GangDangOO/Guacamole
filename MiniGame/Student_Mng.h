#pragma once
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

enum GENDER {
	MALE,
	FEMALE
};

struct _Student {
	int num;
	string name;
	int age;
	bool gender;
};


class Student_Mng {
public:
	vector<_Student> mng;
	void Show_Student(_Student student);
	void Add_Student();
	void Delete_Student();
};

void Start_Mng();

