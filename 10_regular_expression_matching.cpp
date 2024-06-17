#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Solution 1: Use dynamic programming to solve this problem
// Time complexity: O(m*n)
class Solution {
public:
  bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
      if (p[i - 1] == '*') {
        dp[0][i] = dp[0][i - 2];
      }
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] == '*') {
          dp[i][j] =
              dp[i][j - 2] ||
              (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
        }
      }
    }
    return dp[m][n];
  }
};

// Solution 2: Use recursive to solve this problem
// Time complexity: O(2^(m+n)) (exponential time complexity)
class Solution_2 {
public:
  bool isMatch(string s, string p) {
    if (p.empty()) {
      return s.empty();
    }
    bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));

    if (p.size() >= 2 && p[1] == '*') {
      return (isMatch(s, p.substr(2)) ||
              (first_match && isMatch(s.substr(1), p)));
    } else {
      return first_match && isMatch(s.substr(1), p.substr(1));
    }
  }
};

// Solution 3: Use recursive with memoization to solve this problem
// Time complexity: O(m*n) (linear time complexity)
class Solution_3 {
public:
  bool isMatch(string s, string p) {
    vector<vector<int>> memo(s.size() + 1, vector<int>(p.size() + 1, -1));
    return isMatch(s, p, 0, 0, memo);
  }

private:
  bool isMatch(const string &s, const string &p, int i, int j,
               vector<vector<int>> &memo) {
    if (j == p.size()) {
      return i == s.size();
    }
    if (memo[i][j] != -1) {
      return memo[i][j] == 1;
    }

    bool first_match = (i < s.size() && (p[j] == s[i] || p[j] == '.'));

    bool ans;
    if (j <= p.size() - 2 && p[j + 1] == '*') {
      ans = (isMatch(s, p, i, j + 2, memo) ||
             (first_match && isMatch(s, p, i + 1, j, memo)));
    } else {
      ans = first_match && isMatch(s, p, i + 1, j + 1, memo);
    }

    memo[i][j] = ans ? 1 : 0;
    return ans;
  }
};