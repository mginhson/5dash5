#include <iostream>
#include <string>
#include <regex>
#include <vector>

//void getSpacedInput(vector<string> & palabras);
using namespace std;

void getSpacedInput(vector<string> & palabras){
    regex esp("\\s+");
    string linea;
    getline(cin, linea);
    

    sregex_token_iterator it(linea.begin(), linea.end(), esp, -1);
    sregex_token_iterator end;
    //vector<string> palabras;
    
    for (; it != end; ++it) {
        palabras.push_back(it->str());
    }
    
}
int main(void){
    vector <string> spacedLine;
    getSpacedInput(spacedLine);
    unsigned long int L = stoul(spacedLine[0].c_str()); 
    unsigned long int N = stoul(spacedLine[1].c_str());
    unsigned long int M = stoul(spacedLine[2].c_str());
    spacedLine.resize(0);
    vector <unsigned long int> aPositionUp;
    unsigned long int faces = N + 1;
    for (int i = 0; i < N; i++){
        getSpacedInput(spacedLine);
        if (!strcmp(spacedLine[0].c_str(), "U")){
            aPositionUp.push_back(stoul(spacedLine[1].c_str()));
        } else {
            aPositionUp.push_back(L);
        }
        spacedLine.resize(0);
    }
    for (int i = 0; i < M; i++){
        
        getSpacedInput(spacedLine);
        
        unsigned long int compare = stoul(spacedLine[1].c_str());
        if (!strcmp(spacedLine[0].c_str(), "L" )){
            faces += N;
            
        } else {
            
            for (int j = 0; j < N; j++){
                if (aPositionUp[j] > compare){
                    faces++;
                } 
            }
        }
        faces += 1;
        spacedLine.resize(0);
    }
    cout << faces;
    return 0;
}
