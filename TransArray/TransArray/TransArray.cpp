#include <iostream>

using namespace std;

enum _Dirction {
	LEFT = 1,
	RIGHT
};

void Print_arr(int** arrs, int size_input); // 배열출력
void Swap_arr(int** arrs, int size_input, int dir_arr); // 배열값교환

int main() {
	int size_input;
	cout << "크기입력 : ";
	cin >> size_input;
	// 메모리할당
	int** arrs = new int*[size_input];
	for (int i = 0; i < size_input; i++) {
		arrs[i] = new int[size_input];
	}
	// 배열값 설정
	for (int i = 0; i < size_input; i++) {
		for (int j = 0; j < size_input; j++s) {
			arrs[i][j] = i * size_input + j;
		}
	}
	// 행동상태
	int input = 0;
	while (input != 3) {
		Print_arr(arrs, size_input);
		cout << "1.왼쪽 2.오른쪽 3.종료 : ";
		cin >> input;
		Swap_arr(arrs, size_input, input);
	}
	// 메모리 해제
	for (int i = 0; i < size_input; i++) {
		delete[] arrs[i];
	}
	delete[] arrs;
	return 0;
}

void Print_arr(int** arrs, int size_input) {
	for (int i = 0; i < size_input; i++) {
		for (int j = 0; j < size_input; j++) {
			cout << arrs[i][j] << '\t';
		}
		cout << endl;
	}
}

void Swap_arr(int** arrs, int size_input, int dir_arr) {
	if (dir_arr == LEFT) {
		for (int y = 0; y < size_input - 1; y++) {
			for (int x = y; x < size_input - y - 1; x++) {
				int temp;
				temp = arrs[y][x];
				arrs[y][x] = arrs[x][size_input - y - 1];
				arrs[x][size_input - y - 1] = arrs[size_input - y - 1][size_input - x - 1];
				arrs[size_input - y - 1][size_input - x - 1] = arrs[size_input - x - 1][y];
				arrs[size_input - x - 1][y] = temp;	
			}
		}
	}
	else if (dir_arr == RIGHT) {
		for (int y = 0; y < size_input - 1; y++) {
			for (int x = y; x < size_input - y - 1; x++) {
				int temp;
				temp = arrs[y][x];
				arrs[y][x] = arrs[size_input - x - 1][y];
				arrs[size_input - x - 1][y] = arrs[size_input - y - 1][size_input - x - 1];
				arrs[size_input - y - 1][size_input - x - 1] = arrs[x][size_input - y - 1];
				arrs[x][size_input - y - 1] = temp;
			}
		}
	}

}