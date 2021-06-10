// Solution for Two Sum contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/two-sum/solution/

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> previous_instances; //using a map to store previous instances of the array.
        for(int i=0;i<nums.size();i++){
            int difference = target-nums[i]; //find the difference between the target and the current instance
            if(previous_instances.find(difference)!=previous_instances.end()){ //if we find that the difference exists in the map, we can come to the conclusion that there is a pair.
                return {previous_instances[difference],i}; //return the pair
            }
            previous_instances[nums[i]] = i; //store the instance for future reference
        } 
        return {}; //return an empty array if no pair is found.
    }
};

//Time complexity: O(n)