#include <iostream>
#include <random>

using namespace std;

int i, j, n1, n2, temp, input, bCount, bingo;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(0, 4);

void output_arr(int arr[5][5]) {
	i = 0;
	while (i != 5) {
		j = 0;
		while (j != 5) {
			if (arr[i][j] != -1) {
				cout << arr[i][j];
				if (arr[i][j] < 10) cout << "   ";
				else cout << "  ";
			}
			else cout << "X   ";
			j++;
		}
		cout << endl << endl;
		i++;
	}
}

void init_arr(int arr[5][5]) {
	i = 0;
	while (i != 5) {
		j = 0;
		while (j != 5) {
			arr[i][j] = (i * 5) + j;
			j++;
		}
		i++;
	}
}

int check_bingo(int arr[5][5]) {
	i = bingo = 0;
	while (i != 5) {
		j = bCount = 0;
		while (j != 5) {
			if (arr[i][j] == -1) bCount++;
			j++;
		}
		if (bCount == 5) bingo++;
		i++;
	}
	i = 0;
	while (i != 5) {
		j = bCount = 0;
		while (j != 5) {
			if (arr[j][i] == -1) bCount++;
			j++;
		}
		if (bCount == 5) bingo++;
		i++;
	}
	i = bCount = 0;;
	while (i != 5) {
		if (arr[i][i] == -1) bCount++;
		if (bCount == 5) bingo++;
		i++;
	}
	i = bCount = 0;
	j = 4;
	while (i != 5) {
		if (arr[i][j] == -1) bCount++;
		if (bCount == 5) bingo++;
		i++;
		j--;
	}
	return bingo;
}

int main() {
	int arr[5][5];

	init_arr(arr);
	i = 0;
	while (i != 100) {
		n1 = dis(gen);
		n2 = dis(gen);
		temp = arr[n1][n2];
		arr[n1][n2] = arr[0][0];
		arr[0][0] = temp;
		i++;
	}
	cout << "-----------------------------" << endl;
	bingo = 0;
	while (true) {
		output_arr(arr);
		cout << "-----------------------------" << endl;
		bingo = check_bingo(arr);
		if (bingo >= 3) {
			cout << "승리하셨습니다. 빙고 : " << bingo << "개" << endl;
			cin >> input;
			return 0;
		}
		cout << "현재 빙고 : " << bingo << "개" << endl;
		cout << "입력 : ";
		cin >> input;
		cout << "-----------------------------" << endl;
		i = 0;
		while (i != 5) {
			j = 0;
			while (j != 5) {
				if (arr[i][j] == input) arr[i][j] = -1;
				j++;
			}
			i++;
		}
	}

	return 0;
}