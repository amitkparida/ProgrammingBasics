#include <iostream>
using namespace std;

void print(int n)
{
    char c = 'A';
    for (int i = 0; i < n; i++)
    {
        for (char c = 'A'; c <= 'A' + i; c++)
        {
            cout << c;
        }
        cout << endl;
    }
}
int main()
{
    int n = 5; // Number of rows is transposable
    print(n); /* Pattern which is going to be printed :
    A
    AB
    ABC
    ABCD
    ABCDE                                                                         */
    return 0;
}