#include <iostream>
using namespace std;

void print(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
             cout << "*";    
        }
        cout << endl;
    }
}
int main()
{
    int n = 5,m = 5; // Number of rows & columns is transposable
    print(n,m);
    /*                          Pattern which is going to be printed :
                                * * * * *
                                * * * * * 
                                * * * * * 
                                * * * * * 
                                * * * * *                                                                           */
    return 0;
}