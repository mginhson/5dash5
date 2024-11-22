#include <iostream>
#include <string>

using namespace std;
int main (void)
{
    string input, answer;

    cin >> input ;

    auto i = input.begin();

    while (i != input.end())
    {
        auto repeat = i;
        

        unsigned int counter = 1;
        while (*(++i) == *repeat)
            ++counter;
        
        answer.push_back(*repeat);
        answer.append(to_string(counter));

    }

    cout << answer << endl;

    
}