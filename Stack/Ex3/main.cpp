#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

class node {
public:
    int x, y;
    int dir;
    node(int i, int j)
    {
        x = i;
        y = j;

        // Initially direction
        // set to 0
        dir = 0;
    }
};

bool canEatFood(int maze[5][5], int fx, int fy){
    
}

int main() {
    int maze[5][5] = {
            { 1, 0, 1, 1, 0 },
            { 1, 1, 1, 0, 1 },
            { 0, 1, 0, 1, 1 },
            { 1, 1, 1, 1, 0 },
            { 1, 0, 0, 1, 0 }
    };

// Food coordinates
    int fx = 1, fy = 4;

    cout << canEatFood(maze, fx, fy);

    return 0;
}
