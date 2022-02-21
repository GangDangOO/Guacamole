#include "Student_Mng.h"

void Start_Mng() {
	Student_Mng std_mng;
	int input;
	while (true) {
		cout << "�л����" << endl;
		for (int i = 0; i < std_mng.mng.size(); i++) {
			std_mng.Show_Student(std_mng.mng[i]);
		}
		cout << "=====================================\n";
		cout << "1.�л��߰� 2.�л����� : ";
		cin >> input;
		switch (input) {
		case 1:
			std_mng.Add_Student();
			break;
		case 2:
			std_mng.Delete_Student();
			break;
		default:
			cout << "�߸��Է��ϼ̽��ϴ�." << endl;
			break;
		}
	}

}

void Student_Mng::Add_Student() {
	_Student temp;

	temp.num = (mng.size() + 1);
	cout << "�л��� �̸� : ";
	cin >> temp.name;
	cout << "�л��� ���� : ";
	cin >> temp.age;
	cout << "�л��� ����(0.�� 1.��) : ";
	cin >> temp.gender;

	mng.push_back(temp);
}

void Student_Mng::Show_Student(_Student student) {
	cout <<"��ȣ."<< student.num << '\t';
	cout <<"�̸� : "<< student.name << '\t';
	cout <<"���� : "<< student.age << '\t';
	if (student.gender == MALE)
		cout << "���� : ��" << endl;
	else
		cout << "���� : ��" << endl;
}

void Student_Mng::Delete_Student() {
	int input;
	string str;
	int age;
	cout << "������ �л���� �˻�\n1.�̸��˻� 2.���̰˻� : ";
	cin >> input;
	switch (input)
	{
	case 1:
		cout << "�˻��� �̸� �Է� : ";
		cin >> str;
		for (int i = 0; i < mng.size(); i++) {
			if (mng[i].name == str) {
				Show_Student(mng[i]);
			}
		}
		cout << "������ �л��� ��ȣ�� �������ּ���. : ";
		cin >> input;
		mng.erase(mng.begin() + input - 1);
		cout << "�����Ǿ����ϴ�." << endl;
		break;
	case 2:
		cout << "�˻��� ���� �Է� : ";
		cin >> age;
		for (int i = 0; i < mng.size(); i++) {
			if (mng[i].age == age) {
				Show_Student(mng[i]);
			}
		}
		cout << "������ �л��� ��ȣ�� �������ּ���. : ";
		cin >> input;
		mng.erase(mng.begin() + input - 1);
		cout << "�����Ǿ����ϴ�." << endl;
		break;
	default:
		cout << "�߸��Է��ϼ̽��ϴ�." << endl;
		break;
	}
}
