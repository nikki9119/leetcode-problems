// Solution for ZigZag Conversion contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/zigzag-conversion/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);

Example:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows,""); //create an array to store the characters in their respective rows.
        int i=0,slen = s.size();
        while(i<slen){
            for(int j=0;j<numRows && i<slen;j++,i++) //go down the rows
                rows[j].push_back(s[i]);
            for(int j=numRows-2;j>=1 && i<slen;j--,i++)//go up the rows (zigzagging)
                rows[j].push_back(s[i]);
        }
        string res = "";
        for(string rowstring: rows){
            res+=rowstring; //append the characters row by row
        }
        return res;
    }
};

// Time complexity: O(n), Space Complexity: O(n)