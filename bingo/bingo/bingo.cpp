#include <iostream>
#include <random>
#include <string>
//-------------------------------------------
using namespace std;
//-------------------------------------------
int arr_n[5][5];
string arr_s[5][5];
int i, j, n_temp, x, y, n_input, bingo, n_count;
string s_temp, s_input;
//-------------------------------------------
int check_num_bingo();
int check_str_bingo();
//-------------------------------------------
void init_num_arr();
bool check_num(int n_temp, bool b_ingame);
void show_num_arr();
//-------------------------------------------
void init_input_arr();
bool check_str(string s_temp, bool b_ingame);
void show_str_arr();
//-------------------------------------------
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> v_dis(0, 4);
uniform_int_distribution<int> n_dis(0, 60);
//-------------------------------------------
int check_num_bingo() {
	i = bingo = 0;
	while (i != 5) {
		j = 0;
		n_count = 0;
		while (j != 5) {
			if (arr_n[i][j] == -1) n_count++;
			j++;
		}
		if (n_count == 5) bingo++;
		i++;
	}
	i = 0;
	while (i != 5) {
		j = 0;
		n_count = 0;
		while (j != 5) {
			if (arr_n[j][i] == -1) n_count++;
			j++;
		}
		if (n_count == 5) bingo++;
		i++;
	}
	i = n_count = 0;
	while (i != 5) {
		if (arr_n[i][i] == -1) n_count++;
		i++;
	}
	if (n_count == 5) bingo++;
	i = n_count = 0;
	j = 4;
	while (i != 5) {
		if (arr_n[i][j] == -1) n_count++;
		j--;
		i++;
	}
	if (n_count == 5) bingo++;
	return bingo;
}
//-------------------------------------------
int check_str_bingo() {
	i = bingo = 0;
	while (i != 5) {
		j = 0;
		n_count = 0;
		while (j != 5) {
			if (arr_s[i][j] == "\0") n_count++;
			j++;
		}
		if (n_count == 5) bingo++;
		i++;
	}
	i = 0;
	while (i != 5) {
		j = 0;
		n_count = 0;
		while (j != 5) {
			if (arr_s[j][i] == "\0") n_count++;
			j++;
		}
		if (n_count == 5) bingo++;
		i++;
	}
	i = n_count = 0;
	while (i != 5) {
		if (arr_s[i][i] == "\0") n_count++;
		i++;
	}
	if (n_count == 5) bingo++;
	i = n_count = 0;
	j = 4;
	while (i != 5) {
		if (arr_s[i][j] == "\0") n_count++;
		j--;
		i++;
	}
	if (n_count == 5) bingo++;
	return bingo;
}
//-------------------------------------------
void init_num_arr() {
	y = 0;
	while (y != 5) {
		x = 0;
		while (x != 5) {
			n_temp = n_dis(gen);
			if (check_num(n_temp, false) == 0) {
				arr_n[y][x] = n_temp;
				x++;
			}
		}
		y++;
	}
}
//-------------------------------------------
bool check_num(int num, bool b_ingame) {
	i = 0;
	while (i != 5) {
		j = 0;
		while (j != 5) {
			if (arr_n[i][j] == num) {
				if (b_ingame == true) {
					arr_n[i][j] = -1;
					return 1;
				}
				else return 1;
			}
			j++;
		}
		i++;
	}
	return 0;
}
//-------------------------------------------
void show_num_arr() {
	i = 0;
	while (i != 5) {
		j = 0;
		while (j != 5) {
			if (arr_n[i][j] == -1) {
				cout << "X" << '\t';
				j++;
			}
			else {
				cout << arr_n[i][j] << '\t';
				j++;
			}
		}
		cout << endl;
		i++;
	}
}
//-------------------------------------------
void init_input_arr() {
	cout << "단어를 입력해주세요." << endl;
	y = 0;
	while (y != 5) {
		x = 0;
		while (x != 5) {
			cin >> s_temp;
			if (check_str(s_temp, false) == 0) {
				arr_s[y][x] = s_temp;
				x++;
			}
		}
		y++;
	}
}
//-------------------------------------------
bool check_str(string s_temp, bool b_ingame) {
	i = 0;
	while (i != 5) {
		j = 0;
		while (j != 5) {
			if (arr_s[i][j] == s_temp) {
				if (b_ingame == true) {
					arr_s[i][j] = "\0";
					return 1;
				}
				else return 1;
			}
			j++;
		}
		i++;
	}
	return 0;
}
//-------------------------------------------
void show_str_arr() {
	i = 0;
	while (i != 5) {
		j = 0;
		while (j != 5) {
			if (arr_s[i][j] == "\0") {
				cout << "X" << '\t';
				j++;
			}
			else {
				cout << arr_s[i][j] << '\t';
				j++;
			}
		}
		cout << endl;
		i++;
	}
}
//-------------------------------------------
int main() {
	cout << "숫자빙고.1 단어빙고.2 입력 : ";
	cin >> n_input;
	if (n_input == 1) {
		init_num_arr();
		while (true) {
			show_num_arr();
			cout << "현재 빙고 : " << check_num_bingo() << endl;
			if (check_num_bingo() >= 3) {
				cout << "승리하셨습니다.";
				cin >> n_input;
				return 0;
			}
			cout << "숫자 입력 : ";
			cin >> n_input;
			cout << "-----------------------------------" << endl;
			check_num(n_input, true);
		}
	}
	else if (n_input == 2) {
		init_input_arr();
		while (true) {
			show_str_arr();
			cout << "현재 빙고 : " << check_str_bingo() << endl;
			if (check_str_bingo() >= 3) {
				cout << "승리하셨습니다.";
				cin >> n_input;
				return 0;
			}
			cout << "단어 입력 : ";
			cin >> s_input;
			cout << "-----------------------------------" << endl;
			check_str(s_input, true);
		}
	}

	return 0;
}