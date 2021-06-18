// Solution for Reverse Linked List contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/reverse-linked-list/

Given the head of a singly linked list, reverse the list, and return the reversed list.

Example:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *current=head;
        ListNode *prev=NULL,*next=NULL;
        while(current!=NULL) // traverse the list until the end.
        {
            next=current->next; // next node is the current's next node.
            current->next=prev; // point current's next to the previous node.
            prev=current; // current node now becomes the previous node,
            current=next; // and the next node now becomes the current node.
        }
        head=prev; // the tail node now becomes the head node.
        return head;
    }
};

// Time complexity: O(n), where n is the length of the list.