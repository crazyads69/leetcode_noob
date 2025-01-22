/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function (matrix, k) {
  // Get the number of rows and columns
  const rows = matrix.length;
  const cols = matrix[0].length;

  // Binary search
  let left = matrix[0][0]; // Smallest element
  let right = matrix[rows - 1][cols - 1]; // Largest element

  while (left < right) {
    // Get the middle element
    const mid = Math.floor(left + (right - left) / 2);

    // Count the number of elements less than or equal to mid
    let count = 0;
    // Start from the top right corner
    let j = cols - 1;

    for (let i = 0; i < rows; i++) {
      while (j >= 0 && matrix[i][j] > mid) {
        j--;
      }
      // Count the number of elements less than or equal to mid
      count += j + 1;
    }

    if (count < k) {
      // If the count is less than k, then the kth smallest element is greater than mid
      left = mid + 1;
    } else {
      // If the count is greater than or equal to k, then the kth smallest element is less than or equal to mid
      right = mid;
    }
  }

  return left;
};

matrix = [
  [1, 5, 9],
  [10, 11, 13],
  [12, 13, 15],
];
k = 8;

console.log(kthSmallest(matrix, k)); // 13
