#include <iostream>
using namespace std;

void print(int n)
{
    int start = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            start = 1;
        else
            start = 0;
        for (int j = 0; j < i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}
int main()
{
    int n = 5; // Number of rows is transposable
    print(n);
    /* Pattern which is going to be printed :
    0
    10
    010
    1010
    01010                                                                         */
    return 0;
}