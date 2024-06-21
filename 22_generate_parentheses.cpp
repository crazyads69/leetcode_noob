#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Solution 1: Backtracking (Recursion) to generate all possible combinations
// of parentheses
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    if (n == 0)
      return res;
    if (n == 1) {
      res.push_back("()");
      return res;
    }
    backtrack(res, "", 0, 0, n);
    return res;
  }
  void backtrack(vector<string> &res, string cur, int open, int close,
                 int max) {
    // If the length of the current string is equal to 2 * n, then we have
    // reached the end of the recursion tree
    if (cur.size() == max * 2) {
      res.push_back(cur);
      return;
    }
    if (open < max) {
      // open parenthesis
      backtrack(res, cur + "(", open + 1, close, max);
    }
    if (close < open) {
      // close parenthesis
      backtrack(res, cur + ")", open, close + 1, max);
    }
  }
};