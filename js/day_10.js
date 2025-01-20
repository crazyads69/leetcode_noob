/**
 * @param {Function} fn
 * @return {Function}
 */
// var once = function (fn) {
//   return function (...args) {
//     if (fn) {
//       // Call the function with the arguments and set the function to null
//       let result = fn(...args);
//       // Set the function to null after calling it so that it can't be called again
//       fn = null;
//       return result;
//     }
//   };
// };

var once = function (fn) {
  let isCalled = false;
  let result;

  return function (...args) {
    if (!isCalled) {
      isCalled = true;
      result = fn(...args);
      return result;
    }
    return undefined;
  };
};

let fn = (a, b, c) => a + b + c;
let onceFn = once(fn);
console.log(onceFn(1, 2, 3)); // 6
console.log(onceFn(2, 3, 6)); // undefined
