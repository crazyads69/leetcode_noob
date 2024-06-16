#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    string ans = "";
    int n = s.size();
    // Create a 2D vector to store the results of the subproblems
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    // Iterate over the length of the substring
    for (int len = 1; len <= n; len++) {
      // Iterate over the starting index of the substring
      for (int i = 0; i < n - len + 1; i++) {
        // Calculate the ending index of the substring
        int j = i + len - 1;
        // Check if the substring is a palindrome
        if (s[i] == s[j] && (len <= 2 || dp[i + 1][j - 1])) {
          dp[i][j] = true;
          // Update the result if the current palindrome is longer
          if (len > ans.size()) {
            ans = s.substr(i, len);
          }
        }
      }
    }
    return ans;
  }
};