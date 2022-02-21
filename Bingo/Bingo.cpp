#include <iostream>
#include <random>

using namespace std;

int size_arr, input, i, x, y, temp, x_rd, y_rd, bingo, count_bingo, Cpu_input;

random_device rd;
mt19937 gen(rd());
int check_bingo(int** arr);
void init_arr(int** arr);
void shuffle_arr(int** arr, int size_arr);
void print_arr(int** arr, int size_arr);
//---------------------------------------------------------------
int main() {
	cout << "사이즈 입력 : ";
	cin >> size_arr;
	int** User_arr = new int* [size_arr];
	int** Cpu_arr = new int* [size_arr];
	uniform_int_distribution<int> dis(0, size_arr - 1);

	init_arr(User_arr);
	shuffle_arr(User_arr, size_arr);
	init_arr(Cpu_arr);
	shuffle_arr(Cpu_arr, size_arr);
	while (true) {
		print_arr(User_arr, size_arr);
		cout << "--------------------------------------------" << endl;
		print_arr(Cpu_arr, size_arr);
		cin >> input;
		y = 0;
		while (y != size_arr) {
			x = 0;
			while (x != size_arr) {
				if (User_arr[y][x] == input) User_arr[y][x] = -1;
				if (Cpu_arr[y][x] == input) Cpu_arr[y][x] = -1;
				x++;
			}
			y++;
		}
		Cpu_input = dis(gen);
		cout << "컴퓨터의 숫자 : " << Cpu_input << endl;
		y = 0;
		while (y != size_arr) {
			x = 0;
			while (x != size_arr) {
				if (User_arr[y][x] == Cpu_input) User_arr[y][x] = -1;
				if (Cpu_arr[y][x] == Cpu_input) Cpu_arr[y][x] = -1;
				x++;
			}
			y++;
		}
		bingo = check_bingo(User_arr);
		cout << "-----------------------------------------------------------------" << endl;
		cout << "내 빙고 : " << bingo << endl;
	}
	return 0;
}
//---------------------------------------------------------------
int check_bingo(int** arr) {
	y = bingo = 0;
	while (y != size_arr) {
		x = count_bingo = 0;
		while (x != size_arr) {
			if (arr[y][x] == -1) count_bingo++;
			x++;
		}
		if (count_bingo == size_arr) bingo++;
		y++;
	}
	y = 0;
	while (y != size_arr) {
		x = count_bingo = 0;
		while (x != size_arr) {
			if (arr[x][y] == -1) count_bingo++;
			x++;
		}
		if (count_bingo == size_arr) bingo++;
		y++;
	}
	i = count_bingo = 0;
	while (i != size_arr) {
		if (arr[i][i] == -1) count_bingo++;
		i++;
	}
	if (count_bingo == size_arr) bingo++;
	y = count_bingo = 0;
	x = size_arr - 1;
	while (y != size_arr) {
		if (arr[y][x] == -1) count_bingo++;
		x--;
		y++;
	}
	if (count_bingo == size_arr) bingo++;

	return bingo;
}
//---------------------------------------------------------------
void init_arr(int** arr) {
	i = 0;
	while (i != size_arr) {
		arr[i] = new int[size_arr];
		i++;
	}
	y = 0;
	while (y != size_arr) {
		x = 0;
		while (x != size_arr) {
			arr[y][x] = (y * size_arr) + x;
			x++;
		}
		y++;
	}
}
//---------------------------------------------------------------
void shuffle_arr(int** arr, int size_arr) {
	uniform_int_distribution<int> dis(0, size_arr - 1);
	i = 0;
	while (i != 100) {
		x_rd = dis(gen);
		y_rd = dis(gen);
		temp = arr[y_rd][x_rd];
		arr[y_rd][x_rd] = arr[0][0];
		arr[0][0] = temp;
		i++;
	}
}
//---------------------------------------------------------------
void print_arr(int** arr, int size_arr) {
	y = 0;
	while (y != size_arr) {
		x = 0;
		while (x != size_arr) {
			if (arr[y][x] == -1) cout << "X" << '\t';
			else cout << arr[y][x] << '\t';
			x++;
		}
		cout << endl;
		y++;
	}
}