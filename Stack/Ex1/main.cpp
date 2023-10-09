#include <iostream>
#include <stack>
#include <string>

using namespace std;

int baseballScore(string ops){
    /*TODO*/
    stack<int> scores;
    int result = 0;
    for(auto ch:ops)
    {
        if (ch >= '0' && ch <= '9')
        {
            scores.push(ch - '0');
        }
        else if (ch == 'C')
        {
            scores.pop();
        }
        else if (ch == 'D')
        {
            scores.push(scores.top()*2);
        }
        else if (ch == '+')
        {
            int temp = scores.top(), sum;
            scores.pop();
            sum = temp + scores.top();
            scores.push(temp);
            scores.push(sum);
        }
    }
    while(!scores.empty())
    {
        result += scores.top();
        scores.pop();
    }
    return result;
}

int main() {
    string test = "524CD9++";
    cout << baseballScore(test);
}
