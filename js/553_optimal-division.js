/**
 * @param {number[]} nums
 * @return {string}
 */
var optimalDivision = function (nums) {
  if (nums.length === 1) {
    return nums[0].toString();
  }

  if (nums.length === 2) {
    return nums.join("/");
  }

  let result = nums[0].toString() + "/(" + nums[1];
  for (let i = 2; i < nums.length; i++) {
    result += "/" + nums[i];
  }
  result += ")";
  return result;
};

nums = [1000, 100, 10, 2];
console.log(optimalDivision(nums)); // "1000/(100/10/2)"
