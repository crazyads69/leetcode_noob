
#include <iostream>
#include <vector>
using namespace std;

// Solution 1: Brute force solution
class Solution1 {
public:
  int xorAllNums(vector<int> &nums1, vector<int> &nums2) {
    vector<int> nums3;
    for (int i = 0; i < nums1.size(); i++) {
      for (int j = 0; j < nums2.size(); j++) {
        nums3.push_back(nums1[i] ^ nums2[j]);
      }
    }
    int res = 0;
    for (int i = 0; i < nums3.size(); i++) {
      res ^= nums3[i];
    }
    return res;
  }
};

// Solution 2: Optimized solution
// Fact:
// if nums1.size() is even and nums2.size() is even, the result is 0
// If nums2 is odd, the result is the xor of all elements in nums1 (all element
// in nums2 appear even times in nums3 so it is 0)
// If
class Solution {
public:
  int xorAllNums(vector<int> &nums1, vector<int> &nums2) {
    int res = 0;
    if (nums1.size() % 2 == 0 && nums2.size() % 2 == 0) {
      return 0;
    }
    if (nums2.size() % 2 == 1) {
      for (int num : nums1) {
        res ^= num;
      }
    }

    // Tương tự với nums2
    if (nums1.size() % 2 == 1) {
      for (int num : nums2) {
        res ^= num;
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  vector<int> nums1 = {1, 2, 3, 4, 5};
  vector<int> nums2 = {1, 2, 3, 4};
  cout << sol.xorAllNums(nums1, nums2) << endl;
  return 0;
}