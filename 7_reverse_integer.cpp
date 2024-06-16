#include <limits.h>
using namespace std;
class Solution {
public:
  int reverse(int x) {
    // Initialize the result
    int result = 0;
    // Iterate until x is 0
    while (x != 0) {
      // Get the last digit of x
      int digit = x % 10;
      // Check if the result is greater than INT_MAX / 10
      if (result > INT_MAX / 10) {
        return 0;
      }
      // Check if the result is less than INT_MIN / 10
      if (result < INT_MIN / 10) {
        return 0;
      }
      // Multiply the result by 10 and add the digit
      result = result * 10 + digit;
      // Divide x by 10
      x /= 10;
    }
    // Return the result
    return result;
  }
};