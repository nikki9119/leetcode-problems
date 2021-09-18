// Solution for Find Winner on a Tic Tac Toe Game contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/

Tic-tac-toe is played by two players A and B on a 3 x 3 grid.

Here are the rules of Tic-Tac-Toe:

Players take turns placing characters into empty squares (" ").
The first player A always places "X" characters, while the second player B always places "O" characters.
"X" and "O" characters are always placed into empty squares, never on filled ones.
The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Given an array moves where each element is another array of size 2 corresponding to the row and column of the grid where they mark their respective character in the order in which A and B play.

Return the winner of the game if it exists (A or B), in case the game ends in a draw return "Draw", if there are still movements to play return "Pending".

You can assume that moves is valid (It follows the rules of Tic-Tac-Toe), the grid is initially empty and A will play first.

Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: "A" wins, he always plays first.
"X  "    "X  "    "X  "    "X  "    "X  "
"   " -> "   " -> " X " -> " X " -> " X "
"   "    "O  "    "O  "    "OO "    "OOX"
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int n = 3; //store the number of rows(columns) in the board
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> rows(n),cols(n); //maintain two arrays to store the results in the n rows and columns
        int diagonal = 0, anti_diagonal = 0; //also maintain two variables to store results in both diagonals
        int player = 1; //start with player 'A' (1 for player A and -1 for player B)
        for(int i=0;i<moves.size();i++){ //traverse through the moves array
            int moveRow = moves[i][0]; //get the row and column index of the move
            int moveCol = moves[i][1];
            rows[moveRow]+=player; //add the player value to the corresponding row and column
            cols[moveCol]+=player;
            if(moveRow==moveCol) //add the player value to the corresponding diagonals if the move is in a diagonal cell.
                diagonal+=player;
            if(moveRow+moveCol==n-1)
                anti_diagonal+=player;
            if(abs(rows[moveRow])==n || abs(cols[moveCol])==n || abs(diagonal)==n || abs(anti_diagonal)==n)
                return player == 1? "A" : "B"; //a player wins if all the cells in the row or column or one of the diagonals have the same value (ie. 1 or -1)
            player*=-1; //invert the player value to the next player.
        }
        //if all the moves are over and nobody wins, check whether the match is draw or pending.
        return moves.size() == n*n? "Draw":"Pending"; //a match is draw if the number of moves are equal to the size of the board. Else the match is pending
    }
};

// Time complexity: O(m) where m is the number of moves.