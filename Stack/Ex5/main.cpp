#include <iostream>
#include <stack>
#include <map>
#include <string>

using namespace std;

bool isValidParentheses (string s){
    /*TODO*/
    map<char,char>check ={{'[',']'}, {'{', '}'}, {'(',')'}};
    stack<char>Stack;
    for(auto run:s){
        if(run == '{' || run == '[' || run == '('){
            Stack.push(run);
        }
        else{
            if(Stack.empty() || check[Stack.top()] != run){
                return false;
            }
            else{
                Stack.pop();
            }
        }
    }
    if(Stack.empty()){
        return true;
    }else{
        return false;
    }
}

int main() {
    string test = "{}[";
    cout << isValidParentheses(test);
    return 0;
}
