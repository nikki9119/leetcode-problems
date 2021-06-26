// Solution for Rotting Oranges contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/rotting-oranges/

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct Orange{int i,j,minute;}; // structure to store the position of the orange in the grid and the minute it will get rotten.
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 2D array storing four possible directions inside the grid (left, right, down, up)
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size()==0 || grid[0].size()==0) return 0;
        int presentMinute = 0; // start with 0th minute
        int freshOranges = 0; // count of fresh oranges in the beginning
        queue<Orange> rotten; // queue to store rotten oranges.
        // traverse through the grid for rotten and fresh oranges
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){ // if the orange is already rotten push it into the queue with minute as 0 (starting minute)
                    rotten.push(Orange{i,j,0});
                }
                else if(grid[i][j]==1){ // increment the count of fresh oranges if the orange is fresh.
                    freshOranges+=1;
                }
            }
        }
        // start BFS with rotten oranges. Any orange that is near the rotten orange will rot the next minute.
        while(!rotten.empty()){
            Orange &orange = rotten.front();
            int i = orange.i;
            int j = orange.j;
            if(orange.minute>presentMinute)
                presentMinute++; // increment the present minute if the orange is from the next minute
            for(int d=0;d<4;d++){ // look for oranges in all the four possible directions
                int x = i+directions[d][0];
                int y = j+directions[d][1];
                if(x>=0&&x<grid.size()&&y>=0&&y<grid[i].size()&&grid[x][y]==1){ // if any fresh orange is found,
                    grid[x][y]=2; // make the orange rotten
                    rotten.push(Orange{x,y,presentMinute+1}); // push the orange into the queue with minute as the next minute
                    freshOranges-=1; // decrement the count of fresh oranges
                }
            }
            rotten.pop(); // pop the encountered rotten orange
        }
        return (freshOranges==0)?presentMinute:-1; // return the number of minutes elapsed only if all oranges are rotten, else return -1.
    }
};

// Time complexity: O(m*n), where m is the number of rows and n is the number of columns in the grid.