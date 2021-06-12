// Solution for Trapping Rain Water contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/trapping-rain-water/

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        int ans = 0;
        vector<int> left_max(height.size()),right_max(height.size()); //maintain two arrays for storing max elevation upto that point, both from right and left.
        left_max[0] = height[0];
        for(int i = 1 ; i<height.size(); i++){
            left_max[i] = max(height[i],left_max[i-1]); //populate max array from left
        }
        right_max[height.size()-1]=height[height.size()-1];
        for(int i = height.size()-2; i >= 0;i--){
            right_max[i] = max(height[i],right_max[i+1]); //populate max array from right
        }
        for(int i=0; i < height.size(); i++){
            ans += min(left_max[i],right_max[i]) - height[i]; //units os rain water that can be accomodated at a position
        }
        return ans;
    }
};

//Time complexity: O(n), Space Complexity: O(n)

//Space optimized solution:
class Solution {
public:
    int trap(vector<int>& height) {
        int lo=0, hi=height.size()-1,left_max=0, right_max=0, ans=0; //maintain just to variables to store the maximum height upto that point (both from left and right)
        while(lo<=hi){ //traverse until left pointer crosses the right pointer
            if(height[lo]<height[hi]){ //case 1:if the value in the left pointer is less than that of the value in the right pointer 
                if(height[lo]>left_max) //if the value is more than left_max, update left_max, else update the answer
                    left_max = height[lo];
                else
                    ans+=left_max - height[lo];
                lo++;
            }
            else{ //case 2:if the value in the right pointer is less than that of the value in the left pointer
                if(height[hi]>right_max) //if the value is more than right_max, update right_max, else update the answer
                    right_max = height[hi];
                else
                    ans += right_max - height[hi];
                hi--;
            }
        }
        return ans;
    }
};
//Time complexity: O(n), Space Complexity: O(1)