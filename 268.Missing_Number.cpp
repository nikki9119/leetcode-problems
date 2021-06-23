// Solution for Missing Number contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/missing-number/

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example:
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /* This approach takes advantage of the Gauss' formula to compute the missing number. 
        Since the range is given and the range always starts with 0, we can use Gauss' formula for sum of first n natural numbers.
        Then we subtract the sum of the numbers in the array from the Gauss' sum which will give the missing number. */
        int sum = nums.size()*(nums.size()+1)/2; // Gauss' formula: sum of 1-n numbers = n(n+1)/2
        int numsSum = 0;
        for(int i:nums)
            numsSum+=i; // calculate the sum of the numbers present in the array.
        return sum-numsSum; // the difference between the two sums will give the missing number.
    }
};

// Time complexity: O(n), Space complexity: O(1)