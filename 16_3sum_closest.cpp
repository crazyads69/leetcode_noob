#include <vector>
using namespace std;

class Solution_1 {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    // sort the array
    sort(nums.begin(), nums.end());
    int n = nums.size();
    // initialize the closest sum
    int closest = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < n - 2; i++) {
      // two pointers
      int l = i + 1, r = n - 1;
      while (l < r) {
        // calculate the sum
        int sum = nums[i] + nums[l] + nums[r];
        // update the closest sum if needed
        if (abs(sum - target) < abs(closest - target)) {
          // update the closest sum with the current sum if the current sum is
          // closer to the target
          closest = sum;
        }
        if (sum < target) {
          // move the left pointer to the right if the sum is less than target
          l++;
        } else if (sum > target) {
          // move the right pointer to the left if the sum is greater than
          // target
          r--;
        } else {
          // return the target if the sum is equal to the target
          return sum;
        }
      }
    }
    return closest;
  }
};

// Solution 2: Optimized version of Solution 1
class Solution_2 {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int len = nums.size();
    // if the length of the array is less than 3, return the sum of all elements
    if (len == 3)
      return nums[0] + nums[1] + nums[2];

    sort(nums.begin(), nums.end());
    // initialize the closest sum
    int ans = nums[0] + nums[1] + nums[2];
    // if the closest sum is greater than or equal to the target, return the //
    // closest sum
    if (ans >= target)
      return ans;

    // if the sum of the last three elements is less than or equal to the
    // target,
    int max = nums[len - 1] + nums[len - 2] + nums[len - 3];
    // return the sum of the last three elements
    if (max <= target)
      return max;

    // initialize the last number
    int last = nums[0];
    int left, right, sum, num;
    // initialize the distance between the closest sum and the target
    int dist = abs(ans - target);
    int i = 0;

    for (; i < len - 2; i++) {
      if (i && nums[i] == last)
        continue;
      last = num = nums[i];
      left = i + 1;
      right = len - 1;
      while (left < right) {
        sum = num + nums[left] + nums[right];
        if (sum == target)
          return sum;
        if (abs(sum - target) < dist) {
          ans = sum;
          dist = abs(ans - target);
        }
        if (sum < target) {
          while (left < right && nums[left] == nums[left + 1])
            left++;
          left++;
        } else {
          while (left < right && nums[right] == nums[right - 1])
            right--;
          right--;
        }
      }
    }
    return ans;
  }
};