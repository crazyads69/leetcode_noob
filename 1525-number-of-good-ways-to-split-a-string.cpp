#include <functional>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int numSplits(string s) {
    int n = s.size();
    int res = 0;
    // Count the frequency of each character in the string
    int left[26] = {0}, right[26] = {0};
    int leftCount = 0, rightCount = 0;
    for (int i = 0; i < n; i++) {
      // check if the character is not present in the right
      if (right[s[i] - 'a'] == 0) {
        rightCount++;
      }
      // Increment the frequency of the character in the right array by 1
      right[s[i] - 'a']++;
    }
    for (int i = 0; i < n; i++) {
      if (left[s[i] - 'a'] == 0) {
        leftCount++;
      }
      left[s[i] - 'a']++;
      right[s[i] - 'a']--;
      if (right[s[i] - 'a'] == 0) {
        rightCount--;
      }
      if (leftCount == rightCount) {
        res++;
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  string s = "aacaba";
  cout << sol.numSplits(s) << endl;
  return 0;
}