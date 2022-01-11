#include <iostream>
#include <random>
using namespace std;

int main()
{
    int player, computer;
    random_device Rd;
    mt19937_64 Gen(Rd());
    uniform_int_distribution<int> nomber(0,2);

    cout << "가위 바위 보\n";
    while (true) {
        cout << "--------------------------------\n";
        cout << "가위 : 0, 바위 : 1, 보 : 2, 종료 : 3\n";
        cout << "값을 입력해주세요. : ";
        cin >> player;
        if (player == 3) break;
        computer = nomber(Gen);
        cout << "플레이어 : " << player << " | 컴퓨터 : " << computer << endl;
        if (player == computer) cout << "비겼습니다.\n";
        else if (player == 0 && computer == 1) cout << "패배했습니다.\n";
        else if (player == 1 && computer == 2) cout << "패배했습니다.\n";
        else if (player == 2 && computer == 0) cout << "패배했습니다.\n";
        else if (computer == 0 && player == 1) cout << "승리했습니다.\n";
        else if (computer == 1 && player == 2) cout << "승리했습니다.\n";
        else if (computer == 2 && player == 0) cout << "승리했습니다.\n";
        cout << "--------------------------------\n\n";
    }

    return 0;
}