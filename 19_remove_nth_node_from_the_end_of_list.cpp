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
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution 1: Using dummy node (two pass)
// Time complexity: O(L) where L is the length of the list
class Solution_1 {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // Init new list node
    ListNode *dummy = new ListNode(0);
    // Point to head
    dummy->next = head;
    // Init first and second pointer
    ListNode *first = dummy;
    ListNode *second = dummy;
    for (int i = 1; i <= n + 1; i++) {
      // Move first pointer to n + 1 node (the node before the node to be
      // removed)
      first = first->next;
    }
    // Move first pointer to end of list
    while (first != nullptr) {
      // Move first and second pointer
      first = first->next;
      second = second->next;
    }
    // Remove nth node from end of list
    second->next = second->next->next;
    return dummy->next;
  }
};

// Solution 2: Not using dummy node (one pass)
class Solution_2 {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *first = head, *second = head;

    // Move first pointer so that the gap between first and second is n nodes
    // apart
    for (int i = 0; i < n; i++) {
      first = first->next;
    }

    // If first has reached the end, remove the head node
    if (first == nullptr) {
      head = head->next;
      return head;
    }

    // Move first to the end, maintaining the gap
    while (first->next != nullptr) {
      first = first->next;
      second = second->next;
    }

    // Remove the nth node from end of list
    second->next = second->next->next;

    return head;
  }
};