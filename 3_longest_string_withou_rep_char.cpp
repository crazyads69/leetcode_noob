#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Using sliding window technique to solve the problem
class Solution_1 {
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

// Using sliding window technique to solve the problem
// Optimized version of the above solution by using a hash map
class Solution_2 {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int ans = 0;
    // Hash map to store the index of the character
    unordered_map<char, int> index;
    // Try to extend the range [i, j]
    for (int i = 0, j = 0; j < n; j++) {
      // If the character is already in the substring, move the left pointer to
      // the right of the same character last found else i=0
      if (index.find(s[j]) != index.end()) {
        i = max(index[s[j]], i);
      }
      // Update the maximum length of the substring without repeating characters
      ans = max(ans, j - i + 1);
      // Update the value of the index of the character in the string
      index[s[j]] = j + 1;
    }
    return ans;
  }
};