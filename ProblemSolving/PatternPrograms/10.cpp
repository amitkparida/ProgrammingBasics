#include <iostream>
using namespace std;

void print1(int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i ; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print(int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

int main()
{
    int n = 5; // Number of rows is transposable
    print1(n);
    print(n);
    /* Pattern which is going to be printed :
     *
     **
     ***
     ****
     *****
     *****
     ****
     ***
     **
     *                                                                          */
    return 0;
}