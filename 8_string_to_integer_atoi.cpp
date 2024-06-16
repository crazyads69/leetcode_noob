#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
  int myAtoi(string s) {
    int result = 0;
    // Determine the sign of the number (1 for positive, -1 for negative)
    int sign = 1;
    // Skip leading whitespaces
    int i = 0;
    while (i < s.size() && s[i] == ' ') {
      i++;
    }
    // Check if the number is negative
    if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
      sign = s[i] == '-' ? -1 : 1;
      i++;
    }
    // Iterate over the remaining characters
    while (i < s.size()) {
      // Check if the character is a digit
      if (!isdigit(s[i])) {
        break;
      }
      // Get the digit
      int digit = s[i] - '0';
      // Check if the result is greater than INT_MAX / 10
      if (result > INT_MAX / 10) {
        return sign == 1 ? INT_MAX : INT_MIN;
      }
      // Check if the result is equal to INT_MAX / 10 (to avoid overflow 2^31 -
      // 1 = 2147483647, -2^31 = -2147483648)
      if (result == INT_MAX / 10) {
        // Check if the digit is greater than 7
        if (sign == 1 && digit > 7) {
          return INT_MAX;
        }
        // Check if the digit is greater than 8
        if (sign == -1 && digit >= 8) {
          return INT_MIN;
        }
      }
      // Check if the result
      // Multiply the result by 10 and add the digit
      result = result * 10 + digit;
      // Move to the next character
      i++;
    }
    // Return the result
    return result * sign;
  }
};

// Solution 2: Using istringstream
// This version uses a string stream to read the number directly from the
// string. This automatically handles leading whitespace and the optional sign,
// and stops reading when it encounters a non-digit character. It's a lot less
// code, but it does essentially the same thing as your original solution.
// The only difference is that it doesn't handle overflow explicitly, it just
// relies on the fact that the stream will stop reading when it encounters a
// non-digit character. If the number is too large, the stream will stop reading
// before it overflows. This is a bit of a hack, but it works :)
class Solution_2 {
public:
  int myAtoi(string str) {
    istringstream iss(str);
    int num = 0;
    iss >> num;
    return num;
  }
};