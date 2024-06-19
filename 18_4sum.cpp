#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Solution 1: Brute force to find all combinations of 4 numbers
// Time complexity: O(n^3)
class Solution_1 {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    if (nums.size() < 4)
      return {};
    // sort the input vector
    sort(nums.begin(), nums.end());
    // initialize the result vector
    vector<vector<int>> res;
    // iterate through the input vector
    for (int i = 0; i < nums.size(); i++) {
      // Handle case when the number is overflown
      if (nums[i] > 0 && nums[i] > target)
        break;
      // skip duplicates
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      // iterate through the input vector
      for (int j = i + 1; j < nums.size(); j++) {
        // skip duplicates
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
        // initialize the left and right pointers
        int left = j + 1, right = nums.size() - 1;
        // iterate through the input vector
        while (left < right) {
          // calculate the sum of the four numbers
          long long sum = nums[i] + nums[j] + nums[left] + nums[right];
          // if the sum is equal to the target
          if (sum == target) {
            // add the four numbers to the result vector
            res.push_back({nums[i], nums[j], nums[left], nums[right]});
            // skip duplicates
            while (left < right && nums[left] == nums[left + 1])
              left++;
            // skip duplicates
            while (left < right && nums[right] == nums[right - 1])
              right--;
            // move the left pointer to the right
            left++;
            // move the right pointer to the left
            right--;
          }
          // if the sum is less than the target
          else if (sum < target)
            // move the left pointer to the right
            left++;
          // if the sum is greater than the target
          else
            // move the right pointer to the left
            right--;
        }
      }
    }
    return res;
  }
};

// Solution 2: Optimize the solution 1 add some conditions to skip some
// unnecessary iterations
// Time complexity: O(n^3)
class Solution_2 {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    if (nums.size() < 4)
      return result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 3; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      if ((long long)nums[i] + (long long)nums[i + 1] + (long long)nums[i + 2] +
              (long long)nums[i + 3] >
          target)
        break;
      if ((long long)nums[i] + (long long)nums[nums.size() - 1] +
              (long long)nums[nums.size() - 2] +
              (long long)nums[nums.size() - 3] <
          target)
        continue;

      for (int j = i + 1; j < nums.size() - 2; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
        if ((long long)nums[i] + (long long)nums[j] + (long long)nums[j + 1] +
                (long long)nums[j + 2] >
            target)
          break;
        if ((long long)nums[i] + (long long)nums[j] +
                (long long)nums[nums.size() - 1] +
                (long long)nums[nums.size() - 2] <
            target)
          continue;

        int left = j + 1, right = nums.size() - 1;

        while (left < right) {
          long long sum = static_cast<long long>(nums[i]) + nums[j] +
                          nums[left] + nums[right];

          if (sum == target) {
            result.push_back({nums[i], nums[j], nums[left], nums[right]});

            while (left < right && nums[left] == nums[left + 1])
              left++;
            while (left < right && nums[right] == nums[right - 1])
              right--;

            left++;
            right--;
          } else if (sum < target) {
            left++;
          } else {
            right--;
          }
        }
      }
    }
    return result;
  }
};