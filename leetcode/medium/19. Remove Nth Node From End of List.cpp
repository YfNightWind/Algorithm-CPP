//
// Created by Alex Lin on 2022/1/20.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
 public:
  int cur = 0;
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!head) return nullptr;
    head->next = removeNthFromEnd(head->next, n);
    cur++;
    if (n == cur) return head->next;
    return head;
  }
};