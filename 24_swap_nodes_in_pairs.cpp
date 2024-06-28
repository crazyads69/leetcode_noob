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
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution 1: Recursion
// Time complexity: O(n)
class Solution_1 {
public:
  ListNode *swapPairs(ListNode *head) {
    // If the list has no node or has only one node left.
    if (head == NULL || head->next == NULL) {
      return head;
    }
    // Nodes to be swapped
    ListNode *temp = head->next;
    // Swapping
    head->next = swapPairs(temp->next);
    // Swapping
    temp->next = head;
    return temp;
  }
};

// Solution 2: Iteration with dummy node
class Solution_2 {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *dummy = new ListNode(0);
    // Point the next of dummy to head
    dummy->next = head;
    ListNode *current = dummy;
    while (current->next != NULL && current->next->next != NULL) {
      // Nodes to be swapped
      ListNode *first = current->next;
      ListNode *second = current->next->next;
      // Swapping
      first->next = second->next;
      // Swapping
      current->next = second;
      current->next->next = first;
      current = current->next->next;
    }
    return dummy->next;
  }
};