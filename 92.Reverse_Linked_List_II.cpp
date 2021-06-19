// Solution for Reverse Linked List II contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/reverse-linked-list-ii/

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || left==right)
            return head;
        ListNode* curr = head, *prev = NULL;
        for(int i=1;i<left;i++){ // traverse until the leftmost node of the reversal chain
            prev = curr;
            curr = curr->next;
        }
        // The headConnector and the tailConnector pointers are set once initially and then used in the end to finish the linked list reversal.
        ListNode *headConnector = prev, *tailConnector = curr, *nxt=NULL;
        for(int i=left;i<=right;i++){ // reverse nodes until the rightmost node of the reversal chain 
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        // Adjust the final connections.
        if(headConnector != NULL)
            headConnector->next = prev;
        else
            head = prev;
        tailConnector->next = curr;
        return head;
    }
};

// Time complexity; O(n) where n is the length of the list.