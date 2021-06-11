// Solution for Two Sum contributed by nikki9119.

/*
Problem URL: https://leetcode.com/problems/add-two-numbers/

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

*/
#include<bits/stdc++.h>
using namespace std;


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0; //variable to store the carry of addition
        ListNode answer(0); //initialize a node with value 0
        ListNode *temp = &answer; //temporary pointer for traversing
        while(l1||l2||carry){
            int sum = ((l1?l1->val:0)+(l2?l2->val:0)+carry); //add the numbers in the node if exists
            carry = (sum)/10;
            temp->next = new ListNode(sum%10); //create a node next to temp and store the sum
            temp = temp->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return answer.next; //return the list (we return answer.next because we have initialized a dummy node at the beginning which is not needed).
    }
};