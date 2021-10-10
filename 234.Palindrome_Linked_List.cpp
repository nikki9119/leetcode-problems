// Solution for Palindrome Linked List contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/palindrome-linked-list/

Given the head of a singly linked list, return true if it is a palindrome.

Example:
Input: head = [1,2,2,1]
Output: true

*/
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *left = head, *right = head, *prev = NULL, *tmp;
        while(right && right->next){ //reverse the linked list until the middle, and check both left and right halves.
            right = right->next->next;
            tmp = left->next;
            left->next = prev;
            prev = left;
            left = tmp;
        }
        if(right!=NULL){
            left = left->next; //skip the middle node (for odd length palindromes)
        }
        while(prev!=NULL && left!=NULL){ //check both left and right halves one by one.
            if(prev->val==left->val){ //go to the next node if they are equal.
                prev = prev->next;
                left = left->next;
            }
            else{
                return false; //if the nodes are not equal, we can conclude that the linked list is not a palindrome.
            }
        }
        return true;
    }
};

// Time complexity: O(n), Space complexity: O(1)