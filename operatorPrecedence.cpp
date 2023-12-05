#include <iostream>
using namespace std;

bool isOperatorPrecedence(string rule){
    for(int i = 0; i < rule.size(); i++){
        if(rule[i] == 'e'){
            return false;
        }
    }
    for(int i = 0; i < rule.size() - 1; i++){
        if(rule[i] >= 65 && rule[i] <= 90 && rule[i+1] >= 65 && rule[i+1] <= 90){
            return false;
        }
    }
    return true;
}

int main(){
    string production;
    cout << "Enter production : ";
    cin >> production;

    cout << (isOperatorPrecedence(production) ? "Grammar is operator precedence" : "Grammar is not operator precedence") << endl;

    return 0;
}