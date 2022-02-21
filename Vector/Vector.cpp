#include <iostream>
#include <vector>

using namespace std;

int main() {
	int size = 20;
	vector<int> v1;
	for (int i = 0; i < size; i++) {
		v1.push_back(i);
		cout << v1[i] << endl;
		cout << "사이즈" << v1.size() << endl;
		cout << "메모리" << v1.capacity() << endl << endl;
	}
		v1.insert(v1.begin(), 100);
		cout << v1[0] << endl;
		cout << *v1.begin() << endl;
		cout << v1.front() << endl;
		cout << v1.back() << endl;
		vector<int>().swap(v1);
		v1.resize(20);
		cout << "사이즈" << v1.size() << endl;
		cout << "메모리" << v1.capacity() << endl << endl;
		v1.push_back(0);
		cout << "사이즈" << v1.size() << endl;
		cout << "메모리" << v1.capacity() << endl << endl;
		v1.insert(v1.begin() + 20, 5);
		v1.shrink_to_fit();
		cout << "사이즈" << v1.size() << endl;
		cout << "메모리" << v1.capacity() << endl << endl;


}