// Solution for Longest Substring Without Repeating Characters contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string s, find the length of the longest substring without repeating characters.

Example:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256,-1); //to store indices of already occured characters.
        int n = s.size();
        int left=0; //sliding window technique. Initialize two pointers left and right
        int result = 0;
        for(int right=0;right<n;right++){
            left = max(left,lastIndex[s[right]]+1); //look for duplicates, if present slide the left window to the next of the duplicate.
            result = max(result,right-left+1); //find the maximum window length.
            lastIndex[s[right]] = right; //store the index of the character encountered.
        }
        return result;
    }
};

// Time complexity: O(n)