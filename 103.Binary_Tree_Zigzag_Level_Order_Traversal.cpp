// Solution for Binary Tree Zigzag Level Order Traversal contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
*/
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        stack<TreeNode *> currentLevel; // maintain two stacks for storing nodes in the current level
        stack<TreeNode *> nextLevel;    // and the next level.
        if(root == NULL)
            return res; // return empty array if the tree is empty.
        bool leftToRight = true; // decides whether to traverse from left to right or the opposite in a level.
        currentLevel.push(root); // push the root node into the current level.
        vector<int> nodeValuesOfCurrentLevel; // array to store values of the nodes in a level
        while(currentLevel.empty() == false){
            TreeNode *top = currentLevel.top(); // get the top of the current level stack.
            currentLevel.pop();
            if(top){
                nodeValuesOfCurrentLevel.push_back(top->val); // append to the array if top has a value.
                if(leftToRight){ // if traversal is from left to right, 
                    if(top->left)
                        nextLevel.push(top->left); // push the left child of the top node to the next level first if exists
                    if(top->right)
                        nextLevel.push(top->right); // then push the right child of the top node to the next level if exists
                }
                else{ // do the opposite of the above mentioned if traversal is from right to left.
                    if(top->right) 
                        nextLevel.push(top->right);
                    if(top->left)
                        nextLevel.push(top->left);
                }
            }
            if(currentLevel.empty()){
                res.push_back(nodeValuesOfCurrentLevel); // append the array of values to the result when we exhaust all the nodes in the current level
                nodeValuesOfCurrentLevel.clear(); // clear the array
                leftToRight = !leftToRight; // reverse the direction
                swap(currentLevel,nextLevel); // swap the next level with the current level.
            }
        }
        return res;
    }
};

// Time complexity: O(n), Space complexity: O(n)