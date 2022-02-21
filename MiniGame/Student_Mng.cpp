#include "Student_Mng.h"

void Start_Mng() {
	Student_Mng std_mng;
	int input;
	while (true) {
		cout << "학생목록" << endl;
		for (int i = 0; i < std_mng.mng.size(); i++) {
			std_mng.Show_Student(std_mng.mng[i]);
		}
		cout << "=====================================\n";
		cout << "1.학생추가 2.학생제거 : ";
		cin >> input;
		switch (input) {
		case 1:
			std_mng.Add_Student();
			break;
		case 2:
			std_mng.Delete_Student();
			break;
		default:
			cout << "잘못입력하셨습니다." << endl;
			break;
		}
	}

}

void Student_Mng::Add_Student() {
	_Student temp;

	temp.num = (mng.size() + 1);
	cout << "학생의 이름 : ";
	cin >> temp.name;
	cout << "학생의 나이 : ";
	cin >> temp.age;
	cout << "학생의 성별(0.남 1.여) : ";
	cin >> temp.gender;

	mng.push_back(temp);
}

void Student_Mng::Show_Student(_Student student) {
	cout <<"번호."<< student.num << '\t';
	cout <<"이름 : "<< student.name << '\t';
	cout <<"나이 : "<< student.age << '\t';
	if (student.gender == MALE)
		cout << "성별 : 남" << endl;
	else
		cout << "성별 : 여" << endl;
}

void Student_Mng::Delete_Student() {
	int input;
	string str;
	int age;
	cout << "제거할 학생목록 검색\n1.이름검색 2.나이검색 : ";
	cin >> input;
	switch (input)
	{
	case 1:
		cout << "검색할 이름 입력 : ";
		cin >> str;
		for (int i = 0; i < mng.size(); i++) {
			if (mng[i].name == str) {
				Show_Student(mng[i]);
			}
		}
		cout << "삭제할 학생의 번호를 지정해주세요. : ";
		cin >> input;
		mng.erase(mng.begin() + input - 1);
		cout << "삭제되었습니다." << endl;
		break;
	case 2:
		cout << "검색할 나이 입력 : ";
		cin >> age;
		for (int i = 0; i < mng.size(); i++) {
			if (mng[i].age == age) {
				Show_Student(mng[i]);
			}
		}
		cout << "삭제할 학생의 번호를 지정해주세요. : ";
		cin >> input;
		mng.erase(mng.begin() + input - 1);
		cout << "삭제되었습니다." << endl;
		break;
	default:
		cout << "잘못입력하셨습니다." << endl;
		break;
	}
}
