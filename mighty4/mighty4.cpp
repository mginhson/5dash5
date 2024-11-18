#include <iostream>

using namespace std;

#define MAX_N 100
#define MAX_M 100   
//Made global trying to force heap allocation.
unsigned long long pretty[MAX_M][MAX_N] = {0};


int main(void)
{
    pretty[MAX_M - 1][MAX_N - 1] = 1;
    
    for (int i = MAX_M - 1; i >= 0; i--) //Traverses every row, bottom to top
    {
        for (int j = MAX_N - 1; j >= 0; j--)//Traverses every column, right to left
        {
            if ((i + 1) < MAX_M) pretty[i][j] += pretty[i+1][j];
            if ((j + 1) < MAX_N) pretty[i][j] += pretty[i][j+1];
        }
    }

    unsigned int m,n; 
    
    cin >> m >> n;
    
    if ((m > MAX_M) || (n > MAX_N))
        return -1;
    
    cout << pretty[MAX_M - m][MAX_N - n] << endl;


}