#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool checkLegal(int x, int H, int y, int W) {
    return (x < 0 || x >= H || y < 0 || y >= W);
}

bool DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y, int H, int W) {
    // Check if the current position is illegal or ('R')
    if (checkLegal(x, H, y, W) || grid[x][y] == 'R') {
        return false;
    }

    // Check if visited
    if (visited[x][y]) {
        return false;
    }

    // Mark this as visited
    visited[x][y] = true;

    // Check if reached the bottom row (x == H-1)
    if (x == H - 1) {
        return true;
    }

    // Explore possible paths: straight down, down-left, and down-right
    bool result = DFS(grid, visited, x + 1, y, H, W)                             // Straight down
        || (!checkLegal(x, H, y - 1, W) && grid[x][y - 1] != 'R' && DFS(grid, visited, x + 1, y - 1, H, W))  // Down-left
        || (!checkLegal(x, H, y + 1, W) && grid[x][y + 1] != 'R' && DFS(grid, visited, x + 1, y + 1, H, W)); // Down-right

    // Reset the visited flag for backtracking
    visited[x][y] = false;

    return result;
}

int main() {
    int W, H, y=-1; //(0,y) is the starting coord
    cin >> W >> H;
    vector<vector<char>> grid(H, vector<char>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
            if(grid[i][j]=='Y'){
                y=j;
            }
        }
    }
    // Create a memoization table to store visited positions
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    if (DFS(grid, visited, 0, y, H, W)){
        cout<<"YES";
    }
    else cout<<"NO";
    
    return 0;
}