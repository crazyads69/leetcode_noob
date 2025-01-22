/**
 * @param {number[]} dist
 * @param {number[]} speed
 * @return {number}
 */
var eliminateMaximum = function (dist, speed) {
  const n = dist.length;

  // Calculate the time required to reach each monster and sort them in ascending order
  const time = new Array(n);
  for (let i = 0; i < n; i++) {
    time[i] = Math.ceil(dist[i] / speed[i]);
  }

  // Sort the time array in ascending order
  time.sort((a, b) => a - b);

  let count = 0;
  for (let i = 0; i < n; i++) {
    // If the time required to reach the ith monster is greater than or equal to i, then the monster can be eliminated
    if (time[i] <= i) {
      break;
    }
    count++;
  }

  return count;
};

dist = [1, 3, 4];
speed = [1, 1, 1];

console.log(eliminateMaximum(dist, speed)); // 3
