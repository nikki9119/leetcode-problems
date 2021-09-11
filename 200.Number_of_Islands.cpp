// Solution for Number of Islands contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/number-of-islands/

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void DFS(vector<vector<char>> &grid, int row, int col){ // A DFS function to traverse the lands.
        if(row<0 || row>=grid.size() || col<0 || col>=grid[row].size() || grid[row][col] == 0) // check for bounds and the cell content.
            return;
        else if(grid[row][col]=='1'){
            grid[row][col] = 0; // If a land ('1') is found, mark it as visited by just making it 0
            DFS(grid,row+1,col); // recursively call DFS for the adjacent cells.
            DFS(grid,row-1,col);
            DFS(grid,row,col+1);
            DFS(grid,row,col-1);
        }
    }
    public:
    int numIslands(vector<vector<char>>& grid) {
        int countOfIslands = 0;
        for(int row=0;row<grid.size();row++)
            for(int col=0;col<grid[row].size();col++)
                if(grid[row][col]=='1'){ // call the DFS method if the cell is a land ('1') 
                    DFS(grid,row,col);
                    countOfIslands++; // Increment the count of islands as the DFS is complete for the particular cell.
                }
        return countOfIslands;
    }
};

// Time complexity: O(row*col), where row,col are the dimensions of the matrix.