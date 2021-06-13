// Solution for Find First and Last Position of Element in Sorted Array contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //function to find the first occurence of the target number
    int findFirstOccurence(vector<int> nums,int lo,int hi,int target){
        int res = -1; //if target number is not found, we return -1.
        while(lo <= hi){ //binary search to find the occurence of the target number
            int mid = lo+(hi-lo)/2;
            if(nums[mid] < target)
                lo = mid+1;
            else if(nums[mid] > target)
                hi = mid-1;
            else{
                res = mid; //If arr[mid] is same as target, update res 
                hi = mid-1; //and move to the left half.
            }
        }
        return res;
    }
    //function to find the last occurence of the target number
    int findLastOccurence(vector<int> nums,int lo,int hi,int target){
        int res =- 1; //if target number is not found, we return -1.
        while(lo <= hi){ //binary search to find the occurence of the target number
            int mid = lo+(hi-lo)/2;
            if(nums[mid] < target)
                lo = mid+1;
            else if(nums[mid] > target)
                hi = mid-1;
            else{
                res = mid; //If arr[mid] is same as x, we update res 
                lo = mid+1; //and move to the right half.
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirstOccurence(nums, 0, nums.size()-1, target);
        int last = findLastOccurence(nums, 0, nums.size()-1, target);
        return {first, last};
    }
};

// Time complexity: O(log n)