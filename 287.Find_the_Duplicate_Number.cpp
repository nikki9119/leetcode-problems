// Solution for Find the Duplicate Number contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/find-the-duplicate-number/

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.

Example:
Input: nums = [1,3,4,2,2]
Output: 2
*/
#include<bits/stdc++.h>
using namespace std;

// This problem is same as Linked List Cycle II -> https://leetcode.com/problems/linked-list-cycle-ii/
// Look for the existence of cycle using Floyd's cycle detection. Return the cycle point (which in this case, will be the duplicate number)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fastPtr = nums[0];
        int slowPtr = nums[0];
        do{ // detect cycle
            slowPtr = nums[slowPtr];
            fastPtr = nums[nums[fastPtr]];
        }while(slowPtr!=fastPtr);
        slowPtr = nums[0]; // point the slow pointer to the beginning of the array, leave fast pointer as it is.
        while(slowPtr!=fastPtr){ // advance both slow and fast pointer in the same pace. They will meet at some point. That will be the cycle point.
            slowPtr = nums[slowPtr];
            fastPtr = nums[fastPtr];
        }
        return fastPtr; // return the cycle point. You can return slowPtr also.
    }
};