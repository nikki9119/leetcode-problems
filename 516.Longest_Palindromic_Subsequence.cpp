// Solution for Longest Palindromic Subsequence contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/longest-palindromic-subsequence/

Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Example:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int longestCommonSubseq(string s1, string s2){
        // refer https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/ for LCS.
        int n = s1.size();
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
public:
    int longestPalindromeSubseq(string s) {
        // The idea here is that the longest common subsequence in s and the reverse of s will give us the longest palindromic subsequence of s.
        string reverseOfS = s;
        reverse(reverseOfS.begin(),reverseOfS.end()); // reverse s and store it as a separate string.
        return longestCommonSubseq(s,reverseOfS); // find the longest common subsequence in s and reverseOfS
    }
};

// Time complexity: O(n^2)