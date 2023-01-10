#include <iostream>
using namespace std;

void print(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}
int main()
{
    int n = 5; // Number of rows is transposable
    print(n); /*                Pattern which is going to be printed :
                                1
                                22
                                333
                                4444
                                55555                                                                           */
    return 0;
}