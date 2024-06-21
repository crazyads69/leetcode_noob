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
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Solution 1: Merge lists one by one using recursion
class Solution_1 {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0)
      return nullptr;
    if (lists.size() == 1)
      return lists[0];
    return mergeKLists(lists, 0, lists.size() - 1);
  }
  ListNode *mergeKLists(vector<ListNode *> &lists, int start, int end) {
    if (start == end)
      return lists[start];
    int mid = start + (end - start) / 2;
    ListNode *left = mergeKLists(lists, start, mid);
    ListNode *right = mergeKLists(lists, mid + 1, end);
    return mergeTwoLists(left, right);
  }
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        cur->next = l1;
        l1 = l1->next;
      } else {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }
    if (l1)
      cur->next = l1;
    if (l2)
      cur->next = l2;
    return dummy->next;
  }
};

// Solution 2: Optimize Solution 1 by using a priority queue
// Time complexity: O(nlogk),
// where n is the total number of nodes and k is the number of linked lists
#include <queue>
class Solution_2 {
public:
  struct compare {
    bool operator()(const ListNode *l, const ListNode *r) {
      return l->val > r->val;
    }
  };
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode *, vector<ListNode *>, compare> pq;
    for (auto l : lists) {
      if (l)
        pq.push(l);
    }
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    while (!pq.empty()) {
      ListNode *top = pq.top();
      pq.pop();
      cur->next = top;
      cur = cur->next;
      if (top->next)
        pq.push(top->next);
    }
    return dummy->next;
  }
};
