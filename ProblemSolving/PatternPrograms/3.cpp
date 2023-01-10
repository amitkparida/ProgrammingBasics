#include <iostream>
using namespace std;

void print(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
int main()
{
    int n = 5; // Number of rows is transposable
    print(n);
    /*                          Pattern which is going to be printed :
                                1
                                12
                                123
                                1234
                                12345                                                                           */
    return 0;
}