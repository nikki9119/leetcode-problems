// Solution for Remove Nth Node From End of List contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp1 = head,*temp2 = head;
        for(int i=0;i<n;i++){ //give a head start to temp1 n nodes ahead.
            if(temp1->next == NULL){ //edge case (if n<= length of the list)
                if(i==n-1){
                    head = head->next;
                }
                return head;
            }
            temp1 = temp1->next;
        }
        while(temp1->next!=NULL){ //move both pointers accross the list until temp1 reaches the end.
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(temp2->next){
            ListNode *del = temp2->next;
            temp2->next = del->next;
            delete(del); //delete the nth node from the end of the list.
        }
        return head;
    }
};

// Time complexity : O(L) where L is the length of the linked list.