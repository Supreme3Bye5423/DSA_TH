#include <iostream>
#include <map>

using namespace std;

bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int,int>&pair2){
    map<int, pair<int,int>> Hash;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int sum = arr[i] + arr[j];
            if(Hash.find(sum) == Hash.end()){
                Hash[sum] = make_pair(i,j);
            }
            else{
                pair<int,int> pp = Hash[sum];
                pair1 = {arr[pp.first],arr[pp.second]};
                pair2 = {arr[i],arr[j]};
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
