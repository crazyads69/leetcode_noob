/**
 * @param {number[]} score
 * @return {string[]}
 */
// var findRelativeRanks = function (score) {
//   // Sort the score array in descending order
//   let sortedScore = score.slice().sort((a, b) => b - a);

//   // Create a map to store the rank of each score
//   let rankMap = new Map();

//   // Assign the rank to each score
//   for (let i = 0; i < sortedScore.length; i++) {
//     if (i === 0) {
//       rankMap.set(sortedScore[i], "Gold Medal");
//     } else if (i === 1) {
//       rankMap.set(sortedScore[i], "Silver Medal");
//     } else if (i === 2) {
//       rankMap.set(sortedScore[i], "Bronze Medal");
//     } else {
//       rankMap.set(sortedScore[i], i + 1 + "");
//     }
//   }

//   // Create a result array
//   let result = [];
//   for (let i = 0; i < score.length; i++) {
//     result.push(rankMap.get(score[i]));
//   }
//   return result;
// };

// Optimized solution

var findRelativeRanks = function (score) {
  const n = score.length;

  // Create a new array with the indices of the score array sorted in descending order
  const sortedIndices = new Array(n)
    .fill(0)
    .map((_, i) => i)
    .sort((a, b) => score[b] - score[a]);
  console.log("sortedIndices", sortedIndices);
  const result = new Array(n);

  const medals = ["Gold Medal", "Silver Medal", "Bronze Medal"];

  for (let i = 0; i < n; i++) {
    // Assign the rank to each score based on the sortedIndices array
    result[sortedIndices[i]] = i < 3 ? medals[i] : (i + 1).toString();
  }

  return result;
};

score = [5, 4, 3, 2, 1];
console.log(findRelativeRanks(score)); // ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
score = [10, 3, 8, 9, 4];
console.log(findRelativeRanks(score)); // ["Gold Medal", "5", "Bronze Medal", "Silver Medal", "4"]
