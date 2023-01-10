#include <iostream>
using namespace std;

void print(int n)
{
    char c = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << c;
        }
        c++;
        cout << endl;
    }
}
int main()
{
    int n = 5; // Number of rows is transposable
    print(n);
    /* Pattern which is going to be printed :
    A
    BB
    CCC
    DDDD
    EEEEE
    FFFFFF                                                                         */
    return 0;
}