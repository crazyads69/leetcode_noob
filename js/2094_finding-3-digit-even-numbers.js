/**
 * @param {number[]} digits
 * @return {number[]}
 */
// var findEvenNumbers = function (digits) {
//   let result = new Set();
//   for (let i = 0; i < digits.length; i++) {
//     for (let j = 0; j < digits.length; j++) {
//       for (let k = 0; k < digits.length; k++) {
//         if (
//           digits[i] !== 0 &&
//           digits[k] % 2 === 0 &&
//           i !== j &&
//           j !== k &&
//           i !== k
//         ) {
//           const value = digits[i] * 100 + digits[j] * 10 + digits[k];
//           if (100 <= value && value <= 999 && value % 2 === 0) {
//             result.add(value);
//           }
//         }
//       }
//     }
//   }
//   // Set to Array
//   result = Array.from(result);
//   // Sort the array
//   result.sort((a, b) => a - b);
//   return result;
// };

// Optimized solution
var findEvenNumbers = function (digits) {
  // Tạo mảng đếm tần suất xuất hiện của mỗi chữ số
  const count = new Array(10).fill(0);
  for (const digit of digits) {
    count[digit]++;
  }

  const result = [];

  // Duyệt qua tất cả các số có 3 chữ số
  for (let num = 100; num <= 998; num += 2) {
    const hundreds = Math.floor(num / 100);
    const tens = Math.floor((num % 100) / 10);
    const ones = num % 10;

    // Tạo một bản sao của mảng đếm
    const tempCount = [...count];

    // Kiểm tra xem có đủ chữ số để tạo số hiện tại không
    if (tempCount[hundreds] > 0) {
      tempCount[hundreds]--;
      if (tempCount[tens] > 0) {
        tempCount[tens]--;
        if (tempCount[ones] > 0) {
          result.push(num);
        }
      }
    }
  }

  return result;
};

digits = [2, 1, 3, 0];
console.log(findEvenNumbers(digits)); // [102,120,130,132,210,230,302,310,312,320]
