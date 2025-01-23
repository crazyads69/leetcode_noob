/**
 * @param {string} s
 * @param {number[][]} pairs
 * @return {string}
 */
var smallestStringWithSwaps = function (s, pairs) {
  // Create a parent array to store the parent of each index
  let parent = new Array(s.length).fill(0).map((_, i) => i);

  // Create a map to store the indices of each group
  let groups = new Map();

  // Helper function to find the parent of an index
  const find = (x) => {
    if (parent[x] !== x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  };

  // Helper function to union two indices
  const union = (x, y) => {
    parent[find(x)] = find(y);
  };

  // Iterate through the pairs array
  for (let [x, y] of pairs) {
    union(x, y);
  }

  // Iterate through the parent array
  for (let i = 0; i < parent.length; i++) {
    let root = find(i);
    if (!groups.has(root)) {
      groups.set(root, []);
    }
    groups.get(root).push(i);
  }

  // Convert the string to an array
  s = s.split("");

  // Iterate through the groups map
  for (let group of groups.values()) {
    let chars = group.map((i) => s[i]);
    chars.sort();
    for (let i = 0; i < group.length; i++) {
      s[group[i]] = chars[i];
    }
  }

  return s.join("");
};
s = "dcab";
pairs = [
  [0, 3],
  [1, 2],
];

console.log(smallestStringWithSwaps(s, pairs)); // "bacd"
