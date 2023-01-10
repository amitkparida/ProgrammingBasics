#include <iostream>
using namespace std;

void print(int n)
{
    int gap = 2 * (n - 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int k = 1; k <= gap; k++)
        {
            cout << " ";
        }
        for (int l = i; l >= 1; l--)
        {
            cout << l;
        }
        cout << endl;
        gap -= 2;
    }
}
int main()
{
    int n = 4; // Number of rows is transposable
    print(n); /* Pattern which is going to be printed :
        1      1
        12    21
        123  321
        12344321                                                                  */
    return 0;
}