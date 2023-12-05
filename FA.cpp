#include <iostream>
using namespace std;

int main(){
    string str;
    cout << "Enter the string : ";
    cin >> str;
    bool result = true;
    for(int i = 0; i < str.length(); i++){
        if(i == 0 && str[i] != 'a'){
            result = false;
            break;
        }else if(i == str.length()-1 && str[i] != 'b'){
            result = false;
            break;
        }else if (i != 0 && i != str.length() - 1 && str[i] != 'a' && str[i] != 'b'){
            result = false;
            break;
        }
    }
    cout << (result ? "String belongs to a given grammar" : "String does not belongs to a given grammar") << endl;
    return 0;
}