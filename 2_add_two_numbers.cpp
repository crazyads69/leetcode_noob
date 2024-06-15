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
#include <__config>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // Create a dummy head node to simplify the code
    ListNode *dummy_head = new ListNode(0);
    // Create pointers to the input lists and the current node in the new list
    ListNode *p = l1, *q = l2, *current = dummy_head;
    // Initialize the carry to 0
    int carry = 0;
    // Iterate over both lists
    while (p != nullptr || q != nullptr) {
      int x = (p != nullptr) ? p->val : 0;
      int y = (q != nullptr) ? q->val : 0;
      // Add carry from previous iteration to the current sum
      int sum = carry + x + y;
      // Update carry for the next iteration
      carry = sum / 10;
      // Create a new node with the digit value of the sum
      current->next = new ListNode(sum % 10);
      // Move to the next node
      current = current->next;
      if (p != nullptr)
        p = p->next;
      if (q != nullptr)
        q = q->next;
    }
    // Check if there is a carry left after the last iteration
    if (carry > 0) {
      // Create a new node with the carry value
      current->next = new ListNode(carry);
    }
    // Return the head of the new list (skip the dummy head node)
    return dummy_head->next;
  }
};