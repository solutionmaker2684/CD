#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<string> keywords = {"asm", "else", "new", "this", "auto", "enum", "operator", "throw", "bool", "explicit", "private",	"true", "break", "export", "protected", "try", "case", "extern", "public","typedef", "catch", "false", "register", "typeid", "char", "float", "reinterpret_cast", "typename", "class", "for", "return", "union", "const", "friend", "short", "unsigned", "const_cast", "goto", "signed", "using", "continue", "if",	"sizeof", "virtual", "default",	"inline", "static",	"void", "delete", "int", "static_cast",	"volatile", "do", "long", "struct",	"wchar_t", "double", "mutable",	"switch", "while", "dynamic_cast", "namespace", "template", "And", "bitor", "not_eq", "xor", "and_eq", "compl",	"or", "xor_eq", "bitand", "not","or_eq"};
    string str;
    cout << "Enter a string : ";
    cin >> str;
    bool result = false;
    for(int i = 0; i < keywords.size(); i++){
        if(str == keywords[i]){
            result = true;
            break;
        }
    }  
    cout << (result ? "String is a keyword" : "String is not a keyword") << endl;
    return 0;
}