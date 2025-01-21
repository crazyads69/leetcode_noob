/**
 * @param {number[]} nums
 * @return {number}
 */
var countElements = function (nums) {
  const min = Math.min(...nums);
  const max = Math.max(...nums);

  let count = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > min && nums[i] < max) {
      count++;
    }
  }

  return count;
};

nums = [11, 7, 2, 15];
console.log(countElements(nums)); // 2
nums = [-3, 3, 3, 90];
console.log(countElements(nums)); // 2
nums = [-71, -71, 93, -71, 40];
console.log(countElements(nums)); // 1
