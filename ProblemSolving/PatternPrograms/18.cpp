#include <iostream>
using namespace std;

void print(int n)
{
    for (int i = 0; i < n; i++)
    {
        char c = 'E';
        for (char c = 'E' - i; c <= 'E'; c++)
        {
            cout << c;
        }
        cout << endl;
    }
}
int main()
{
    int n = 5; // Number of rows is transposable
    print(5);
    /*                          Pattern which is going to be printed :
          E
          DE
          CDE
          BCDE
          ABCDE                                                                           */

    return 0;
}