/**
 * @param {number[][]} grid
 * @return {number}
 */
var matrixScore = function (grid) {
  const rows = grid.length;
  const cols = grid[0].length;

  // Flip the first column to make all the first elements of each row to be 1
  for (let i = 0; i < rows; i++) {
    if (grid[i][0] === 0) {
      for (let j = 0; j < cols; j++) {
        grid[i][j] = grid[i][j] === 0 ? 1 : 0;
      }
    }
  }

  // Flip the columns to make the number of 1s in each column to be more than the number of 0s
  for (let j = 1; j < cols; j++) {
    let ones = 0;
    for (let i = 0; i < rows; i++) {
      ones += grid[i][j];
    }

    if (ones < rows / 2) {
      for (let i = 0; i < rows; i++) {
        grid[i][j] = grid[i][j] === 0 ? 1 : 0;
      }
    }
  }

  let score = 0;
  for (let i = 0; i < rows; i++) {
    let row = grid[i];
    let rowScore = 0;
    for (let j = 0; j < cols; j++) {
      rowScore = rowScore * 2 + row[j];
    }
    score += rowScore;
  }

  return score;
};

grid = [
  [0, 0, 1, 1],
  [1, 0, 1, 0],
  [1, 1, 0, 0],
];

console.log(matrixScore(grid)); // 39
