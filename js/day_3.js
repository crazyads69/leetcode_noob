/**
 * @param {string} val
 * @return {Object}
 */
var expect = function (val) {
  return {
    toBe: function (expected) {
      if (val !== expected) {
        throw "Not Equal";
      }
      return true;
    },
    notToBe: function (expected) {
      if (val === expected) {
        throw "Equal";
      }
      return true;
    },
  };
};

console.log(expect(5).toBe(5)); // true
console.log(expect(5).notToBe(5));
