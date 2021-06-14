// Solution for 3Sum contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/3sum/

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); //sort the array to handle duplicates while traversing, as they will be adjacent to each other in a sorted array.
        for(int i=0; i < nums.size() && nums[i] <= 0; i++){ //checking whether first integer is non-positive or not can save a lot of time. Got this idea from a forum ;)
            if(i > 0 && nums[i] == nums[i-1]) //continue iteration for duplicates
                continue;
            int lo = i+1, hi = nums.size()-1;
            while(lo < hi){
                int sum = nums[i]+nums[lo]+nums[hi];
                if(sum < 0) //increment lo pointer if sum<0
                    lo++;
                else if (sum > 0) //decrement hi pointer if sum>0
                    hi--;
                else{ //for triplet with sum==0
                    res.push_back({nums[i], nums[lo], nums[hi]});
                    while(lo<hi && nums[lo] == nums[lo+1]) lo++; //skip if duplicates are present
                    while(lo<hi && nums[hi] == nums[hi-1]) hi--; //skip if duplicates are present
                    lo++;
                    hi--;
                }
            }
        }
        return res;
    }
};

// Time Complexity: O(n^2) 