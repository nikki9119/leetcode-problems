// Solution for Longest Palindromic Substring contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/longest-palindromic-substring/

Given a string s, return the longest palindromic substring in s.

Example:
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int expand(string str,int start, int end){
        // helper function to return the length of a palindromic substring within a string.
        while(start>=0 && end<str.size() && str[start]==str[end]){
            start--; // expand by moving start pointer to the left,
            end++; // and end pointer to the right
        }
        return end-start-1;
    }
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for(int i=0; i<s.size(); i++){
            int oddPalindromeLength = expand(s,i,i); // expand for odd palindrome with s[i] as center
            int evenPalindromeLength = expand(s,i,i+1); // expand for even palindrome with s[i] and s[i+1] as center
            int maxPalindromeLength = max(oddPalindromeLength, evenPalindromeLength); // get the maximum length between the above two palindromes.
            if(maxPalindromeLength > end-start){ // update maximum palindrome substring length
                start = i-(maxPalindromeLength-1)/2;
                end = i+maxPalindromeLength/2;
            }
        }
        return s.substr(start, end-start+1);
    }
};

// Time complexity: O(n^2)