/**
 * @param {string[]} words
 * @return {number}
 */
var longestStrChain = function (words) {
  // Sort the words array in ascending order of length
  words.sort((a, b) => a.length - b.length);

  // Create a map to store the length of the longest chain ending with each word
  let dp = new Map();

  // Initialize the result to 1
  let result = 1;

  // Iterate through the words array
  for (let word of words) {
    // Initialize the length of the longest chain ending with the current word to 1
    dp.set(word, 1);

    // Iterate through the characters of the current word
    for (let i = 0; i < word.length; i++) {
      // Create a new word by removing the i-th character from the current word
      let newWord = word.slice(0, i) + word.slice(i + 1);

      // If the new word is in the map, update the length of the longest chain ending with the current word
      if (dp.has(newWord)) {
        dp.set(word, Math.max(dp.get(word), dp.get(newWord) + 1));
      }
    }

    // Update the result
    result = Math.max(result, dp.get(word));
  }

  return result;
};

words = ["a", "b", "ba", "bca", "bda", "bdca"];
console.log(longestStrChain(words)); // 4
