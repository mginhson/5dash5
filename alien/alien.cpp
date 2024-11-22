#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

typedef struct {
    char prev;
    char next;
} Order;
void alienDictionary(vector <string> vectorWithWords);
void alienDictionaryRecursive(vector<string> &words, int s,int l, vector<Order>&orders);
int main(void){
    vector<string> dou = {"ba", "bc", "ac", "cab"};
    alienDictionary(dou);
    return 0;
}

void alienDictionary(vector <string> vectorWithWords){

    vector<Order> orders;
    alienDictionaryRecursive(vectorWithWords, 0, vectorWithWords.size(), orders);
    set<char> characters;
    for (int i = 0; i < orders.size(); i++){
        characters.insert(orders[i].prev);
        characters.insert(orders[i].next);
    }
    for (int i = 0; i < characters.size(); i++){
        for (char j : characters){
            bool isPrev = false;
            for (Order & order : orders){
                if (order.prev == j){
                    isPrev = true;
                }
            }
            if (!isPrev){
                cout << j;
                for (int k = 0; k < orders.size(); k++){
                    if (orders[k].next == j){
                        orders.erase(orders.begin() + k);
                    }
                }
                break;
            }
        }
    }
}

void alienDictionaryRecursive(vector<string> &words, int s,int l, vector<Order>&orders){
    int samePrincipalLetterCounter = 0;
    for (int i = s + 1; i < l;i++){
        if (words[i][0] != words[i - 1][0]){
            Order newOrder({(words)[i - 1][0], words[i][0]});
            orders.push_back(newOrder);
            if (samePrincipalLetterCounter > 0){
                alienDictionaryRecursive(words, i - samePrincipalLetterCounter - 1, samePrincipalLetterCounter, orders);    
                samePrincipalLetterCounter = 0;
            } 
        } else {
            samePrincipalLetterCounter++;
        } 
        
    }
}