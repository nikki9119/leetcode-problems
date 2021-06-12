// Solution for Container With Most Water contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/container-with-most-water/

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
Notice that you may not slant the container.

Example:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0, left=0, right=height.size()-1; //initialize two pointers, left and right
        while(left < right){
            maxArea = max(maxArea,min(height[left],height[right])*(right-left)); //store the maximum area, the shorter wall is selected as the height.
            if(height[left] < height[right]) //if left wall is shorter than the right wall move left pointer to the right, else move right pointer to the left
                left++;
            else
                right--;
        }
        return maxArea;
    }
};

// Time Complexity: O(n)