/**
 * @param {number[]} nums
 * @return {number}
 */
var findLHS = function (nums) {
  const map = new Map();
  let max = 0;

  for (const num of nums) {
    map.set(num, (map.get(num) || 0) + 1);
  }

  for (const [key, value] of map) {
    if (map.has(key + 1)) {
      max = Math.max(max, value + map.get(key + 1));
    }
  }

  return max;
};
