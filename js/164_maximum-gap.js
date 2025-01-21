/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumGap = function (nums) {
  const n = nums.length;
  if (n < 2) return 0;

  // Tìm giá trị nhỏ nhất và lớn nhất trong mảng
  const max = Math.max(...nums);
  const min = Math.min(...nums);

  // Nếu tất cả các phần tử giống nhau
  if (max === min) return 0;

  // Tính toán kích thước bucket
  const gap = Math.ceil((max - min) / (n - 1));

  // Khởi tạo bucket
  const maxBucket = new Array(n - 1).fill(-1);
  const minBucket = new Array(n - 1).fill(-1);

  // Phân loại phần tử vào bucket
  for (const num of nums) {
    if (num === min || num === max) continue;

    const idx = Math.floor((num - min) / gap);
    if (maxBucket[idx] === -1) {
      maxBucket[idx] = num;
      minBucket[idx] = num;
    } else {
      maxBucket[idx] = Math.max(maxBucket[idx], num);
      minBucket[idx] = Math.min(minBucket[idx], num);
    }
  }

  // Tính khoảng cách lớn nhất
  let maxGap = 0;
  let prev = min;

  for (let i = 0; i < n - 1; i++) {
    if (maxBucket[i] === -1) continue; // Bỏ qua bucket rỗng
    maxGap = Math.max(maxGap, minBucket[i] - prev);
    prev = maxBucket[i];
  }

  // So sánh với khoảng cách giữa giá trị lớn nhất và bucket cuối cùng
  maxGap = Math.max(maxGap, max - prev);

  return maxGap;
};

nums = [3, 6, 9, 1];
console.log(maximumGap(nums)); // 3
