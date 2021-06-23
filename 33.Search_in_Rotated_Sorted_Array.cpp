// Solution for Search in Rotated Sorted Array contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/search-in-rotated-sorted-array/

There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Example:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    // The approach is based on modifying binary search as given in https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
    int modifiedBinarySearch(vector<int> nums, int target, int lo, int hi){
        if(lo>hi)
            return -1;
        int mid = (lo+hi)/2;
        if(nums[mid]==target)
            return mid;
        if(nums[lo]<=nums[mid]){ //If arr[l...mid] is sorted
            // As this subarray is sorted, we can quickly check if key lies in half or other half
            if(target>=nums[lo] && target<=nums[mid])
                return modifiedBinarySearch(nums, target, lo, mid-1);
            else
            // If key not lies in first half subarray, Divide other half  into two subarrays, such that we can quickly check if key lies in other half
                return modifiedBinarySearch(nums, target, mid+1, hi);
        }else{
            // If arr[l..mid] first subarray is not sorted, then arr[mid... h] must be sorted subarray
            if(target>=nums[mid] && target<=nums[hi])
                return modifiedBinarySearch(nums, target, mid+1, hi);
            else
                return modifiedBinarySearch(nums, target, lo, mid-1);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        return modifiedBinarySearch(nums, target, 0, nums.size()-1);
    }
};

// Time complexity: O(log(n))