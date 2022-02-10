#include <iostream>
#include <Windows.h>

using namespace std;

const bool bLeft = false;
const bool bRight = true;
const char* star = "*****";
const char* space = "     ";

void print_star(int n, bool dir);

int main()
{
    int* arr = new int[5];
    int i = 0;
    while (i != 6) {
        arr[i] = i;
        cout << arr[i] << endl;
        i++;
    }
    system("pause");
}

void print_star(int n, bool dir) {
    if (dir == bLeft) {

    }
    else {

    }
}