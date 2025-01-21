/**
 * @param {number[]} nums
 * @param {number[]} queries
 * @return {number[]}
 */
var answerQueries = function (nums, queries) {
  const n = nums.length;
  const m = queries.length;
  // Sort the nums array in ascending order
  const sortedNums = nums.slice().sort((a, b) => a - b);
  const res = [];

  for (let i = 0; i < m; i++) {
    const query = queries[i];
    let sum = 0;
    let j = 0;

    // Iterate through the sortedNums array and add the current number to the sum until the sum is greater than the query
    while (j < n && sum + sortedNums[j] <= query) {
      // If the sum of the current number and the sum is less than or equal to the query, add the current number to the sum
      sum += sortedNums[j];
      j++;
    }

    // Add the number of elements that are less than or equal to the query to the result array
    res.push(j);
  }
  return res;
};

nums = [4, 5, 2, 1];
queries = [3, 10, 21];

console.log(answerQueries(nums, queries)); // [2,3,4]
