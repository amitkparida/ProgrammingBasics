#include <iostream>
using namespace std;

void print(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            cout << "*";
        }
        for (int k = 0; k < 2 * i; k++)
        {
            cout << " ";
        }
        for (int l = n; l > i; l--)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        for (int k = 2*(n-i) - 2; k > 0; k--)
        {
            cout << " ";
        }
        for (int l = 0; l <= i; l++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
int main()
{
    int n = 5; // Number of rows is transposable
    print(n);
    print1(n);
    /*                          Pattern which is going to be printed :
                                      **********
                                      ****  ****
                                      ***    ***
                                      **      **
                                      *        *
                                      *        *
                                      **      **
                                      ***    ***
                                      ****  ****
                                      **********
                                                                                    */
    return 0;
}