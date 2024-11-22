#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

void input (unsigned int* v, unsigned int& length, unsigned int& n)
{
    //To Complete by evaluator.
    n = 3;
    length = 1;

    v[0] = 2;
    
    
    
}


unsigned long long memo[10000 + 1]; //0 <= amount <= 10^4


#define MIN(a,b) (((a) < (b)) ? (a) : (b))

int main (void)
{
    unsigned int coins[12]; //coin[i] <= 2^32 - 1
    
    

    unsigned int amount, coinsLength;

    input(coins, coinsLength ,amount );


    memset(memo, ~0 ,sizeof(memo)/sizeof(*memo)); //max possible value

    for (unsigned int a = 0 ; a < coinsLength; a++)
        memo[coins[a]] = 1; //initialize base cases

    /**
     * Build the memoization from bottom (0) to top (amount), and retrieve the [amount] slot.
     * For every different amount trying to be reached, the step before the last one to arrive
     * to that sum had to be the difference between the current amount and one of the coins. 
     * The memo arrays keeps track of the minimum amount of coins to get to a sum, so, if the 
     * sum
    */
    for (unsigned int current = 0; current <= amount; current++)
    {
        
        for (unsigned int i = 0; i < coinsLength; i++)
        {
            
            if (current >= coins[i])
            {
                if (memo[current] - 1 > memo[current-coins[i]])
                    memo[current] = memo[current-coins[i]] + 1;
            }

            
        }
    }

    cout << (int)memo[amount] << endl;
}