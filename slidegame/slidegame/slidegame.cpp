#include <iostream>
#include <random>

using namespace std;

int arr[16] = { 0, };
int i, j, temp, sN1, sN2, input, here;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(1, 15);

struct vect {
	int x;
	int y;
};

void init_arr(int arr[]) {
	i = 0;
	while (i != 16) {
		arr[i] = i;
		i++;
	}
}

void shuffle_arr(int arr[]) {
	i = 0;
	while (i != 100) {
		sN1 = dis(gen);
		sN2 = dis(gen);
		temp = arr[sN1];
		arr[sN1] = arr[sN2];
		arr[sN2] = temp;
		i++;
	}
}

void shuffle_index(int arr[], int here, int n) {
	temp = arr[here];
	arr[here] = arr[n];
	arr[n] = temp;
}

void show_arr(int arr[]) {
	i = 0;
	while (i != 4) {
		j = 0;
		while (j != 4) {
			if (arr[i * 4 + j] < 10) cout << '0' << arr[i * 4 + j] << " ";
			else cout << arr[i * 4 + j] << " ";
			j++;
		}
		cout << endl;
		i++;
	}
}

int change_arr(int arr[], int here, int input) {
	switch (input) {
		case 4:
			if (here % 4 != 0 && here != 0) {
				shuffle_index(arr, here, here - 1);
				here--;
			}
			cout << here << endl;
			break;
		case 6:
			if (here % 4 != 3 && here != 3) {
				shuffle_index(arr, here, here + 1);
				here++;
			}
			cout << here << endl;
			break;
		case 8:
			if (here > 4) {
				shuffle_index(arr, here, here - 4);
				here -= 4;
			}
			break;
		case 2:
			if (here < 12) {
				shuffle_index(arr, here, here + 4);
				here += 4;
			}
			break;
	default:
		cout << "잘못입력하셨습니다." << endl;
		break;
	}
	return here;
}

int main() {
	here = 0;
	init_arr(arr);
	shuffle_arr(arr);
	while (true) {
		show_arr(arr);
		cout << "-------------------------------------" << endl;
		cout << "왼쪽.4 오른쪽.6 위.8 아래2 입력 : ";
		cin >> input;
		here = change_arr(arr, here, input);
	}
	return 0;
}