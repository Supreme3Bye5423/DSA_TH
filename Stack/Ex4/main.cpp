#include <bits/stdc++.h>
using namespace std;

vector<int> stock_span(const vector<int>& ns) {
    // STUDENT ANSWER
    vector<int> result;
    int size = ns.size();
    result.push_back(1);
    for(int i = 1 ; i < size; i++){
        int span = 1;
        for(int j = i - 1; j >= 0; j--){
            if (ns[i] > ns[j]){
                span++;
            }
            else{
                break;
            }
        }
        result.push_back(span);
    }
    return result;
}


int main() {
    vector<int>ns = {10,4,5,90,120,80};

    for(auto i:stock_span(ns)){
        cout << i << " ";
    }
}
