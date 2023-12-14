#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//long long nthNiceNumber(int n) {
//    if(n == 1)return 2;
//    else if(n == 2) return 5;
//    queue<long long>Queue;
//    Queue.push(2);
//    long long x = 0;
//    for(int i = 2; i < n; i++)
//    {
//        x = Queue.front();
//        Queue.pop();
//        Queue.push(x*10+2);
//        Queue.push(x*10+5);
//    }
//    return x;
//}
//
long long nthNiceNumber(int n){
    vector<long long>ans;
    queue<long long>QueueEven;
    queue<long long>QueueOdd;
    QueueEven.push(2);
    QueueOdd.push(5);
    long long x = 0;
    int j = 1;
    int f = 1;
    for(int i = 0; i < n; i++){
        if (i%2==0){
            for(int run = 0; run < j; run++){
                if(ans.size() >= n){
                    return ans[n - 1];
                }
                x = QueueEven.front();
                QueueEven.pop();
                ans.push_back(x);
                QueueEven.push(x*10 + 2);
                QueueEven.push(x*10 + 5);
            }
            j*=2;
        }
        else{
            for(int run = 0; run < f; run++){
                if(ans.size() >= n){
                    return ans[n - 1];
                }
                x = QueueOdd.front();
                QueueOdd.pop();
                ans.push_back(x);
                QueueOdd.push(x*10 + 2);
                QueueOdd.push(x*10 + 5);
            }
            f*=2;
        }
    }
    return ans[n - 1];
}

int main() {
    cout << nthNiceNumber(10000) << endl;
}
