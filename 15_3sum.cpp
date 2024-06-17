#include <algorithm>
#include <initializer_list>
#include <vector>
using namespace std;

// Solution 1: Brute force to find all combinations of 3 numbers
// Time complexity: O(n^2)
class Solution_1 {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int target = -nums[i];
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        if (nums[l] + nums[r] == target) {
          res.push_back({nums[i], nums[l], nums[r]});
          while (l < r && nums[l] == nums[l + 1])
            l++;
          while (l < r && nums[r] == nums[r - 1])
            r--;
          l++;
          r--;
        } else if (nums[l] + nums[r] < target) {
          l++;
        } else {
          r--;
        }
      }
    }
    return res;
  }
};

// Solution 2: Optimize the solution 1
// Time complexity: O(n^2)
class Solution_2 {
  vector<vector<int>> threeSum(vector<int> &nums) {
    // Check if the size of nums is less than 3
    if (nums.size() < 3)
      return {};
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    if (nums.front() > 0 || nums.back() < 0)
      return {};
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0)
        break;
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int target = -nums[i];
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        if (nums[l] + nums[r] == target) {
          res.push_back({nums[i], nums[l], nums[r]});
          while (l < r && nums[l] == nums[l + 1])
            l++;
          while (l < r && nums[r] == nums[r - 1])
            r--;
          l++;
          r--;
        } else if (nums[l] + nums[r] < target) {
          l++;
        } else {
          r--;
        }
      }
    }
    return res;
  }
};