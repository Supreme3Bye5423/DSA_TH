#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int sumOfMaxSubarray(vector<int>& nums, int k) {
    // STUDENT ANSWER
    deque<int>subArray;
    if (k <= 0)return 0;
    int size = nums.size();
    if (k > size) k = size;
    int sum = 0;
    for(int i = 0; i < size; i++){
        if (i + k > size){
            break;
        }
        for(int cut = 0; cut < k; cut++){
            if(subArray.empty()){
                subArray.push_back(nums[cut + i]);
            }
            else if (nums[cut + i] > subArray.front()){
                subArray.pop_front();
                subArray.push_front(nums[cut + i]);
            }
        }
        sum += subArray.front();
        subArray.clear();
    }
    return sum;
}

int main() {
    vector<int> nums {1, 5, 2, 4};
    int k = 5;
    cout << sumOfMaxSubarray(nums, k);
}
