#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Brute force solution with O(n^2) time complexity
class Solution1 {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> result;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (nums[i] + nums[j] == target) {
          result.push_back(i);
          result.push_back(j);
          return result;
        }
      }
    }
    return result;
  }
};

// Optimized solution with O(n) time complexity using hash map
class Solution2 {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> result;
    unordered_map<int, int> hash_map;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int complement = target - nums[i];
      if (hash_map.find(complement) != hash_map.end()) {
        result.push_back(hash_map[complement]);
        result.push_back(i);
        return result;
      }
      // Store the index of the current element of array in the hash map
      hash_map[nums[i]] = i;
    }
    return result;
  }
};