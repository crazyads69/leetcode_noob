/**
 * @param {number[]} nums
 * @return {number}
 */
var distinctAverages = function (nums) {
  const averages = new Set();

  nums.sort((a, b) => a - b);

  while (nums.length > 0) {
    const min = nums.shift();
    const max = nums.pop();

    const avg = (min + max) / 2;
    averages.add(avg);
  }

  return averages.size;
};

nums = [4, 1, 4, 0, 3, 5];
console.log(distinctAverages(nums)); // 2
