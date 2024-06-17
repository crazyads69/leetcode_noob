#include <string>
using namespace std;

// Solution 1: Convert to string and compare characters from the two ends
class Solution_1 {
public:
  bool isPalindrome(int x) {
    // Check if the number is negative
    if (x < 0) {
      return false;
    }
    // Convert the number to a string
    string s = to_string(x);
    // Iterate over the characters in the string
    for (int i = 0; i < s.size() / 2; i++) {
      // Check if the characters at the two ends of the string are different
      if (s[i] != s[s.size() - i - 1]) {
        return false;
      }
    }
    // Return true if the string is a palindrome
    return true;
  }
};

// Solution 2: Only get the half of the number and compare
class Solution_2 {
public:
  bool isPalindrome(int x) {
    // Special cases:
    // As discussed above, all negative numbers are not palindrome.
    // Also if the last digit of the number is 0, in order to be a palindrome,
    // the first digit of the number also needs to be 0.
    // Only 0 satisfy this property.
    if (x < 0 || (x % 10 == 0 && x != 0)) {
      return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber) {
      revertedNumber = revertedNumber * 10 + x % 10;
      x /= 10;
    }

    // When the length is an odd number, we can get rid of the middle digit by
    // revertedNumber/10 For example when the input is 12321, at the end of the
    // while loop we get x = 12, revertedNumber = 123, since the middle digit
    // doesn't matter in palindrome(it will always equal to itself), we can
    // simply get rid of it.
    return x == revertedNumber || x == revertedNumber / 10;
  }
};