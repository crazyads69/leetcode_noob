/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function (nums) {
  // Sort the array to get the order of numbers in ascending order
  const sortedNums = [...nums].sort((a, b) => a - b);
  const map = new Map();

  for (let i = 0; i < sortedNums.length; i++) {
    // If the number is not in the map, add it to the map
    if (!map.has(sortedNums[i])) {
      // The value of the map is the index of the number in the sorted array
      map.set(sortedNums[i], i);
    }
  }

  return nums.map((num) => map.get(num));
};
