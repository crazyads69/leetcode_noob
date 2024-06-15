#include <iostream>
#include <string>
using namespace std;

// Using sliding window technique to solve the problem
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int ans = 0;
    // Current index of character in the string
    // (ASCII value of the character is used as index)
    int index[128] = {0};
    // Try to extend the range [i, j]
    for (int i = 0, j = 0; j < n; j++) {
      // If the character is already in the substring, move the left pointer to
      // the right of the same character last found else i=0
      i = max(index[s[j]], i);
      // Update the maximum length of the substring without repeating characters
      ans = max(ans, j - i + 1);
      // Update the value of the index of the character in the string
      index[s[j]] = j + 1;
    }
    return ans;
  }
};