#include <iostream>
using namespace std;

void print(int n)
{
    
    for (int i = 0; i < n; i++)
    {
        int alpha = (2 * i + 1);
        for (int j = n - 1; j >= i; j--)
        {
            cout << " ";
        }
        char c = 'A';
        int beta = (2*i + 1)/2;
        for (int k = 1; k <= 2*i + 1; k++)
        {
            cout << c;
            if(k <= beta) c++;
            else c--;
        }
        for (int l = n - 1; l >= i; l--)
        {
            cout << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n = 4; // Number of rows is transposable
    print(n);
    /*                          Pattern which is going to be printed :
          A     
         ABA    
        ABCBA   
       ABCDCBA
      ABCDEDCBA                                                                           */
    return 0;
}