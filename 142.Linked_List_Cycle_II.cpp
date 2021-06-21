// Solution for Linked List Cycle II contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/linked-list-cycle-ii/

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Notice that you should not modify the linked list.

Example:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slowPtr = head;
        ListNode *fastPtr = head;
        while(fastPtr && fastPtr->next){ // detect cycle first, same as Linked List Cycle.
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if(slowPtr==fastPtr)
                break;
        }
        if(fastPtr == NULL || fastPtr->next == NULL) // if no cycle found, return NULL.
            return NULL;
        slowPtr = head; // point the slow pointer to the head of the list, leave fast pointer as it is.
        while(slowPtr != fastPtr){ // advance both slow and fast pointer in the same pace. They will meet at some point. That will be the cycle point.
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
        return slowPtr; // return the cycle point.
    }
};

// Time complexity: O(n)