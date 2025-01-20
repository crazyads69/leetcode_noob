/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
// var map = function (arr, fn) {
//   return arr.map(fn);
// };

// The above implementation uses the built-in map method. Let's implement our own map function.
var map = function (arr, fn) {
  let newArr = [];
  for (let i = 0; i < arr.length; i++) {
    newArr.push(fn(arr[i], i));
  }
  return newArr;
};

arr = [1, 2, 3, 4, 5];
fn = function (num) {
  return num * 2;
};

console.log(map(arr, fn)); // [2, 4, 6, 8, 10]
