#include <iostream>
#include <vector>
using namespace std;

bool isLeftRecursive(string rule){
    int position = rule.find("->");
    string leftSide = rule.substr(0, position);
    string rightSide = rule.substr(position + 2);

    if(leftSide == rightSide.substr(0, leftSide.length())){
        return true;
    }

    return false;
}

void eliminateLeftRecursion(vector<string> &grammar){
    
    for(int i = 0; i < grammar.size(); i++){
        string rule = grammar[i];

        if(isLeftRecursive(rule)){
            int position = rule.find("->");
            string leftSide = rule.substr(0, position);
            string rightSideRemainingRule = rule.substr(position + 2 + leftSide.length());

            string alpha = rightSideRemainingRule.substr(0, rightSideRemainingRule.find("|"));
            string beta = rightSideRemainingRule.substr(rightSideRemainingRule.find("|") + 1);

            string newRule1 = leftSide + "->" + beta + leftSide + "'";
            string newRule2 = leftSide + "'->" + alpha + leftSide + "'|e";

            grammar[i] = newRule1;
            grammar.push_back(newRule2);
        }
    }
}

int main(){
    vector<string> grammar;
    grammar.push_back("E->E+T|T");
    grammar.push_back("T->T*F|F");
    grammar.push_back("F->(E)|id");

    eliminateLeftRecursion(grammar);

    cout << "Modified Grammar" << endl;
    for (int i = 0; i < grammar.size(); i++) {
        cout << grammar[i] << endl;
    }

    return 0;
}