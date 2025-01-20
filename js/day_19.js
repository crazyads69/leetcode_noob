/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function (functions) {
  // Create an array to store the results of each promise
  const results = [];

  // Create an array to store the promises
  const promises = functions.map((fn) => fn());

  // Create a promise that resolves when all promises have resolved
  return new Promise((resolve, reject) => {
    // Keep track of the number of promises that have resolved
    let count = 0;

    // Iterate through each promise
    promises.forEach((promise, i) => {
      // When the promise resolves, store the result
      promise
        .then((result) => {
          results[i] = result;
          count++;

          // If all promises have resolved, resolve the main promise
          if (count === promises.length) {
            resolve(results);
          }
        })
        // If any promise rejects, reject the main promise
        .catch(reject);
    });
  });
};

const promise = promiseAll([() => new Promise((res) => res(42))]);
promise.then(console.log); // [42]
