/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
  // These variables are preserved via closure (so it can use them later)
  let callCount = 0;
  let cacheMap = new Map();

  const memoizedFn = function (...args) {
    const key = JSON.stringify(args);
    if (cacheMap.has(key)) {
      return cacheMap.get(key);
    }
    callCount += 1;
    const result = fn(...args);
    cacheMap.set(key, result);
    return result;
  };

  // This is a custom property that can be accessed from the outside
  memoizedFn.getCallCount = () => callCount;

  // Return the memoized function to the caller so it can be executed
  return memoizedFn;
}

let callCount = 0;
const memoizedFn = memoize(function (a, b) {
  callCount += 1;
  return a + b;
});
memoizedFn(2, 3); // 5
memoizedFn(2, 3); // 5
console.log(callCount); // 1
