/**
 * @param {number[][]} matrix
 * @return {number}
 */
var minFallingPathSum = function (matrix) {
  const rows = matrix.length;
  const cols = matrix[0].length;

  // Start from the row before the last row
  for (let i = rows - 2; i >= 0; i--) {
    for (let j = 0; j < cols; j++) {
      let below = matrix[i + 1][j];
      let left = j > 0 ? matrix[i + 1][j - 1] : Number.MAX_SAFE_INTEGER;
      let right = j < cols - 1 ? matrix[i + 1][j + 1] : Number.MAX_SAFE_INTEGER;
      matrix[i][j] += Math.min(below, left, right);
    }
  }

  return Math.min(...matrix[0]);
};

matrix = [
  [2, 1, 3],
  [6, 5, 4],
  [7, 8, 9],
];

console.log(minFallingPathSum(matrix)); // 13
