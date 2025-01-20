/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */

// Promise.race([fn(...args), timeoutPromise]): This ensures that whichever promise (fn(...args) or timeoutPromise) settles first will control the outcome.
// If fn completes in time, its result will be returned.
// If the timeout occurs first, "Time Limit Exceeded" will be thrown.

var timeLimit = function (fn, t) {
  return async function (...args) {
    // Create a timeout promise that will reject after t milliseconds
    const timeoutPromise = new Promise((_, reject) =>
      setTimeout(() => reject("Time Limit Exceeded"), t)
    );

    // Race the function execution with the timeout
    try {
      const result = await Promise.race([fn(...args), timeoutPromise]);
      return result; // Return the result if fn resolves within time limit
    } catch (err) {
      throw err; // Throw the error (either from timeout or fn)
    }
  };
};

const limited = timeLimit((t) => new Promise((res) => setTimeout(res, t)), 100);
limited(150).catch(console.log); // "Time Limit Exceeded" at t=100ms
