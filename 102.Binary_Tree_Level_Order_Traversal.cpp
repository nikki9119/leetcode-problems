// Solution for Binary Tree Level Order Traversal contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/binary-tree-level-order-traversal/

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
*/
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {}; // return empty array if the tree is empty.
        vector<vector<int>> res;
        queue<TreeNode *> traverseQueue; // maintain a queue to push the nodes level wise.
        int queueSize;
        vector<int> currentLevelValues; // array to store values of the nodes in a level.
        traverseQueue.push(root); // push the root node into the queue.
        while(!traverseQueue.empty()){
            queueSize = traverseQueue.size();
            for(int i=0;i<queueSize;i++){ // run a loop for the number of nodes in a particular level.
                TreeNode *front = traverseQueue.front(); // get the front of the queue.
                traverseQueue.pop();
                currentLevelValues.push_back(front->val); // append the value of front to the array.
                if(front->left)
                    traverseQueue.push(front->left); // push the left child of the front node to the queue if exists.
                if(front->right)
                    traverseQueue.push(front->right); // push the right child of the front node to the queue if exists.
            }
            res.push_back(currentLevelValues); // append the array of values to the result.
            currentLevelValues.clear(); // clear the array.
        }
        return res;
    }
};

// Time complexity: O(n), Space complexity: O(n)