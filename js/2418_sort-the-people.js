/**
 * @param {string[]} names
 * @param {number[]} heights
 * @return {string[]}
 */
var sortPeople = function (names, heights) {
  // Create an array of objects with name and height properties
  const people = names.map((name, index) => ({ name, height: heights[index] }));
  // Sort the people array by height in descending order
  people.sort((a, b) => b.height - a.height);
  // Return the names of the people in the sorted order
  return people.map((person) => person.name);
};

names = ["Mary", "John", "Emma"];
heights = [180, 165, 170];
console.log(sortPeople(names, heights)); // ["Mary", "Emma", "John"]
