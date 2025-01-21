/**
 * @param {number} n
 * @param {number[][]} rides
 * @return {number}
 */
var maxTaxiEarnings = function (n, rides) {
  rides.sort((a, b) => a[1] - b[1]);

  const dp = new Array(n + 1).fill(0);

  let rideIndex = 0;

  for (let i = 1; i <= n; i++) {
    // Update dp[i] with the previous value
    dp[i] = dp[i - 1];

    // Process all rides that end at i and update dp[i]
    while (rideIndex < rides.length && rides[rideIndex][1] === i) {
      const [start, end, tip] = rides[rideIndex];
      dp[end] = Math.max(dp[end], dp[start] + (end - start + tip));
      rideIndex++;
    }
  }

  return dp[n];
};

n = 5;

rides = [
  [2, 5, 4],
  [1, 5, 1],
];

console.log(maxTaxiEarnings(n, rides)); // 7
