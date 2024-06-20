#include <iostream>
#include <stack>
#include <string>
using namespace std;
// Solution: Use stack to store current opening brackets and pop when closing
// brackets are found
// Time complexity: O(n) where n is the length of the string
class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
      // If c is an opening bracket, push it to the stack
      if (c == '(' || c == '[' || c == '{') {
        st.push(c);
      } else {
        // If c is a closing bracket, check if the stack is empty
        if (st.empty()) {
          return false;
        }
        // If c is a closing bracket, check if the top of the stack is the same
        if (c == ')' && st.top() != '(') {
          return false;
        }
        if (c == ']' && st.top() != '[') {
          return false;
        }
        if (c == '}' && st.top() != '{') {
          return false;
        }
        st.pop();
      }
    }
    return st.empty();
  }
};