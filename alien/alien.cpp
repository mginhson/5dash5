#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

typedef struct {
    char prev;
    char next;
} Order;
void alienDictionary(vector <string> &vectorWithWords);
void alienDictionaryRecursive(vector<string>& words, int l, vector<Order>& orders);
int main(void) {
    vector<string> dou = { "ba", "bc", "ac", "cab"};
    alienDictionary(dou);
    return 0;
}

void alienDictionary(vector <string> &vectorWithWords) {

    vector<Order> orders;
    alienDictionaryRecursive(vectorWithWords, vectorWithWords.size(),orders);
    set<char> characters;
    //cout << orders.size();
    for (int i = 0; i < orders.size(); i++) {
        characters.insert(orders[i].prev);
        characters.insert(orders[i].next);
        
    }
    int size = characters.size();

    for (int i = 0; i < size; i++) {
        for (char j : characters) {
            bool isNext = false;
            for (Order& order : orders) {
                if (order.next == j) {
                    isNext = true;
                }
            }
            if (!isNext) {
               
                cout << j;
                for (int k = 0; k < orders.size(); k++) {
                    if (orders[k].prev == j) {
                        orders.erase(orders.begin() + k);
                        k--;
                    }
                }
                characters.erase(j);
                break;
            }
        }
    }
}

void alienDictionaryRecursive(vector<string>& words, int l,vector<Order>& orders) {
    int samePrincipalLetterCounter = 0;    
    for (int i = 0; i < l - 1; i++) {
        
        
        for (int j = 0; j < words[i].size() && j < words[i + 1].size(); j++) {
            if (words[i][j] != words[i + 1][j]) {
                Order newOrder({ (words)[i][j], words[i + 1][j] });
                orders.push_back(newOrder);
                break;
            }
        }
    }
}
