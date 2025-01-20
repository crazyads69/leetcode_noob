/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function (functions) {
  return function (x) {
    // Execute the functions in reverse order and pass the result of the previous function to the next function
    return functions.reduceRight((acc, fn) => fn(acc), x);
  };
};

const fn = compose([(x) => x + 1, (x) => 2 * x]);
console.log(fn(4)); // 9
