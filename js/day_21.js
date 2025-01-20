/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function (arr, size) {
  // Step 1: Create an empty array to store the chunks
  var result = [];

  // Step 2: Loop through the array
  for (var i = 0; i < arr.length; i += size) {
    // Step 3: Slice the array into the chunk of the specific size
    var chunk = arr.slice(i, i + size);
    // Step 4: Push the chunk to the array
    result.push(chunk);
  }
  return result;
};

arr = [1, 2, 3, 4, 5];
size = 3;
console.log(chunk(arr, size)); // [[1], [2], [3], [4], [5]]
