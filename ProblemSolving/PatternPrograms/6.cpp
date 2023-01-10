#include <iostream>
using namespace std;

void print(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
int main()
{
    int n = 5, m; // Number of rows is transposable
    print(n); /*                Pattern which is going to be printed :
                                12345
                                1234
                                123
                                12
                                1                                                                          */
    return 0;
}