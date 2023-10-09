#include <iostream>
#include <stack>
#include <vector>
#include <fstream>


using namespace std;

vector<int> nextGreater(vector<int>& arr){
    int i;
    for(i = 0; i < arr.size(); i++)
    {
        bool check = false;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if(arr[j] > arr[i])
            {
                arr[i] = arr[j];
                check = true;
                break;
            }
        }
        if (check == false)
        {
            arr[i] = -1;
        }
    }
    return arr;
}

int main() {
    ifstream input;
    input.open("D:\\DSA\\TH\\DSA_TH\\Stack\\Ex2\\text.txt");
    if (!input)
    {
        cout << "error file";
        return 1;
    }
    int N;
    input >> N;
    vector<int> nums(N);
    for(int i = 0; i < N; i++) input >> nums[i];
    vector<int> greaterNums = nextGreater(nums);
    ofstream output;
    output.open("out.txt");
    for(int i : greaterNums)output << i << ' ';
    cout << '\n';
    return 0;
}
