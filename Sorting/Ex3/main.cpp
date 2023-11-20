#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k) {
    sort(rooms.begin(), rooms.end());
    sort(people.begin(), people.end());
    int count = 0;
    int roomPtr = 0;
    for(int i = 0; i < people.size(); i++){
        if(roomPtr >= rooms.size())break;
        while(roomPtr < rooms.size() && rooms[roomPtr] < people[i] - k){
            roomPtr++;
        }
        if (roomPtr < rooms.size() && rooms[roomPtr] <= people[i] + k){
            count++;
            roomPtr++;
        }
    }
    return count;
}

int main() {
    vector<int> people = {60, 60};
    vector<int> rooms = {10, 20 , 30};
    int k = 50;
    cout << maxNumberOfPeople(rooms, people, k) << '\n';
}
