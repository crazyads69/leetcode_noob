/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxFrequency = function (nums, k) {
  // Sort the array in ascending order
  nums.sort((a, b) => a - b);
  let left = 0;
  let sum = 0;
  let result = 1;

  for (let right = 1; right < nums.length; right++) {
    sum += (nums[right] - nums[right - 1]) * (right - left);
    while (sum > k) {
      sum -= nums[right] - nums[left];
      left++;
    }
    result = Math.max(result, right - left + 1);
  }
  return result;
};

nums = [1, 2, 4];
k = 5;

console.log(maxFrequency(nums, k)); // 3
