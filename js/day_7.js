/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function (nums, fn, init) {
  let acc = init; // Giá trị tích lũy ban đầu
  for (let i = 0; i < nums.length; i++) {
    acc = fn(acc, nums[i], i); // Gọi hàm fn với giá trị tích lũy và phần tử hiện tại
  }
  return acc;
};

nums = [1, 2, 3, 4];
fn = function sum(accum, curr) {
  return accum + curr;
};
init = 0;

console.log(reduce(nums, fn, init)); // 10
