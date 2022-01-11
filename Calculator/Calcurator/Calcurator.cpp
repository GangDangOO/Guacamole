#include <iostream>
using namespace std;

int main()
{
    int n1, n2;
    char c;

    cout << "계산기\n";
    cout << "값을 입력해주세요. : ";
    cin >> n1;
    while (true) {
        cout << "종료하실려면 1을 연산할려면 +, -, *, /를 입력해주세요. : ";
        cin >> c;
        if (c == '1') break;
        cout << "연산할 값을 입력해주세요. : ";
        cin >> n2;
        switch (c)
        {
        case '+':
            n1 += n2;
            break;
        case '-':
            n1 -= n2;
            break;
        case '*':
            n1 *= n2;
            break;
        case '/':
            n1 /= n2;
            break;
        default:
            break;
        }
        cout << "연산결과 : " << n1 << "이 나왔습니다.\n";
    }
}