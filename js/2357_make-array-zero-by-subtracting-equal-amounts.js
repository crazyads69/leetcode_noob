/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumOperations = function (nums) {
  // Tạo một tập hợp (set) chứa các giá trị dương duy nhất trong mảng nums
  const uniquePositiveNumbers = new Set(nums.filter((num) => num > 0));

  // Số bước cần thiết chính là số lượng các phần tử trong tập hợp
  return uniquePositiveNumbers.size;
};
