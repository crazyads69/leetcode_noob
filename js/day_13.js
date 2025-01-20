/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
  // This is an async function that returns a promise that resolves after a certain amount of time
  return new Promise((resolve) => {
    setTimeout(resolve, millis);
  });
}

/**
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
