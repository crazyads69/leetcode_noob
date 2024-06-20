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
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    // Init new list node
    ListNode *dummy = new ListNode(0);
    // Point to head
    ListNode *current = dummy;
    // Merge two lists
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val < list2->val) {
        current->next = list1;
        list1 = list1->next;
      } else {
        current->next = list2;
        list2 = list2->next;
      }
      // Move current pointer to next node
      current = current->next;
    }
    // Append remaining nodes
    if (list1 != nullptr) {
      current->next = list1;
    }
    if (list2 != nullptr) {
      current->next = list2;
    }
    // Return merged list head
    return dummy->next;
  }
};

// Solution 2: not using dummy node (recursive)
class Solution_2 {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    // Init new list node
    ListNode *head = nullptr;
    // Merge two lists
    if (list1 == nullptr) {
      return list2;
    }
    if (list2 == nullptr) {
      return list1;
    }
    if (list1->val < list2->val) {
      head = list1;
      head->next = mergeTwoLists(list1->next, list2);
    } else {
      head = list2;
      head->next = mergeTwoLists(list1, list2->next);
    }
    // Return merged list head
    return head;
  }
};