/**
 * @param {number[]} happiness
 * @param {number} k
 * @return {number}
 */
var maximumHappinessSum = function (happiness, k) {
  happiness.sort((a, b) => b - a);

  let totalHappiness = 0;

  for (let i = 0; i < k; i++) {
    totalHappiness += Math.max(happiness[i] - i, 0);
  }

  return totalHappiness;
};
