#include <iostream>
using namespace std;

void print(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n = 4; // Number of rows is transposable
    print(n);
    /* Pattern which is going to be printed :
                                    ****
                                    *  *
                                    *  *
                                    ****                                                                         */
    return 0;
}