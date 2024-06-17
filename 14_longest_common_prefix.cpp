#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Solution 1: Compare the prefix with each string in the vector
// Time complexity: O(n * m)
class Solution_1 {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0)
      return "";
    // Initialize the prefix to the first string in the vector
    string prefix = strs[0];
    // Compare the prefix with each string in the vector
    for (int i = 1; i < strs.size(); i++) {
      int j = 0;
      // Find the common prefix between the current prefix and the current
      // string
      while (j < prefix.size() && j < strs[i].size() &&
             prefix[j] == strs[i][j]) {
        // Increment j to move to the next character until the prefix and the
        // current string are different
        j++;
      }
      prefix = prefix.substr(0, j);
    }
    return prefix;
  }
};

// Solution 2: Use binary search to find the common prefix
// Time complexity: O(n * m * log(n))
class Solution_2 {
public:
  bool isCommonPrefix(vector<string> &strs, int len) {
    string str1 = strs[0].substr(0, len);
    for (int i = 1; i < strs.size(); i++)
      if (strs[i].find(str1) != 0)
        return false;
    return true;
  }
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty())
      return "";
    int minLen = INT_MAX;
    for (string str : strs)
      minLen = min(minLen, (int)str.length());
    int low = 1, high = minLen;
    while (low <= high) {
      int middle = (low + high) / 2;
      if (isCommonPrefix(strs, middle))
        low = middle + 1;
      else
        high = middle - 1;
    }
    return strs[0].substr(0, (low + high) / 2);
  }
};