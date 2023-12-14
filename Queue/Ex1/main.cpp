#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

void interleaveQueue(queue<int>& q){
    int size = q.size();
    queue<int>firstHalf;
    queue<int>secondHalf;
    for(int i = 0; i < size; i++){
        if(i < size / 2){
            firstHalf.push(q.front());
            q.pop();
        }
        else {
            secondHalf.push(q.front());
            q.pop();
        }
    }
    for(int i = 0; i < size; i++){
        if(i % 2 == 0){
            q.push(firstHalf.front());
            firstHalf.pop();
        }
        else{
            q.push(secondHalf.front());
            secondHalf.pop();
        }
    }
}

int main() {
    queue<int> q;
    vector<int>vector = {2,4,6,8,10,12};
    int n = 6;
    for (int i = 0; i < n; i++){
        q.push(vector[i]);
    }
    interleaveQueue(q);
    while (!q.empty()){
        cout << q.front() << ' ';
        q.pop();
    }
}
