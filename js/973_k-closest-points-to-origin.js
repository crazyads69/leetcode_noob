/**
 * @param {number[][]} points
 * @param {number} k
 * @return {number[][]}
 */
var kClosest = function (points, k) {
  // Sort the points by distance from origin and return the first k points
  points.sort((a, b) => {
    const distA = a[0] ** 2 + a[1] ** 2;
    const distB = b[0] ** 2 + b[1] ** 2;
    return distA - distB;
  });

  return points.slice(0, k);
};

points = [
  [1, 3],
  [-2, 2],
];
k = 1;

console.log(kClosest(points, k)); // [[-2, 2]]
